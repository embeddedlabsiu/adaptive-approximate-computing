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
		printf("%lf, %lf, %lf"
		, zeroApproximation.error
		, firstApproximation.error
		, thirdApproximation.error );
	}
};

float euclidianDistance( int x1, int y1, int x2, int y2, int numberOfBits, int approxMethod ) 
{ 
    struct int_sqrt one;
    
    unsigned long deltaXSquared = ( x2 - x1 ) * ( x2 - x1 );
    unsigned long deltaYSquared = ( y2 - y1 ) * ( y2 - y1 );
	if ( deltaXSquared + deltaYSquared == 0 )
	{
		// return 0.0;
	}
	// printf("input %lu\n", deltaXSquared + deltaYSquared );
    CGRA_usqrt( deltaXSquared + deltaYSquared, &one, numberOfBits, approxMethod );
    return (float)((one.sqrt)/65536.0);
} 

double euclidianDistanceExact( int x1, int y1, int x2, int y2 ) 
{ 
    unsigned long deltaXSquared = ( x2 - x1 ) * ( x2 - x1 );
    unsigned long deltaYSquared = ( y2 - y1 ) * ( y2 - y1 );
	return std::sqrt( double( deltaXSquared + deltaYSquared ) );
} 

void calculate( Pair& pair, int x1, int y1, int x2, int y2, int numberOfBits, int approxMethod, double actual )
{
	if ( actual == 0 )
	{
		pair.value = 0;
		pair.error = 0;
		return;
	}
	double approx;
	double percentError;
	approx = euclidianDistance( x1, y1, x2, y2, numberOfBits, approxMethod );
	
	
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

	printf("N,X1,Y1,X2,Y2,Actual,Zero_Error,First_Error,Third_Error\n");
	Results result;
	// printf("start %lu, end %lu, step %lu\n", startingLoop, endingLoop, stepSize );
	for ( size_t x = startingLoop; x < endingLoop; x += stepSize )
	{
		for ( size_t y = endingLoop; y > 0; y -= stepSize )
		{
			actual = euclidianDistanceExact( x, y, x % 2, y % 2 );
			calculate( result.zeroApproximation, x, y, x % 2, y % 2, numberOfBits, 0, actual );
			calculate( result.firstApproximation, x, y, x % 2, y % 2, numberOfBits, 1, actual );
			calculate( result.thirdApproximation, x, y, x % 2, y % 2, numberOfBits, 3, actual );
			printf("%lu,%lu,%lu,%lu,%lu,%lf,", numberOfBits, x, y, x % 2, y % 2, actual ); 
			// printf("---") ;
			result.print();
			printf("\n");      
		}
	}
}
