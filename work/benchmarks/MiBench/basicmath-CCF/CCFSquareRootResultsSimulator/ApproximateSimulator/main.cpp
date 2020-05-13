#include <stdio.h>

#include "snipmath.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <cmath>

#include <stdint.h>

#define CGRABufferSize ( 1024 )

// #define PRINTALL 
enum UsageArguments
{
	NumberOfBits	= 'n',
	StartingLoop	= 'b',
	EndingLoop		= 'e',
	StepSize		= 's',
	Tolerance		= 't',	
} ;

struct UsageMetrics
{
	unsigned exact;
	unsigned zero;
	unsigned first;
	unsigned third;

	UsageMetrics()
	: exact( 0 )
	, zero( 0 )
	, first( 0 )
	, third( 0 )
	{}

	void calculate( int approximateMethod )
	{
		switch ( approximateMethod )
		{
			case -1:
				++exact;
				break;

			case 0:
				++zero;
				break;

			case 1:
				++first;
				break;

			case 3:
				++third;
				break;

			default:
				break;
		}
	}

	void printValues() const
	{
		printf( "%u, %u, %u, %u", exact, zero, first, third );
	}

	void printHeader( bool printNewLine) const
	{
		if ( printNewLine )
		{
			printf( "Exact, Zero, First, Third\n" );
			return;
		}
		printf( "Exact, Zero, First, Third" );
	}
};

int main( int argc, char* argv[] )
{
	// init variables
	int opt;
	size_t numberOfBits = 0;
	size_t startingLoop = 0;
	size_t endingLoop = 0;
	size_t stepSize = 0;
	int tolerance = -1;
	double actual;
	double approx;
	double percentError;
	UsageMetrics metrics;

	// setup the long options0
	static struct option longOptions[] =
	{
		{ "NumberOfBits",	required_argument,	0, 'n' },
		{ "StartingLoop",required_argument,	0, 'b' },
		{ "EndingLoop",	required_argument,	0, 'e' },
		{ "StepSize",	required_argument,	0, 's' },
		{ "Tolerance",	optional_argument,	0, 't' },
		{ 0,					0,					0,	0  }
	};

	// parse the user's arguements
	while ( ( opt = getopt_long( argc, argv, "n:b:e:s:t:", longOptions, NULL ) ) != -1 )
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

		case Tolerance:
			tolerance = atoi( optarg );
			break;

		default: /* '?' */
			printf( "UNKOWN ARG\n");
			exit( EXIT_FAILURE );
		}
	}
	printf("tolerance %i\n", tolerance);
	printf("N, X, Approx Method, Actual, Approx, Percent_Error\n");
	int_sqrt q;
	int approxMethod;
	for ( size_t x = startingLoop; x < endingLoop; x += stepSize )
	{
		actual = std::sqrt( x );
		approxMethod = CGRA_usqrt( x, &q, numberOfBits, tolerance );
		metrics.calculate( approxMethod );
	
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

		printf("%lu, %lu, %i, %lf, %lf, %lf\n", numberOfBits, x, approxMethod, actual, approx, percentError ); 
	}

	// metrics.printHeader( true );

	// metrics.printValues();
	// printf("\n");
}
