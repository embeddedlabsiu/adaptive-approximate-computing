#include <stdio.h>
#include "FileWriter.h"
#include "snipmath.h"
#include "ApproximateBitsEquals4LookupTable.h"
#include "ApproximateBitsEquals8LookupTable.h"
#include "ApproximateBitsEquals12LookupTable.h" 
#include "ApproximateBitsEquals16LookupTable.h"

// #include <fcntl.h>

#define FILENAME ( "./CGRA_PE_Description.txt" )

int fd;
struct flock lock = 
{
    .l_whence = SEEK_SET,
    .l_start = 0,
    .l_len = 0,
};

static int getApproximateMethod( unsigned long value, int approximateBits, int desiredTolerance )
{
	int approxMethod = -1;
	// value -=1;
	switch ( approximateBits )
	{
		case 4:
			approxMethod = lookupTable4[ value ][0];
			if ( lookupTable4[ value ][ 1 ] >= desiredTolerance )
			{
				approxMethod = -1;
			}
			break;

		case 8:
			approxMethod = lookupTable8[ value ][0];
			if ( lookupTable8[ value ][ 1 ] >= desiredTolerance )
			{
				approxMethod = -1;
			}
			break;

		case 12:
			approxMethod = lookupTable12[ value ][0];
			if ( lookupTable12[ value ][ 1 ] >= desiredTolerance )
			{
				approxMethod = -1;
			}
			break;

		case 16:
			approxMethod = lookupTable16[ value ][0];
			
			if ( lookupTable16[ value ][ 1 ] >= desiredTolerance )
			{
				approxMethod = -1;
			}
			break;

		default:
			approxMethod = -1;
			break;
	}
	
	// printf("method %i tolerance %i\n", approxMethod, desiredTolerance );
	return approxMethod;
}

inline float distance(int x1, int y1, int x2, int y2, int desiredTolerance, size_t counter, int approximateBits, int* lpcMethod ) 
{ 
    // struct int_sqrt one;
    // int method = getApproximateMethod( counter, approximateBits, desiredTolerance );
    // *lpcMethod = method;
    // // createPEDescriptionFile( FILENAME, approximateBits, method, &fd, &lock );
    
    // unsigned long deltaXSquared = ( x2 - x1 ) * ( x2 - x1 );
    // unsigned long deltaYSquared = ( y2 - y1 ) * ( y2 - y1 );

    // printf("%i ", deltaXSquared + deltaYSquared );

    // CGRA_usqrt( deltaXSquared + deltaYSquared, &one );
    // return (float)((one.sqrt)/65536.0);
} 

double euclidianDistanceExact( int x1, int y1, int x2, int y2 ) 
{ 
    unsigned long deltaXSquared = ( x2 - x1 ) * ( x2 - x1 );
    unsigned long deltaYSquared = ( y2 - y1 ) * ( y2 - y1 );
	return sqrt( (double)( deltaXSquared + deltaYSquared ) );
} 

int main( int argc, char* argv[] )  
{
    size_t counter = 0;
    size_t startingLoop = 1;
	size_t endingLoop = 25;
	size_t stepSize = 1;
    size_t numberOfBits = 8;
    int tolerance = 80;
    double actual;
	double approx;
	double percentError;
    struct int_sqrt one;
    int lpcMethod;
    unsigned long x1, x2, y1, y2;
    fd = open( FILENAME, O_RDWR | O_CREAT, 0666 );

    for ( size_t x = startingLoop; x < endingLoop; x += stepSize )
	{
		for ( size_t y = endingLoop; y > 0; y -= stepSize )
		{
            x1 = x;
            y1 = y;

            x2 = x % 2;
            y2 = y % 2;

			// euclidianDistanceExact( int x1, int y1, int x2, int y2 ) 
            // actual = euclidianDistanceExact( x, y, x % 2, y % 2 );
            actual = euclidianDistanceExact( x1, y1, x2, y2 );

            // struct int_sqrt one;
            // int method = getApproximateMethod( counter, approximateBits, desiredTolerance );
            // *lpcMethod = method;
            // // createPEDescriptionFile( FILENAME, approximateBits, method, &fd, &lock );
    
            unsigned long deltaXSquared = ( x - x1 ) * ( x2 - x1 );
            unsigned long deltaYSquared = ( y2 - y1 ) * ( y2 - y1 );

    // printf("%i ", deltaXSquared + deltaYSquared );

            CGRA_usqrt( deltaXSquared + deltaYSquared, &one );

            approx = (float)((one.sqrt)/65536.0);
            
			// approx = distance( x, y, x % 2, y % 2, tolerance, counter, numberOfBits, &lpcMethod );
			// metrics.calculate( approxMethod );
			if ( actual == 0 )
			{
				percentError = 0;	
			}
			else
			{
				percentError = fabs( ( (double)(fabs(actual-approx)) / (double)actual ) ) * 100;
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
			printf("%i, %lf\n", lpcMethod, percentError ); 
            // printf("%lu,%i,%lf,%lf,%lf\n", counter, lpcMethod, actual, approx, percentError ); 
            // printf("%lu, %lu,%lu,%lu,%lu,%lu,%i,%lf,%lf,%lf\n", counter, numberOfBits, x, y, x % 2, y % 2, lpcMethod, actual, approx, percentError ); 
		}
	}

    return 0;
}
