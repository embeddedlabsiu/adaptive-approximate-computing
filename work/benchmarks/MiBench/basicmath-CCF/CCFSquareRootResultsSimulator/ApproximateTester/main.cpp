#include <stdio.h>

#include "snipmath.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <cmath>

#include <stdint.h>

#define CGRABufferSize ( 1024 )
#define PEFileDescription ( "./CGRA_PE_Description.txt" )

// #define PRINTALL 
enum UsageArguments
{
	NumberOfBits	= 'n',
	StartingLoop	= 't',
	EndingLoop		= 'e',
	// LCPMethod		= 'l',
	StepSize		= 's'	
} ;

struct Pair
{
	double value;
	double error;

	Pair()
	: value( 0 )
	, error( 0 )
	{}
};
struct Results
{
	Pair zeroApproximation;
	Pair firstApproximation;
	Pair thirdApproximation;

	void print()
	{
		#ifdef PRINTALL
		printf("%lf, %lf, %lf, %lf, %lf, %lf"
		, zeroApproximation.value
		, zeroApproximation.error
		, firstApproximation.value
		, firstApproximation.error
		, thirdApproximation.value
		, thirdApproximation.error );
		#else
		printf("%lf, %lf, %lf"
		, zeroApproximation.error
		, firstApproximation.error
		, thirdApproximation.error );
		#endif
	}
};

void calculate( Pair& pair, int squareRoot, int numberOfBits, int approxMethod, double actual )
{
	int_sqrt q;
	double approx;
	double percentError;
	CGRA_usqrt( squareRoot, &q, numberOfBits, approxMethod );
	
	approx = (double)(q.sqrt)/65536.0;
	percentError = std::abs( ( (double)(abs(actual-approx)) / (double)actual ) ) * 100;

	if ( percentError < 0 )
	{
		percentError *= -1;
	}

	if ( percentError > 100 )
	{
		percentError = 100.0;
	}

	pair.value = approx;
	pair.error = percentError;
}

int main( int argc, char* argv[] )
{
	// init variables
	int opt;
	size_t numberOfBits = 0;
	size_t startingLoop = 0;
	size_t endingLoop = 0;
	size_t stepSize = 0;
	double actual;

	// setup the long options0
	static struct option longOptions[] =
	{
		{ "NumberOfBits",	required_argument,	0, 'n' },
		{ "StartingLoop",required_argument,	0, 't' },
		{ "EndingLoop",	required_argument,	0, 'e' },
		// { "LCPMethod",	required_argument,	0, 'l' },
		{ "StepSize",	required_argument,	0, 's' },
		{ 0,					0,					0,	0  }
	};

	// parse the user's arguements
	while ( ( opt = getopt_long( argc, argv, "n:e:s:t:", longOptions, NULL ) ) != -1 )
	{
		switch ( opt )
		{
		case NumberOfBits:
			numberOfBits = atoi( optarg );
			break;

		case EndingLoop:
			endingLoop = atoi( optarg );
			break;

		case StartingLoop:
			startingLoop = atoi( optarg );
			break;

		case StepSize:
			stepSize = atoi( optarg );
			break;

		default: /* '?' */
			printf( "UNKOWN ARG\n");
			exit( EXIT_FAILURE );
		}
	}

	printf("N, X, Actual, Zero_Error, First_Error, Third_Error\n");
	Results result;
		
	for ( size_t x = startingLoop; x < endingLoop; x += stepSize )
	{
		actual = std::sqrt( x );
		calculate( result.zeroApproximation, x, numberOfBits, 0, actual );
		calculate( result.firstApproximation, x, numberOfBits, 1, actual );
		calculate( result.thirdApproximation, x, numberOfBits, 3, actual );
		printf("%lu, %lu, %lf, ", numberOfBits, x, actual ); 
		// printf("---") ;
		result.print();
		printf("\n");      
	}
}