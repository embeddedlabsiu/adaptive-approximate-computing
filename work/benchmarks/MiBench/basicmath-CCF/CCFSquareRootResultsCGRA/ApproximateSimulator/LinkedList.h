#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief This list seems complicated, but making lists generic in C is difficult. 
 * This list can be used to store a pointer to ANY datatype. 
 * Also, it is doubly linked list, so going backwards and forwards is possible. 
 * Wrapping a list, like ArithmeticLogicUnitList, reduces some of the complexity, and 
 * adds list specific API to the list. 
 * Therefore, one should use this linked list whenever possible, and add functionaliy/fix bugs
 * as required.
 */

/**
 * @brief Defines the generic linked list node
 */
typedef struct Node_t
{
	void* data;
	struct Node_t* next;
	struct Node_t* previous;   
} Node;

/**
 * @brief Initializes the node's data to NULL
 * 
 * @param node pointer to the node to be initialised
 */
void initNode( Node* node );

/**
 * @brief Since this is a generic list, one has to define how to print the data
 * because a void* can point to ANYTHING
 */
typedef void (*PrintFunction)(void *);

/**
 * @brief This function is used to search the list for a certain node.
 * The nodeData variable is a point to the node's data.
 * The checkingCriterion is what the function is looking for.
 * For example:
 *	The below struct defines the void* data datatype
 *	typedef struct 
 *	{
 *		size_t peNumber;
 *		ArithmeticPEDescription* desc;
 *	} Test;
 *
 *  The below struct defines the SearchFunction.
 * 	It simply casts the data void* to the Test struct,
 *  casts the criterion to a size_t type, and,
 * 	finally, returns whether the peNumber equals the criterion.
 *	bool nodeLookup( void * data, void* criterion )
 *	{
 *		Test* testing = (Test*)data;
 *		size_t value = *((size_t*) criterion );
 *		return testing->peNumber == value;
 *	}
 */
typedef bool (*SearchFunction)(void * nodeData, void* checkingCriterion );

/**
 * @brief This function is used to destroy the list. Since the void* data
 * can represent a value on the stack (or other place one does not want destoyed) or
 * a value on the heap that needs destroyed when the list is destroyed, this function
 * allows the list to handle both problems. 
 * For example:
 *	The below function would NOT free the data inside the void*
 *	void doNotDestroyNode( void * nodeData  ) {}
 *
 *	The below function WOULD free the data inside the void*
 *	void doNotDestroyNode( void * nodeData  ) { free( nodeData ); }
 */
typedef void (*DestroyNodeFunction)(void * nodeData );

/**
 * @brief This structure represents the actual linked list. It contains SOME metadata about
 * the list's head, tail, size, and how to print the list. 
 * The head points to the first node, tail points to the last node, printFunction 
 * is how to print each node, and size is the size of the list.
 */
typedef struct 
{	
	Node* head;
	Node* tail;
	PrintFunction printFunction;
	size_t size;
} LinkedList;

/**
 * @brief This function initializes the linked list. It puts all pointers to NULL
 * and sets the size to zero.
 * 
 * @param linkedList pointer to the linked list
 */
void initLinkedList( LinkedList* linkedList );

/**
 * @brief This function does the same as initLinkedList except is sets the printFunction to 
 * the given argument.
 * 
 * @param linkedList pointer to the linked list
 * @param printFunction function pointer to the print function
 */
void initLinkedListWithPrint( LinkedList* linkedList, PrintFunction printFunction );

/**
 * @brief This function adds a node to the front of the list.
 * 
 * @param linkedList pointer to the linked list
 * @param data to be added to the list
 */
void pushFront( LinkedList* linkedList, void* data );

/**
 * @brief This function adds a node to the end of the list.
 * 
 * @param linkedList pointer to the linked list
 * @param data to be added to the list
 */
void pushBack( LinkedList* linkedList, void* data );

/**
 * @brief This function removes the front node.
 * 
 * @param linkedList pointer to the linked list
 */
void popFront( LinkedList* linkedList );

/**
 * @brief This function removes the end node.
 * 
 * @param linkedList pointer to the linked list
 */
void popBack( LinkedList* linkedList );

/**
 * @brief This function frees the list, and depending on the destroyNodeFunction, it will
 * free the data inside the node.
 * 
 * @param linkedList pointer to the linked list
 * @param destroyNodeFunction function pointer to destroy the node
 */
void freeLinkedList( LinkedList* linkedList, DestroyNodeFunction destroyNodeFunction );

/**
 * @brief This function prints the linked list to the terminal.
 * 
 * @param linkedList pointer to the linked list
 */
void printList( const LinkedList* const linkedList );

/**
 * @brief This function does the same as above except it has the argument on how to print
 * each node.
 * 
 * @param linkedList pointer to the linked list
 * @param printFunction 
 */
void printListWithFunction( const LinkedList* const linkedList, PrintFunction printFunction );

/**
 * @brief This function finds a specific node, based on the searchFunction and checkingValue,
 * and return the node.
 * 
 * @param linkedList pointer to the linked list
 * @param searchFunction function pointer used to search the list
 * @param checkingValue value to check against
 * @return Node* pointer to the node that was found. This function returns NULL if the node is not found.
 */
Node* findNode( const LinkedList* const linkedList, SearchFunction searchFunction, void* checkingValue );

/**
 * @brief This function finds and deletes a specific node, based on the searchFunction and checkingValue,
 * and returns true if successful. 
 * 
 * @param linkedList pointer to the linked list
 * @param searchFunction function pointer used to search the list
 * @param checkingValue value to check against
 * @return true if the node was found and deleted
 * @return false if the node was not found
 */
bool findAndDeleteNode( LinkedList* linkedList, SearchFunction searchFunction, void* checkingValue );

#endif
