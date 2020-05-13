#ifndef CGRA_H
#define CGRA_H

#include <stdbool.h>
#include <stddef.h>
#include "ArithmeticLogicUnit.h"

#define CGRAMaxArraySize ( 36 )

/**
 * @brief Typedef to make using the CGRA easier
 */
typedef ArithmeticPEDescription CGRA[ CGRAMaxArraySize ];

/**
 * @brief Function to initialize the CGRA
 * 
 * @param cgra pointer to the CGRA
 */
void initCGRA( ArithmeticPEDescription* cgra );

/**
 * @brief This method takes the CGRA map and prints it into the buffer at the position given in the bufferPosition argument.
 * This method is useful to printf the contents of the CGRA data structure for debugging purposes.
 * 
 * @param cgra pointer to the CGRA
 * @param cgraSize size of the CGRA (or end of the elements to search) to not loop through values that do not matter
 * @param buffer to print to 
 * @param bufferPosition position in buffer to start printing. Since it is a pointer, the argument contains the current buffer position when this 
 */
void printCGRA( const CGRA const cgra, size_t cgraSize, char* buffer, int* bufferPosition );

/**
 * @brief This method parses the CGRA PE description file (CGRA_PE.txt) and returns the CGRA data structure set to the default values. 
 * 
 * @param fileToOpen Where the ArithmeticPEsList.txt file is located
 * @param cgra pointer to the CGRA 
 * @return size_t The max PE found
 */
size_t parseArithmeticPEsListFile( const char* fileToOpen, CGRA cgra );

/**
 * @brief This method takes the CGRA data structure and creates the CGRA_PE.txt file that GEM5 uses to setup the CGRA. This method
 * is what allows the executable to control GEM5's CGRA setting. Basically, the programmer calls this method when, for whatever 
 * programmatic reason, the approximation setup of the CGRA needs changed WHILE THE PROGRAM IS EXECUTING. This method is the "control knob", during
 * execution, of GEM5's CGRA.
 * 
 * @param fileToOpen location where the output will will be written
 * @param cgra pointer to the CGRA
 * @param cgraSize size of the CGRA (or end of the elements to search) to not loop through values that do not matter
 */
void createPEDescriptionFile( const char* fileToOpen, const CGRA cgra, size_t cgraSize );

void printPEDescriptionFile( const char* fileToOpen );

#endif
