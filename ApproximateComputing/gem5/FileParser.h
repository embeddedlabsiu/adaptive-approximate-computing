#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "ApproximateComputing.h"

namespace ApproximateComputing {
namespace FileHelper {
	/**
	 * @brief The Parser class parses the given file and returns the filled Results structure
	 */
	class Parser
	{
	public:

		/**
		 * @brief This structure describes a CGRA PE unit that can have independent settings for multiplier, adder, and subtractor.
		 * 
		 */
		struct CgraPeDescription
		{
			ApproximateComputing::HardwareDescription::LogicUnitDescription adder;
			ApproximateComputing::HardwareDescription::MultiplyDescription multiplier;
			ApproximateComputing::HardwareDescription::LogicUnitDescription subtractor;
		};

		/**
		 * @brief This structure contains the results of the CGRA PE description.
		 * 
		 */
		struct Results
		{
			unsigned int numberOfResults;
			CgraPeDescription* descriptions;	

			Results()
				: numberOfResults( 0 )
				, descriptions( nullptr )
			{}
		};

		/**
		 * @brief This method parses the CGRA PE description file and returns the results.
		 * 
		 * @param fileToOpen file to open and read
		 * @param errorMessage message to print if anything goes wrong in the method
		 * @return Results* pointer to the results
		 */
		static Results* parseFile( const char* fileToOpen, const char* errorMessage );

		/**
		 * @brief This method prints the results of the structure to a character buffer, then return it. Great care must be used when calling this
		 * method in a multithreaded program. This is because there is one static character buffer this method fills, so if this method
		 * is called in parallel, undesired behavaviour will occur.
		 * 
		 * @param results to print
		 * @return char* buffer that the results were printed in
		 */
		static char* printResults( const Results* const results );

		/**
		 * @brief This method deletes the Results structure.
		 * 
		 * @param results to be freed
		 */
		static void deleteResults( const Results* const results );

		/**
		 * @brief printDescription prints a single CGRA PE Description to the terminal
		 * @param CgraPeDescription pointer to the pe description
		 */
		static void printDescription( const CgraPeDescription* const CgraPeDescription );

	private:

		/**
		 * @brief The constructors are private to ensure that an instance of this class cannot be created.
		 */
		Parser();

		Parser( const Parser& parser );
	};

} // namespace FileHelper
} // namespace ApproximateComputing
#endif
