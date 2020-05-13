#include "ArithmeticLogicUnitList.h"

#include <stdio.h>

/**
 * @brief function that prints the ArithmeticLogicUnitNode to the terminal.
 * 
 * @param data pointer to ArithmeticLogicUnitNode
 */
void printArithmeticLogicUnitNode( void* data ) 
{ 
	ArithmeticLogicUnitNode* node = (ArithmeticLogicUnitNode*) data;
	printf("PE: %lu, Approx Bits: %i, Approx Type: %i\n", node->peNumber, node->desc->approximatedNumberOfBits, node->desc->approximationType ); 
} 

void printMultiplierLogicUnitNode( void* data ) 
{ 
	MultiplierLogicUnitNode* node = (MultiplierLogicUnitNode*) data;
	printf("PE: %lu, Approx Bits: %i, Approx Type: %i, Addition Method: %i, Multiply Method: %i\n"
	, node->peNumber
	, node->desc->approximatedNumberOfBits
	, node->desc->approximationType
	, node->desc->additionMethod
	, node->desc->multiplyMethod ); 
} 

/**
 * @brief function that is used to search for a node.
 * @note This function is not the only search that can be done.
 * For instance, one could make a lookup function that searches for a specific
 * value inside of the ArithmeticLogicUnitNode instead of the PE number.
 * @param data pointer to the data to be searched
 * @param criterion pointer to what is being checked against.
 * @return true if node meets the criterion
 * @return false if node does not meet the criterion
 */
bool nodeLookup( void* data, void* criterion )
{
	ArithmeticLogicUnitNode* node = (ArithmeticLogicUnitNode*)data;
	size_t value = *((size_t*) criterion );
	return node->peNumber == value;
}

/**
 * @brief function to destroy the data inside the node.
 * @note This is necessary because some lists may not need the data freed. For instance,
 * if ArithmeticLogicUnitNode was not malloc'd, this function would not contain anything
 * in the implementation. 
 * @param nodeData data to free
 */
void destroyNodeData( void* nodeData  ) 
{
	free( nodeData );
}

LinkedList* getAdderList( CGRA cgra, size_t cgraSize )
{
	// init local variables
	LinkedList* list = malloc( sizeof( LinkedList ) );
	initLinkedListWithPrint( list, &printArithmeticLogicUnitNode );
	ArithmeticPEDescription* pe;
	ArithmeticLogicUnitNode* node;

	// @todo too much copy and paste between these function. Divide into two function.
	// loop through the CGRA 
	for ( size_t loop = 0; loop <= cgraSize; ++loop )
	{
		// get a pointer to the PE
		pe = &cgra[ loop ];

		// is this an empty PE
		if ( pe->adder.isUsed )
		{
			// create data to be stored
			node = malloc( sizeof( ArithmeticLogicUnitNode ) );

			// setup the proper variables
			node->peNumber = loop;
			node->desc = &pe->adder;

			// add it to the list
			pushBack( list, node );
		}
	}

	return list;
}

LinkedList* getMultiplierList( CGRA cgra, size_t cgraSize )
{
	// init local variables
	LinkedList* list = malloc( sizeof( LinkedList ) );
	initLinkedListWithPrint( list, &printMultiplierLogicUnitNode );
	ArithmeticPEDescription* pe;
	MultiplierLogicUnitNode* node;

	// @todo too much copy and paste between these function. Divide into two function.
	// loop through the CGRA 
	for ( size_t loop = 0; loop <= cgraSize; ++loop )
	{
		// get a pointer to the PE
		pe = &cgra[ loop ];

		// is this an empty PE
		if ( pe->multiplier.isUsed )
		{
			// create data to be stored
			node = malloc( sizeof( MultiplierDescription ) );

			// setup the proper variables
			node->peNumber = loop;
			node->desc = &pe->multiplier;

			// add it to the list
			pushBack( list, node );
		}
	}

	return list;
}

LinkedList* getSubtractorList( CGRA cgra, size_t cgraSize )
{
	// init local variables
	LinkedList* list = malloc( sizeof( LinkedList ) );
	initLinkedListWithPrint( list, &printArithmeticLogicUnitNode );
	ArithmeticPEDescription* pe;
	ArithmeticLogicUnitNode* node;

	// @todo too much copy and paste between these function. Divide into two function.
	// loop through the CGRA 
	for ( size_t loop = 0; loop <= cgraSize; ++loop )
	{
		// get a pointer to the PE
		pe = &cgra[ loop ];

		// is this an empty PE
		if ( pe->subtractor.isUsed )
		{
			// create data to be stored
			node = malloc( sizeof( ArithmeticLogicUnitNode ) );

			// setup the proper variables
			node->peNumber = loop;
			node->desc = &pe->subtractor;

			// add it to the list
			pushBack( list, node );
		}
	}

	return list;
}

LogicUnitDescription* findPEByNumber( LinkedList* list, size_t peNumber)
{
	// init local variables
	Node* node = findNode( list, nodeLookup, &peNumber );

	// check if the node was found
	if ( node == NULL )
	{
		return NULL;
	}

	// cast everything before returning it
	ArithmeticLogicUnitNode* unitNode = (ArithmeticLogicUnitNode*)node->data;
	return (LogicUnitDescription*)unitNode->desc;
}

void freeArithmeticLogicUnitList( LinkedList* list )
{
	// free the list
	freeLinkedList( list, destroyNodeData );

	// free the LinkedList structure
	free( list );
}