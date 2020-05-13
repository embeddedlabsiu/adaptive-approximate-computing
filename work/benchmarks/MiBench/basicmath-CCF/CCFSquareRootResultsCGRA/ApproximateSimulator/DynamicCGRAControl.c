#include "DynamicCGRAControl.h"

#include <stdio.h>
#include "ApproximateBitsEquals4LookupTable.h"
#include "ApproximateBitsEquals8LookupTable.h"
#include "ApproximateBitsEquals12LookupTable.h" 
#include "ApproximateBitsEquals16LookupTable.h"
#include "CGRADefinitions.h"

#include "snipmath.h"
#include <unistd.h>
#include <math.h>

int getApproximateMethod( unsigned long value, int approximateBits, int desiredTolerance )
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

void initDynamicCGRAControl( DynamicCGRAControl* dynamicCGRAControl, const char* fileToOpen )
{	
	// int bufferPosition = 0;
	// char buffer[ 2048 ] = {'\0'};
	
	initCGRA( dynamicCGRAControl->cgra );

	// parse the file and file the CGRA
	dynamicCGRAControl->cgraSize = parseArithmeticPEsListFile( fileToOpen, dynamicCGRAControl->cgra );

	// This can be removed if printing the results is not desired
	
	// printCGRA( dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize, buffer, &bufferPosition );
	// printf("%s", buffer );

	// printCGRA( dynamicCGRAControl->cgra, 25, &buffer, &bufferPosition );
	// printf("%s", buffer );
	// fill each list
	// @todo reduce the complexity. This can be done in one pass of the CGRA
	dynamicCGRAControl->adderList = getAdderList( dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );
	dynamicCGRAControl->multiplierList = getMultiplierList( dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );
	dynamicCGRAControl->subtractorList = getSubtractorList( dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );
}

void freeDynamicCGRAControl( DynamicCGRAControl* dynamicCGRAControl )
{
	// frees the memory of each list
	freeArithmeticLogicUnitList( dynamicCGRAControl->adderList );
	freeArithmeticLogicUnitList( dynamicCGRAControl->multiplierList );
	freeArithmeticLogicUnitList( dynamicCGRAControl->subtractorList );
}

void printAllLists( DynamicCGRAControl* dynamicCGRAControl )
{
	// wrapper for printing all of the lists
	printf("Add:\n");
	printList( dynamicCGRAControl->adderList );
	printf("Mult:\n");
	printList( dynamicCGRAControl->multiplierList );
	printf("Sub:\n");
	printList( dynamicCGRAControl->subtractorList );
}

void dynamicControl( DynamicCGRAControl* dynamicCGRAControl )
{
	//#define LOOPMAX ( 882 )
	// #define LOOPMAX ( 200 )

	// #define ErrorRate ( 2 )
	// // int     solutions;
	// unsigned long int i = 0;
	// // unsigned long l = 0x3fed0169L;
	// struct int_sqrt q;
	// struct int_sqrt w;
	// // long n = 0;
	// // // at the end of this function, call createPEDescriptionFile if the PE's approximation settings change
	// // static unsigned counter = 0;
	// LinkedList* list;
	// Node* node;
	// ArithmeticLogicUnitNode* data;
	// int bufferPosition = 0;
	// char buffer[ 2048 ] = {'\0'};
	// int lastLpcApproximationMethod = -1;
	// int currentLpcApproximationMethod = -1;

	// bool shouldCreateNewFile = false;

	// FILE *fp;
	// fp = fopen("test.csv", "w");
	// fprintf(fp, "Operation,Result,Actual,Error\n");
	
	// for (i = 1; i <= LOOPMAX; ++i)
	// {
	// 	list = dynamicCGRAControl->subtractorList;
	// 	node = list->head;

	// 	while ( node != NULL )
	// 	{
	// 		data = (ArithmeticLogicUnitNode*)node->data;
	// 		data->desc->approximationType = SubtractorTypesLpCLibMethod ;
	// 		data->desc->approximatedNumberOfBits = 4;
	// 		// data->desc->lpcApproximationMethod = getApproximateMethod( i, 4, ErrorRate );
	// 		currentLpcApproximationMethod = getApproximateMethod( i, 4, ErrorRate );
	// 		if ( lastLpcApproximationMethod != currentLpcApproximationMethod )
	// 		{
	// 			// this only works with one item in the list!
	// 			data->desc->lpcApproximationMethod = currentLpcApproximationMethod;
	// 			lastLpcApproximationMethod = currentLpcApproximationMethod;
	// 			shouldCreateNewFile = true;
	// 		}
			
	// 		node = node->next;
	// 	}


	// 	// createPEDescriptionFile( "./CGRA_PE_Description.txt", dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );	
	// 	if ( shouldCreateNewFile == true )
	// 	{
	// 		// printf("CREATED FILE\n");
	// 		shouldCreateNewFile = false;
	// 		createPEDescriptionFile( "./CGRA_PE_Description.txt", dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );	
	// 	}
		
		
	// 	//printPEDescriptionFile("./CGRA_PE_Description.txt" );

	// 	usleep( 1000000 );
	// 	usqrt(i, &w);
	// 	CGRA_usqrt(i, &q);
	// 	// remainder differs on some machines
	
	// 	double result = (((double)(q.sqrt))/65536.0);
	// 	double actual = (((double)(w.sqrt))/65536.0);

	// 	// printf("val %lu approx %i\n", i, currentLpcApproximationMethod );

		
	// 	fprintf(fp, "sqrt(%d),%lf,%lf,%lf\n",i,result,actual, fabs( result-actual) / actual );	
	// }

	// fclose(fp);
}
