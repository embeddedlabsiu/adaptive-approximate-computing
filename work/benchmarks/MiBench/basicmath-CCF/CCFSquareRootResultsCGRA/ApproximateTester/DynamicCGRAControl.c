#include "DynamicCGRAControl.h"

#include <stdio.h>
#include "CGRADefinitions.h"

#include "snipmath.h"

#include <math.h>
#include <unistd.h>

void initDynamicCGRAControl( DynamicCGRAControl* dynamicCGRAControl, const char* fileToOpen )
{	
	initCGRA( dynamicCGRAControl->cgra );

	// parse the file and file the CGRA
	dynamicCGRAControl->cgraSize = parseArithmeticPEsListFile( fileToOpen, dynamicCGRAControl->cgra );

	// Example of setting a PE manually
	// dynamicCGRAControl->cgra[ 14 ].adder.isUsed = true;
	// dynamicCGRAControl->cgra[ 14 ].adder.approximationType = 3;
	// dynamicCGRAControl->cgra[ 14 ].adder.approximatedNumberOfBits = 16;
	// createPEDescriptionFile( "./CGRA_PE_Description.txt", dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );

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

void setLPCMethod( LinkedList* list, int lpcMethod, int numberOfBits )
{
	Node* node;
	node = list->head;
	ArithmeticLogicUnitNode* data;
	while ( node != NULL )
	{
		data = (ArithmeticLogicUnitNode*)node->data;
		data->desc->approximationType = AdderTypesLpCLibMethod;
		data->desc->approximatedNumberOfBits = numberOfBits;
		data->desc->lpcApproximationMethod = lpcMethod;
		
		node = node->next;
	}	
}

void calculate( DynamicCGRAControl* dynamicCGRAControl, Pair* pair, int squareRoot, int numberOfBits, int approxMethod, double actual )
{
	struct int_sqrt q;
	double approx;
	double percentError;
	LinkedList* list = dynamicCGRAControl->adderList;
	unsigned counter = 0;
	unsigned i;
	#define MAXLOOPER ( 1250 )

	setLPCMethod( list, approxMethod, numberOfBits );
	createPEDescriptionFile( "./CGRA_PE_Description.txt", dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );

	char* dummy;
	
	FILE* file;
	
	for (i = 0; i < MAXLOOPER; i++)
	{
		file = openFile( "dummy.txt", "w" );
		fprintf( file, "Delay\n" );
		fclose( file );
	}
	
	

	// sleep( 5 );

	CGRA_usqrt( squareRoot, &q );

	approx = (double)(q.sqrt)/65536.0;
	percentError = fabs( ( (double)(fabs(actual-approx)) / (double)actual ) ) * 100;

	if ( percentError < 0 )
	{
		percentError *= -1;
	}

	if ( percentError > 100 )
	{
		percentError = 100.0;
	}

	pair->value = approx;
	pair->error = percentError;

	// printf("%lf, ", percentError );
}

void initPair( Pair* pair )
{
	pair->error = 0;
	pair->value = 0;
}

void initResults( Results* results )
{
	initPair( &results->zeroApproximation );
	initPair( &results->firstApproximation );
	initPair( &results->thirdApproximation );
}

void printResults( Results* results )
{
	printf("%lf, %lf, %lf"
	, results->zeroApproximation.error
	, results->firstApproximation.error
	, results->thirdApproximation.error );
}

void dynamicControl( DynamicCGRAControl* dynamicCGRAControl, Results* result, size_t x, int numberOfBits )
{
	double actual = sqrt( x );

	printf("--%i, %lu, %lf, ", numberOfBits, x, actual ); 
	
	calculate( dynamicCGRAControl, &result->zeroApproximation, x, numberOfBits, 0, actual );
	calculate( dynamicCGRAControl, &result->firstApproximation, x, numberOfBits, 1, actual );
	calculate( dynamicCGRAControl, &result->thirdApproximation, x, numberOfBits, 3, actual );
	
	// printf("---") ;
	printResults( result );
	printf("\n");      	
}



