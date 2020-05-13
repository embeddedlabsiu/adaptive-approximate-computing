#include <stdio.h>

#include "snipmath.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <stdint.h>
#include "DynamicCGRAControl.h"

#define CGRABufferSize ( 1024 )
#define PEFileDescription ( "./CGRA_PE_Description.txt" )

int main( int argc, char* argv[] )
{
	// init variables
	size_t numberOfBits = 4;
	size_t startingLoop = 0;
	size_t endingLoop = 65535;
	size_t stepSize = 81;
	
	DynamicCGRAControl dynamic;

	initDynamicCGRAControl( &dynamic, "./ArithmeticPEsList.txt" );
	// printAllLists( &dynamic );

	printf("N, X, Actual, Zero_Error, First_Error, Third_Error\n");
	Results result;
	initResults( &result );
		
	for ( size_t x = startingLoop; x < endingLoop; x += stepSize )
	{
		dynamicControl( &dynamic, &result, x, numberOfBits );
		initResults( &result );
	}

	freeDynamicCGRAControl( &dynamic );
}