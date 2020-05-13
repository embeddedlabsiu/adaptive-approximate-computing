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
	StartingLoop	= 'b',
	EndingLoop		= 'e',
	StepSize		= 's',
	Tolerance		= 't',	
} ;


int euclidianDistance( int x1, int y1, int x2, int y2, int numberOfBits, int tolerance, double* result, unsigned counter ) 
{ 
    struct int_sqrt one;
    int approximationMethod;
    unsigned long deltaXSquared = ( x2 - x1 ) * ( x2 - x1 );
    unsigned long deltaYSquared = ( y2 - y1 ) * ( y2 - y1 );

    approximationMethod = CGRA_usqrt( deltaXSquared + deltaYSquared, &one, numberOfBits, tolerance, counter );
	*result = (float)((one.sqrt)/65536.0);
    return approximationMethod;
} 

double euclidianDistanceExact( int x1, int y1, int x2, int y2 ) 
{ 
    unsigned long deltaXSquared = ( x2 - x1 ) * ( x2 - x1 );
    unsigned long deltaYSquared = ( y2 - y1 ) * ( y2 - y1 );
	return std::sqrt( double( deltaXSquared + deltaYSquared ) );
} 

int main( int argc, char* argv[] )
{
	// init variables
	int opt;
	size_t numberOfBits = 0;
	size_t startingLoop = 0;
	size_t endingLoop = 25;
	size_t stepSize = 1;
	int tolerance = -1;
	int approxMethod;
	double actual;
	double approx;
	double percentError;
	size_t counter = 0;

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

		default: 
			printf( "UNKOWN ARG\n");
			exit( EXIT_FAILURE );
		}
	}

	usleep( 5000 );
	printf("Number,N,X1,Y1,X2,Y2,Approx_Method,Actual,Approx,Percent_Error\n");
	
	// printf("start %lu, end %lu, step %lu\n", startingLoop, endingLoop, stepSize );
	for ( size_t x = startingLoop; x < endingLoop; x += stepSize )
	{
		for ( size_t y = endingLoop; y > 0; y -= stepSize )
		{
			// euclidianDistanceExact( int x1, int y1, int x2, int y2 ) 
			actual = euclidianDistanceExact( x, y, x % 2, y % 2 );
			approxMethod = euclidianDistance( x, y, x % 2, y % 2, numberOfBits, tolerance, &approx, counter );
			// metrics.calculate( approxMethod );
			if ( actual == 0 )
			{
				percentError = 0;	
			}
			else
			{
				percentError = std::abs( ( (double)(abs(actual-approx)) / (double)actual ) ) * 100;
			}
			
			if ( percentError < 0 )
			{
				percentError *= -1;
			}

			if ( percentError > 100 )
			{
				percentError = 100.0;
			}

			++counter;
			printf("%lu, %lu,%lu,%lu,%lu,%lu,%i,%lf,%lf,%lf\n", counter, numberOfBits, x, y, x % 2, y % 2, approxMethod, actual, approx, percentError ); 
		}
	}
}

