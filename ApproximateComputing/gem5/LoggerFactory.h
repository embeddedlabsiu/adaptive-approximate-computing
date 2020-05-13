#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <string>

class LoggingHandler;

namespace ApproximateComputing {
/**
 * @brief This class is based on a factory design pattern. Its only purpose is to create logging handlers. Its
 * constructor is private ensuring that an instance of this class cannot be created. 
 */
class LoggerFactory
{
public:

	/**
	 * @brief	buildLogger method creates the appropriate logging handler and returns a pointer to it.
	 * @param interface string of the interface
	 * @param filename string of the filename
	 * @return pointer to the logging handler
	 */
	static LoggingHandler* buildLogger( const std::string& filename, bool deleteFile = false );

private:

	/**
	 * @brief The constructors are private to ensure that an instance of this class cannot be created.
	 */
	LoggerFactory();
	LoggerFactory( const LoggerFactory& factory );
};

} // namespace ApproximateComputing
#endif // LOGGERFACTORY_H
