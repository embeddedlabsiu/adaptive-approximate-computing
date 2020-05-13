#ifndef ARITHMETICLOGICUNITLIST_H
#define ARITHMETICLOGICUNITLIST_H

#include "CGRA.h"
#include "LinkedList.h"

/**
 * @brief This file should also serve as a guide to "wrap" the generic linked list with specific api based on the data type being
 * stored.
 * This interface allows the linked list to be used more easily and to "hide" specifics in the associated .c file.
 */


/**
 * @brief Contains the description of the arithmetic logic unit and PE number. The LogicUnitDescription* allows the list to change the approximate
 * method and number of bits directly. The PE number is needed because, in the CGRA, the PE number is the position in the array.
 * Since this is a list, it is not possible to handle it in the same manner as the CGRA, so the peNumber is used for this purpose.
 * 
 */
typedef struct 
{
	size_t peNumber;
	LogicUnitDescription* desc;
} ArithmeticLogicUnitNode;

typedef struct 
{
	size_t peNumber;
	MultiplierDescription* desc;
} MultiplierLogicUnitNode;

/**
 * @brief Get the Adder List object from the given CGRA. 
 * @note This function mallocs the linked list, as well as, the void*, which points to a ArithmeticLogicUnitNode. Therefore, 
 * one has to call freeArithmeticLogicUnitList to free up the dynamic memory, or a large memory leak will occur
 * @param cgra pointer to the CGRA
 * @param cgraSize size of the CGRA (or end of the elements to search) to not loop through values that do not matter
 * @return LinkedList* pointer to the created linked list
 */
LinkedList* getAdderList( CGRA cgra, size_t cgraSize );

/**
 * @brief Get the Multiplier List object from the given CGRA
 * @note This function mallocs the linked list, as well as, the void*, which points to a ArithmeticLogicUnitNode. Therefore, 
 * one has to call freeArithmeticLogicUnitList to free up the dynamic memory, or a large memory leak will occur
 * @param cgra pointer to the CGRA
 * @param cgraSize size of the CGRA (or end of the elements to search) to not loop through values that do not matter
 * @return LinkedList* pointer to the created linked list
 */
LinkedList* getMultiplierList( CGRA cgra, size_t cgraSize );

/**
 * @brief Get the Subtractor List object from the given CGRA
 * @note This function mallocs the linked list, as well as, the void*, which points to a ArithmeticLogicUnitNode. Therefore, 
 * one has to call freeArithmeticLogicUnitList to free up the dynamic memory, or a large memory leak will occur
 * @param cgra pointer to the CGRA
 * @param cgraSize size of the CGRA (or end of the elements to search) to not loop through values that do not matter
 * @return LinkedList* pointer to the created linked list 
 */
LinkedList* getSubtractorList( CGRA cgra, size_t cgraSize );

/**
 * @brief Finds the associated LogicUnitDescription based on the given PE number.
 * 
 * @param list pointer to the linked list
 * @param peNumber pe number to look for
 * @return LogicUnitDescription* if found, pointer to the LogicUnitDescription based on the given pe number.
 * However, if no pe is found, this function returns null
 */
LogicUnitDescription* findPEByNumber( LinkedList* list, size_t peNumber);

/**
 * @brief This function frees all of the dynamic memory of the linked list.
 * @note This also calls free on the LinkedList structure as well as all of the data
 * inside the list.
 * @param list to free
 */
void freeArithmeticLogicUnitList( LinkedList* list );

#endif
