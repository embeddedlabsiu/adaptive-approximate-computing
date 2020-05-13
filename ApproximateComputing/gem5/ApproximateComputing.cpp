#include "ApproximateComputing.h"

#include <bitset>

//#include "ApproximateHardware/Adders/Adders.h"
//#include "ApproximateHardware/Multipliers/Multipliers.h"
// #include "Subtractor.h"

#define BITSET_SIZE 32 // Bad things will happen if this is not a 2^n number
typedef std::bitset< BITSET_SIZE > Bitset;
static void addOneBitAccurate( bool a, bool b, bool cin, bool* sum, bool* cou )
{
	int x = a + b + cin;
	if(x == 0)
	{
		*sum = 0;
		*cou = 0;
	}
	else if(x == 1)
	{
		*sum = 1;
		*cou = 0;
	}
	else if(x == 2)
	{
		*sum = 0;
		*cou = 1;
	}
	else
	{
		*sum = 1;
		*cou = 1;
	}
}

static void addOneBitZeroApprox( bool a, bool b, bool cin, bool* sum, bool* cou )
{
	*cou = 0;
	if(((a == 1) && (b == 1)) || ((cin == 1) && ((a == 1) || (b == 1))))
	{
		*cou = 1;
	}
	*sum = 1 - *cou;
}

static void addOneBitFirstApprox( bool a, bool b, bool cin, bool* sum, bool* cou )
{
	*cou = 0;
	if((b == 1) || ((a == 1) && (cin == 1)))
	{
		*cou = 1;
	}
	*sum = 1 - *cou;
}

static void addOneBitThirdApprox( bool a, bool b, bool cin, bool* sum, bool* cou )
{
	*cou = a;
	*sum = b;
}

static Bitset addMultiBitApprox( Bitset a, Bitset b, int approxBits, int method )
{
	Bitset out(0);
	bool temp = 0;
	bool a_val;
	bool b_val;
	bool out_val;
	int i;
	
	for(i = 0; i < approxBits; ++i)
	{
		a_val = a[i];
		b_val = b[i];
		out_val = out[i];
		if(method == 0)
		{
			addOneBitZeroApprox(a_val, b_val, temp, &out_val, &temp);
		}
		else if(method == 1)
		{
			addOneBitFirstApprox(a_val, b_val, temp, &out_val, &temp);
		}
		else if(method == 3)
		{
			addOneBitThirdApprox(a_val, b_val, temp, &out_val, &temp);
		}
		else
		{
			addOneBitAccurate(a_val, b_val, temp, &out_val, &temp);
		}
		out.set(i, out_val);
	}
	while(i < BITSET_SIZE)
	{
		a_val = a[i];
		b_val = b[i];
		out_val = out[i];
		addOneBitAccurate(a_val, b_val, temp, &out_val, &temp);
		out.set(i, out_val);
		++i;
	}
	return out;
}

static Bitset multiply_2x2( Bitset a, Bitset b, int start_a, int start_b, int approxBits, int multMethod, int addMethod )
{
	Bitset out(0);
	if((start_a+start_b) > (BITSET_SIZE-1))
	{
		return out;
	}
	out[start_a+start_b] = (a[start_a] && b[start_b]);
	out[start_a+start_b+1] = ((a[start_a] && b[start_b+1]) || (a[start_a+1] && b[start_b])) && (! (a[start_a] && a[start_a+1] && b[start_b] && b[start_b+1]));
	out[start_a+start_b+2] = ((a[start_a+1] && (! a[start_a]) && b[start_b+1]) || (a[start_a+1] && (! b[start_b]) && b[start_b+1]));
	out[start_a+start_b+3] = (a[start_a] && a[start_a+1] && b[start_b] && b[start_b+1]);
	if(multMethod == 0)
	{
		if((out[start_a+start_b] == 1) && (out[start_a+start_b+1] == 0) && (out[start_a+start_b+2] == 0) && (out[start_a+start_b+3] == 1))
		{
			out[start_a+start_b+1] = 1;
			out[start_a+start_b+2] = 1;
			out[start_a+start_b+3] = 0;
		}
	}
	else if(multMethod == 1)
	{
		if((out[start_a+start_b] == 1) && (out[start_a+start_b+1] == 0) && (out[start_a+start_b+2] == 0) && (out[start_a+start_b+3] == 0))
		{
			out[start_a+start_b] = 0;
		}
		else if((out[start_a+start_b] == 1) && (out[start_a+start_b+1] == 1) && (out[start_a+start_b+2] == 0) && (out[start_a+start_b+3] == 0))
		{
			out[start_a+start_b] = 0;
		}
	}
	return out;
}

static Bitset r_multiply( Bitset input_a, Bitset input_b, int start_a, int start_b, int size, int approxBits, int multMethod, int addMethod )
{
	Bitset f;
	Bitset o;
	Bitset m;
	Bitset l;
	
	if(size == 4)
	{	
		f = multiply_2x2(input_a, input_b, start_a+2, start_b+2, approxBits, multMethod, addMethod);
		o = multiply_2x2(input_a, input_b, start_a+2, start_b, approxBits, multMethod, addMethod);
		m = multiply_2x2(input_a, input_b, start_a, start_b+2, approxBits, multMethod, addMethod);
		l = multiply_2x2(input_a, input_b, start_a, start_b, approxBits, multMethod, addMethod);
	}
	else
	{
		f = r_multiply(input_a, input_b, start_a+(size/2), start_b+(size/2), size/2, approxBits, multMethod, addMethod);
		o = r_multiply(input_a, input_b, start_a+(size/2), start_b, size/2, approxBits, multMethod, addMethod);
		m = r_multiply(input_a, input_b, start_a, start_b+(size/2), size/2, approxBits, multMethod, addMethod);
		l = r_multiply(input_a, input_b, start_a, start_b, size/2, approxBits, multMethod, addMethod);
	}

	Bitset output = addMultiBitApprox(addMultiBitApprox(addMultiBitApprox(f, o, approxBits, addMethod), m, approxBits, addMethod), l, approxBits, addMethod);
	return output;
}

static void tbc2bin( Bitset &input)
{
	if(input[BITSET_SIZE-1] != 1)
	{
		return;
	}
	input.flip();
	for(int i = 0; i < BITSET_SIZE; ++i)
	{
		input[i] = (!input[i]);
		if(input[i] == 1)
		{
			break;
		}
	}
	return;
}

static int lpCLibSubtraction( unsigned int input_a, unsigned int input_b, int approxBits, int method )
{
	Bitset a(input_a);
	Bitset b(-1*input_b);
	bool neg = 0;

	if( input_b > input_a )
	{
		neg = 1;
	}

	Bitset out = addMultiBitApprox(a, b, approxBits, method);
	tbc2bin(out);
	if(neg)
	{
		return -1*out.to_ulong();
	}
	return out.to_ulong();
}

static int lpCLibAddition( unsigned int input_a, unsigned int input_b, int approxBits, int method )
{
	Bitset a(input_a);
	Bitset b(input_b);
	Bitset out = addMultiBitApprox( a, b, approxBits, method );
	return out.to_ulong();
}

static int lpCLibMultiplication( unsigned int input_a, unsigned int input_b, int approxBits, int multMethod, int addMethod )
{
	Bitset a(input_a);
	Bitset b(input_b);
	Bitset out = r_multiply(a, b, 0, 0, BITSET_SIZE, approxBits, multMethod, addMethod);
	return out.to_ulong();
}

namespace ApproximateComputing {

int HardwareDescription::addition( unsigned int input_a, unsigned int input_b, int approxBits, AdderTypes::Enum adderTypes, LPCLibraryMethod::Enum lpcApproximationMethod )
{
	if ( lpcApproximationMethod == -1 )
	{
		return input_a + input_b;
	}
	
	switch ( adderTypes )
	{
	case AdderTypes::Exact:
		//return Adders::adder32Exact( input_a, input_b );
		break;

	case AdderTypes::ApproximateFiftyPercentPower:
		//return Adders::adder32FiftyPercentPower( input_a, input_b );
		break;

	case AdderTypes::lpCLibMethod:
		// printf("!!!!!%i %i %i %i\n", input_a, input_b, approxBits, lpcApproximationMethod );
		return lpCLibAddition( input_a, input_b, approxBits, lpcApproximationMethod );
		break;
	
	case AdderTypes::StandardAddition:
		return input_a + input_b;
		break;
	}
	
	return -1;
}

int HardwareDescription::subtraction( unsigned int input_a, unsigned int input_b, int approxBits, SubtractorTypes::Enum subtractorTypes, LPCLibraryMethod::Enum lpcApproximationMethod )
{
	if ( lpcApproximationMethod == -1 )
	{
		return input_a - input_b;
	}
	switch ( subtractorTypes )
	{	
	case SubtractorTypes::StandardSubtractor:
		return input_a - input_b;
		break;

	case SubtractorTypes::lpCLibMethod:
		return lpCLibSubtraction( input_a, input_b, approxBits, lpcApproximationMethod );
		break;
	}
	return -1;
}

int HardwareDescription::multiplication( unsigned int input_a, unsigned int input_b, int approxBits, int multMethod, int additionMethod, MultiplierTypes::Enum multiplierTypes )
{
	switch ( multiplierTypes )
	{	
	case MultiplierTypes::StandardMultiplier:
		return input_a * input_b;
		break;

	case MultiplierTypes::Exact:
		//return Multipliers::multiplier32_64Exact( input_a, input_b );
		break;

	case MultiplierTypes::lpCLibMethod:
		return lpCLibMultiplication( input_a, input_b, approxBits, multMethod, additionMethod );
		break;

	case MultiplierTypes::ApproximateFirstMlab:
		//return Multipliers::multiplier32_32ApproximateFirstMLab( input_a, input_b );
		break;	
	}

	return -1;
}
}
