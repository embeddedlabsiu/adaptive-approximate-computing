#ifndef APPROXIMATECOMPUTING_H
#define APPROXIMATECOMPUTING_H

#include <fstream>
#include <string>
#include <vector>

namespace ApproximateComputing {

/**
 * @brief This class logs the given vector.
 * 
 */
struct PELogger
{
	/**
	 * @brief typedef to make syntax easier
	 * 
	 */
	typedef std::vector< unsigned > ArithmeticPEs;	

	/**
	 * @brief method that logs the ArithmeticPEs vector
	 * 
	 * @param fileToLog file to write to 
	 * @param peToLog vector to log
	 */
	static void logArithmeticPEs( std::ofstream& fileToLog, const ArithmeticPEs& peToLog );

private:

	/**
	 * @brief The constructors are private to ensure that an instance of this class cannot be created.
	 */
	PELogger();

	PELogger( const PELogger& parser );
};

} // namespace ApproximateComputing
#endif