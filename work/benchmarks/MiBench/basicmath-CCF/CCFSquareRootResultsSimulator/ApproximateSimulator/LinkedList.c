#include "LinkedList.h"

/**
 * Helper function to wrap creating a node
 */
static inline Node* createNode( LinkedList* linkedList, void* data )
{
	Node* newNode = ( Node* )malloc( sizeof( Node ) );
	initNode( newNode );
	newNode->data = data;
	++linkedList->size;

	return newNode;
}

void initNode( Node* node )
{
	// set everything to null
	node->data = NULL;
	node->next = NULL;
	node->previous = NULL;
}

void initLinkedList( LinkedList* linkedList )
{
	// same thing for the list
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->printFunction = NULL;
	linkedList->size = 0;
}

void initLinkedListWithPrint( LinkedList* linkedList, PrintFunction printFunction )
{
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->printFunction = printFunction;
	linkedList->size = 0;
}

void pushFront( LinkedList* linkedList, void* data )
{
	// create the node
	Node* newNode = createNode( linkedList, data );
	
	// handle an empty list
	if ( linkedList->head == NULL )
	{
		linkedList->head = newNode;
		linkedList->tail = newNode;
		return;
	}

	// adjust the list to add a node on the front
	Node* originalFirstNode = linkedList->head;
	newNode->next = originalFirstNode;
	originalFirstNode->previous = newNode;
	linkedList->head = newNode;
}

void pushBack( LinkedList* linkedList, void* data )
{
	// create the node
	Node* newNode = createNode( linkedList, data );
	
	// handle an empty list
	if ( linkedList->head == NULL )
	{
		linkedList->head = newNode;
		linkedList->tail = newNode;
		return;
	}

	// adjust the list to add a node on the end
	Node* originalNode = linkedList->tail;
	originalNode->next = newNode;
	newNode->previous = originalNode;

	linkedList->tail = newNode;
}

void popFront( LinkedList* linkedList )
{
	// check for empty list
	if ( linkedList->head == NULL )
	{
		return;
	}

	// decrement the size
	--linkedList->size;

	// store the node to delete
	Node* frontNode = linkedList->head;

	// is this the only element in the list?
	if ( frontNode->next == NULL )
	{
		// reflect this is an empty list
		linkedList->head = NULL;
		linkedList->tail = NULL;

		free( frontNode );
		return;
	}

	// not the only node, so adjust accordingly
	linkedList->head = frontNode->next;

	linkedList->head->previous = NULL;

	free( frontNode );
}

void popBack( LinkedList* linkedList )
{
	// check for empty list
	if ( linkedList->head == NULL )
	{
		return;
	}

	Node* backNode = linkedList->tail;

	// decrement the size
	--linkedList->size;

	// is this the only element in the list?
	if ( backNode->previous == NULL )
	{
		// reflect this is an empty list
		linkedList->head = NULL;
		linkedList->tail = NULL;

		free( backNode );
		return;
	}

	linkedList->tail = backNode->previous;
	linkedList->tail->next = NULL;

	free( backNode );
}

void freeLinkedList( LinkedList* linkedList, DestroyNodeFunction destroyNodeFunction )
{
	// check for empty list
	if ( linkedList->head == NULL )
    {
		return;
    }

	// init local variables
    Node* currentNode;
	Node* temp;

	currentNode = linkedList->head;

	// iterate through the list
	while ( currentNode != NULL)
	{
		// store the node to delete
		temp = currentNode->next;

		// call destroyNodeFunction to determine whether the internal node data needs destroyed
		(*destroyNodeFunction)( currentNode->data );

		// free the node
		free( currentNode );

		// move to the next node
		currentNode = temp;
	}

	// adjust the rest of the variables to reflect an empty list
	linkedList->size = 0;
	linkedList->head = NULL;
	linkedList->tail = NULL;
}

void printListWithFunction( const LinkedList* const linkedList, PrintFunction printFunction )
{
	// get the list head
	Node* node = linkedList->head;
	
	// iterate through the list, printing according to the function
	while ( node != NULL )
	{
		(*printFunction)( node->data );
		node = node->next;
	}
}

void printList( const LinkedList* const linkedList )
{
	// check for NULL
	if ( linkedList->printFunction == NULL )
	{
		return;
	}

	// get the list head
	Node* node = linkedList->head;
	
	// iterate through the list, printing according to the function
	while ( node != NULL )
	{
		(*linkedList->printFunction)( node->data );
		node = node->next;
	}
}

Node* findNode( const LinkedList* const linkedList, SearchFunction searchFunction, void* checkingValue )
{
	// get the list head
	Node* node = linkedList->head;
	
	// iterate through the list, checking the each node with the searchFunction
	while ( node != NULL )
	{
		if ( (*searchFunction)( node->data, checkingValue ) )
		{
			// found node, now return it
			return node;
		}

		// set up next pass
		node = node->next;
	}

	// did not find the node, so return null
	return NULL;
}

bool findAndDeleteNode( LinkedList* linkedList, SearchFunction searchFunction, void* checkingValue )
{
	// find the node
	Node* toRemove = findNode( linkedList, searchFunction, checkingValue );

	// did not find node, so return null
	if ( toRemove == NULL )
	{
		return false;	
	}

	// decrement the size
	--linkedList->size;

	// if the found node is the only one in the list and return true since a node was deleted
	if ( toRemove->next == NULL && toRemove->previous == NULL )
	{
		// adjust the list accordingly
		linkedList->head = NULL;
		linkedList->tail = NULL;
		free( toRemove );
		return true;	
	}

	// handle removing the first node and return true since a node was deleted
	if ( toRemove->previous == NULL )
	{
		Node* next = toRemove->next;
		next->previous = NULL;	
		linkedList->head = next;
		free( toRemove );
		return true;
	}

	// handle removing the last node and return true since a node was deleted
	if ( toRemove->next == NULL )
	{
		Node* previous = toRemove->previous;
		previous->next = NULL;	
		linkedList->tail = previous;
		free( toRemove );
		return true;
	}

	// handle removing an intermediate node and return true since a node was deleted
	Node* previous = toRemove->previous;
	Node* next = toRemove->next;

	next->previous = previous;
	previous->next = next;

	free( toRemove );
	return true;
}