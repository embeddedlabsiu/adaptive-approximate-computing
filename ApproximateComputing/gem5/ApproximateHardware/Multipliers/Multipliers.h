#ifndef MULTIPLIERS_H
#define MULTIPLIERS_H

namespace ApproximateComputing {

/**
 * @brief Class that contains the API for all of the approximate or exact multipliers. If one needs to add an multiplier to the project, 
 * the main method should be put here.
 */
class Multipliers 
{
public:

	/**
	 * @brief Method for multiplying 64 bit numbers with exact precision
	 * 
	 * @param a Multiplier
	 * @param b Multiplicand
	 * @return unsigned long int product
	 */
	static unsigned long int multiplier32_64Exact( unsigned long int a, unsigned long int b );

	/**
	 * @brief Method for multiplying 32 bit numbers with exact precision
	 * 
	 * @param a Multiplier
	 * @param b Multiplicand
	 * @return unsigned long int product
	 */
	static unsigned multiplier32_32Exact( unsigned a, unsigned b );

	/**
	 * @brief Method for multiplying 32 bit numbers with approximate precision. This is the first implementation of 
	 * M lab.
	 * 
	 * @param a Multiplier
	 * @param b Multiplicand
	 * @return unsigned long int product
	 */
	static unsigned int multiplier32_32ApproximateFirstMLab( unsigned int a, unsigned int b );
};
}

#endif