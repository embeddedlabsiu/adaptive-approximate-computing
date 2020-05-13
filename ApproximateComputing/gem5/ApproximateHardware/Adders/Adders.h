#ifndef ADDERS_H
#define ADDERS_H

namespace ApproximateComputing {

/**
 * @brief Class that contains the API for all of the approximate or exact adders. If one needs to add an adder to the project, 
 * the main method should be put here.
 */
class Adders 
{
public:

	/**
	 * @brief Method that calls the hardware implementation of the 32 bit exact adder 
	 * 
	 * @param a augend
	 * @param b addend
	 * @return unsigned sum
	 */
	static unsigned adder32Exact( unsigned a, unsigned b );

	/**
	 * @brief approximate adder that uses 50% of the exact adder's power 
	 * 
	 * @param a augend
	 * @param b addend
	 * @return unsigned sum
	 */
	static unsigned adder32FiftyPercentPower( unsigned a, unsigned b );
};
}

#endif