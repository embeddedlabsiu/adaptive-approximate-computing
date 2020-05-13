#ifndef LOGGINGHANDLER_H
#define LOGGINGHANDLER_H

#include <string>
#include <fstream>

/**
 * @brief The LoggingHandler class handles logging to a file.
 */
class LoggingHandler
{
private:

	// Path of the file to log to
	const std::string _loggingPath;

	// Stream to file
	std::ofstream _outputStream;

public:

	/**
	 * @brief LoggingHandler constructor
	 * @param loggingPath to log to
	 */
	LoggingHandler( const std::string& loggingPath );

	~LoggingHandler();

	/**
	 * @brief log method to log the given string
	 * @param stringToLog string to log to the file
	 */
	void log( const std::string& stringToLog );

	/**
	 * @brief log method to log the given string
	 * @param stringToLog string to log to the file
	 */
	void log( const char* const stringToLog );

	/**
	 * @brief log method to log the given integer
	 * 
	 * @param intToLog integer to log to the file
	 */
	void log( const int intToLog );

	/**
	 * @brief loggingPath getter
	 * @return logging path
	 */
	const std::string& loggingPath() const;
};

#endif // LOGGINGHANDLER_H
