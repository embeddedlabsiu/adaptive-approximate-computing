#include "DynamicCGRAControl.h"

#include <stdio.h>

#include "CGRADefinitions.h"
void initDynamicCGRAControl( DynamicCGRAControl* dynamicCGRAControl, const char* fileToOpen )
{	
	// parse the file and file the CGRA
	dynamicCGRAControl->cgraSize = parseArithmeticPEsListFile( fileToOpen, dynamicCGRAControl->cgra );

	// This can be removed if printing the results is not desired
	int bufferPosition = 0;
	char buffer[ 2048 ];

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

void dynamicControl( DynamicCGRAControl* dynamicCGRAControl, int error )
{
	// at the end of this function, call createPEDescriptionFile if the PE's approximation settings change
	static unsigned counter = 0;
	LinkedList* list;
	Node* node;
	ArithmeticLogicUnitNode* data;
	
	int bufferPosition = 0;
	char buffer[ 2048 ] = {'\0'};

	// printf("First:\n");
	// printCGRA( dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize, buffer, &bufferPosition );
	// printf( "%u\n", error );

	list = dynamicCGRAControl->adderList;
	node = list->head;
	// if ( counter % 2 == 0 )
	{
	// 	printf("10!!!!!!\n");
			
		// printf("even\n");
		while ( node != NULL )
		{
			data = (ArithmeticLogicUnitNode*)node->data;
			data->desc->approximationType = AdderTypesLpCLibMethod;
			data->desc->approximatedNumberOfBits = 4;
			data->desc->lpcApproximationMethod = LPCLibraryMethodZeroApproximation;
			// printf( "%i\n", data->desc->lpcApproximationMethod );
			node = node->next;
		}
	}
	// else
	// {
	// 	// list = dynamicCGRAControl->subtractorList;
	// 	// node = list->head;	
	// 	// printf("odd\n");
	// 	while ( node != NULL )
	// 	{
	// 		data = (ArithmeticLogicUnitNode*)node->data;
	// 		data->desc->approximationType = AdderTypesLpCLibMethod;
	// 		data->desc->approximatedNumberOfBits = 2;
	// 		data->desc->lpcApproximationMethod = LPCLibraryMethodThirdApproximation;
	// 		// printf( "%i\n", data->desc->lpcApproximationMethod );
	// 		node = node->next;
	// 	}
	// }
	++counter;
	// printf("%lu\n", counter );
	// 	list = dynamicCGRAControl->subtractorList;
	// 	node = list->head;	
	// 	while ( node != NULL )
	// 	{
	// 		data = (ArithmeticLogicUnitNode*)node->data;
	// 		data->desc->approximationType = 0;
	// 		data->desc->approximatedNumberOfBits = 0;
	// 		// printf( "%i\n", data->desc->approximationType );
	// 		node = node->next;
	// 	}
	// }
	// else if ( counter == 100 )
	// {
	// 	printf("100!!!!!!\n");
	// 	list = dynamicCGRAControl->adderList;
	// 	node = list->head;	
	// 	while ( node != NULL )
	// 	{
	// 		data = (ArithmeticLogicUnitNode*)node->data;
	// 		data->desc->approximationType = 0;
	// 		data->desc->approximatedNumberOfBits = 0;
	// 		// printf( "%i\n", data->desc->approximationType );
	// 		node = node->next;
	// 	}

	// 	list = dynamicCGRAControl->subtractorList;
	// 	node = list->head;	
	// 	while ( node != NULL )
	// 	{
	// 		data = (ArithmeticLogicUnitNode*)node->data;
	// 		data->desc->approximationType = -1;
	// 		data->desc->approximatedNumberOfBits = 0;
	// 		// printf( "%i\n", data->desc->approximationType );
	// 		node = node->next;
	// 	}
	// }
	// else if ( counter == 1000 )
	// {
	// 	printf("1000!!!!!!\n");
	// 	list = dynamicCGRAControl->adderList;
	// 	node = list->head;	
	// 	while ( node != NULL )
	// 	{
	// 		data = (ArithmeticLogicUnitNode*)node->data;
	// 		data->desc->approximationType = 0;
	// 		data->desc->approximatedNumberOfBits = 0;
	// 		// printf( "%i\n", data->desc->approximationType );
	// 		node = node->next;
	// 	}

	// 	list = dynamicCGRAControl->subtractorList;
	// 	node = list->head;	
	// 	while ( node != NULL )
	// 	{
	// 		data = (ArithmeticLogicUnitNode*)node->data;
	// 		data->desc->approximationType = 0;
	// 		data->desc->approximatedNumberOfBits = 0;
	// 		// printf( "%i\n", data->desc->approximationType );
	// 		node = node->next;
	// 	}
	// }

	bufferPosition = 0;
	
	createPEDescriptionFile( "./CGRA_PE_Description.txt", dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );
}