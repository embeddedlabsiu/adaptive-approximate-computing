#include "DynamicCGRAControl.h"

#include <stdio.h>

/**
 * This executable IS NOT NECESSARY for the dynamic control of Approximate Computing's CGRA. This
 * is just a test bed for the DynamicCGRAControl, so it can be tested outside of the GEM5 framework.
 */
// int main( int argc, char* argv[] ) 
// {
// 	size_t peFinder = 10;
// 	DynamicCGRAControl dynamic;
// 	initDynamicCGRAControl( &dynamic, argv[ 1 ] );

// 	printAllLists( &dynamic );	

// 	LogicUnitDescription* logicUnitDescription = findPEByNumber( dynamic.subtractorList, peFinder );

// 	if ( logicUnitDescription )
// 	{
// 		printf("%i\n", logicUnitDescription->approximationMethod );
// 	}
// 	else
// 	{
// 		printf("NOT FOUND!!\n");
// 	}

// 	freeDynamicCGRAControl( &dynamic );
// }