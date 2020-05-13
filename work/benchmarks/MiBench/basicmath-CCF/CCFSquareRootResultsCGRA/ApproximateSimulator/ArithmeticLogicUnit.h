#ifndef ARITHMETICLOGICUNIT_H
#define ARITHMETICLOGICUNIT_H

#include <stdbool.h>

/**
 * @brief This structure describes an approximate arithmetic logic unit. It contains the approximate number of bits and method
 * to be used to approximate the results. Additionally, it contains a flag that is used to determine if a logic unit is
 * being used or not.
 */
typedef struct 
{
	bool isUsed;
	int approximatedNumberOfBits;
	int approximationType;
	int lpcApproximationMethod;
} LogicUnitDescription;

/**
 * @brief Function to initialize the LogicUnitDescription structure
 * 
 * @param logicUnitDescription pointer to the LogicUnitDescription structure
 */
void initLogicUnitDescription( LogicUnitDescription* logicUnitDescription );

typedef struct 
{
	bool isUsed;
	int approximatedNumberOfBits;
	int approximationType;
	int multiplyMethod;
	int additionMethod;
} MultiplierDescription;

void initMultiplierDescription( MultiplierDescription* multiplierDescription );

/**
 * @brief The ArithmeticPEDescription structure is, basically, a container for each arithmetic unit's description. Therefore,
 * this structure contains the description for each PE's approximate hardware. 
 */
typedef struct 
{
	LogicUnitDescription adder;
	MultiplierDescription multiplier;
	LogicUnitDescription subtractor; 
} ArithmeticPEDescription;

/**
 * @brief Function to initialize the ArithmeticPEDescription structure
 * 
 * @param arithmeticPEDescription pointer to the ArithmeticPEDescription structure
 */
void initArithmeticPEDescription( ArithmeticPEDescription* arithmeticPEDescription );	

/**
 * @brief This method prints the results of the structure to the character buffer and position in the buffer given in the arguments. 
 * @note This has a character buffer to print to, so it can be used to print to a file or anything else. 
 * @param arithmeticPEDescription pointer to the ArithmeticPEDescription structure 
 * @param buffer to print to 
 * @param bufferPosition position in buffer to start printing. Since it is a pointer, the argument contains the current buffer position when this 
 * function ends. 
 */
void printArithmeticPEDescription( const ArithmeticPEDescription* const arithmeticPEDescription, char* buffer, int* bufferPosition );

#endif
