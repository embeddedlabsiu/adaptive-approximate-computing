#ifndef DYNAMICCGRACONTROL_H
#define DYNAMICCGRACONTROL_H

#include "ArithmeticLogicUnitList.h"

/**
 * @brief This structure holds the variables used for dynamic control of the CGRA PEs
 * 
 */
typedef struct 
{
	CGRA cgra;
	size_t cgraSize;

	LinkedList* adderList;
	LinkedList* multiplierList;
	LinkedList* subtractorList;
} DynamicCGRAControl;

/**
 * @brief Initializes the dynamicCGRAControl structure with the values in the CGRA array.
 * 
 * @param dynamicCGRAControl pointer to the dynamical CGRA control
 * @param fileToOpen file where the ArithmeticPEsList.txt
 */
void initDynamicCGRAControl( DynamicCGRAControl* dynamicCGRAControl, const char* fileToOpen );

/**
 * @brief frees the linked lists in the DynamicCGRAControl structure
 * 
 * @param dynamicCGRAControl pointer to the dynamical CGRA control
 */
void freeDynamicCGRAControl( DynamicCGRAControl* dynamicCGRAControl );

/**
 * @brief prints all of the Linked Lists 
 * 
 * @param dynamicCGRAControl pointer to the dynamical CGRA control
 */
void printAllLists( DynamicCGRAControl* dynamicCGRAControl );

typedef struct 
{
	double value;
	double error;	
} Pair;

typedef struct 
{
	Pair zeroApproximation;
	Pair firstApproximation;
	Pair thirdApproximation;
} Results;

/**
 * @brief This is the cyclic call to control the CGRA at runtime.
 * @todo Fill in the implementation
 * @note This does not contain much because there is no control mechanism as of yet
 * @param dynamicCGRAControl pointer to the dynamical CGRA control
 * @param error 
 */
void dynamicControl( DynamicCGRAControl* dynamicCGRAControl, Results* result, size_t x, int numberOfBits );

void initResults( Results* results );

#endif
