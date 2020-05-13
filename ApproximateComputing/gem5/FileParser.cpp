#include "FileParser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace ApproximateComputing {
namespace FileHelper {
static FILE* openFile( const char* fileToOpen, const char* filePermission, const char* errorMessage )
{
	FILE* file = NULL;
	
	// open the file
	file = fopen ( fileToOpen, filePermission );
	
	// did the file open
	if ( file == NULL )
	{
		fputs( errorMessage, stderr );
		return NULL;
	}

	return file;
}

/**
 * This method calls the openFile, buffers the file, then returns the character buffer.
 */
static char* openAndBufferFile( const char* fileToOpen, const char* errorMessage )
{
	size_t size;
	size_t result;
	char* fileBuffer;
	
	FILE* file = openFile( fileToOpen, "r", errorMessage );

	// move "cursor" to the end
	fseek( file, 0, SEEK_END );

	// get the size of the file
	size = ftell( file );

	// if file is empty
	if ( size == 0 )
	{
		fputs( "File Size error", stderr );
		fclose( file );
		return NULL;
	}

	// rewind the "cursor" to the beginning of the file
	rewind( file );

	// create the file buffer's memory
	fileBuffer = ( char* ) malloc( ( sizeof( char ) * size ) + 2 );
	
	// if there is no heap memory available
	if ( fileBuffer == NULL )
	{
		// print the error, close the file, and return null pointer
		fputs( "Memory error", stderr );
		fclose( file );
		return NULL;
	}
	
	// cache the file
	result = fread( fileBuffer, 1, size, file );

	// close the file
	fclose( file );

	if ( result != size )
	{
		// print the error, close the file, free the memory, and return null pointer
		free( fileBuffer );
		fputs( "Size error", stderr );
		return NULL;
	}

	return fileBuffer;
}

Parser::Results* Parser::parseFile( const char* fileToOpen, const char* errorMessage )
{
#define BufferSize ( 1024 )
	// init variables
	char* fileBuffer;
	char tempBuffer[ BufferSize ] = {'\0'};
	size_t resultCounter = 0;
	size_t loopCounter = 0;
	size_t tempBufferCounter = 0;
	Results* results = nullptr;
	Parser::CgraPeDescription defaultDescription;// = CgraPeDescription();
	size_t colonCounter = 0;
	size_t commaCounter = 0;
	char loopVariable;
	ApproximateComputing::HardwareDescription::LogicUnitDescription* currentLogicUnit = nullptr;
	ApproximateComputing::HardwareDescription::MultiplyDescription* multiplyLogicUnit = nullptr;

	fileBuffer = openAndBufferFile( fileToOpen, errorMessage );
	
	// create the results
	results = new Results();

	while ( fileBuffer[ loopCounter ] == '#' )
	{
		while ( fileBuffer[ loopCounter++ ] != '\n' )
		{}
	}

	// move to the :
	while ( fileBuffer[ ++loopCounter ] != ':' )
	{}

	// store everything until the end of the line
	while ( fileBuffer[ ++loopCounter ] != '\n' )
	{
		tempBuffer[ tempBufferCounter++ ] = fileBuffer[ loopCounter ];
	}

	// convert the buffer into an integer
	results->numberOfResults = atoi( tempBuffer );

	// clear the buffer
	memset( tempBuffer, (int)'\0', tempBufferCounter );

	// reset the counter
	tempBufferCounter = 0;

	// move to the :
	while ( fileBuffer[ ++loopCounter ] != ':' )
	{}
	--loopCounter;
	
	// store everything until the end of the line
	while ( ( loopVariable = fileBuffer[ ++loopCounter ] ) != '\0' && loopVariable != '\n' )
	{
		// switch on the character
		switch ( loopVariable )
		{
		case ',':
			++commaCounter;
			
			switch ( commaCounter )
			{
			case 1:
				if ( colonCounter == 3 )
				{
					multiplyLogicUnit->approximatedNumberOfBits = atoi( tempBuffer );
					break;
				}
				currentLogicUnit->approximatedNumberOfBits = atoi( tempBuffer );
				//printf("%lu bit %i\n", resultCounter, currentLogicUnit->approximatedNumberOfBits);
				break;

			case 2:
				if ( colonCounter == 3 )
				{
					multiplyLogicUnit->approximationType = atoi( tempBuffer );
					break;
				}
				currentLogicUnit->approximationType = atoi( tempBuffer );
				break;
			case 3:
				multiplyLogicUnit->additionMethod = atoi( tempBuffer );
				break;
			}

			// convert the stored value to the correct approximatedNumberOfBits
			memset( tempBuffer, (int)'\0', tempBufferCounter );
			tempBufferCounter = 0;
			break;

		case ':':
			++colonCounter;
			switch ( colonCounter )
			{
			case 1:
				currentLogicUnit = &defaultDescription.adder;
				break;

			case 2:
				currentLogicUnit->lpcApproximationMethod = atoi( tempBuffer );
				currentLogicUnit = &defaultDescription.subtractor;
				break;

			case 3:
				currentLogicUnit->lpcApproximationMethod = atoi( tempBuffer );
				multiplyLogicUnit = &defaultDescription.multiplier;
				break;
			}

			// convert the stored value to the correct approximatedNumberOfBits
			memset( tempBuffer, (int)'\0', tempBufferCounter );
			tempBufferCounter = 0;
			commaCounter = 0;
			break;

		default:
			// store the contents of the file into the buffer
			tempBuffer[ tempBufferCounter++ ] = fileBuffer[ loopCounter ];
			//printf("%s\n", tempBuffer ); 
			break;
		}
	}

	// convert the last value
	defaultDescription.multiplier.multiplyMethod = atoi( tempBuffer );



	printDescription( &defaultDescription );
	// clear the buffer
	memset( tempBuffer, (int)'\0', tempBufferCounter );

	// reset the counter
	tempBufferCounter = 0;
	commaCounter = 0;
	colonCounter = 0;

	// create the array of descriptions
	results->descriptions = new CgraPeDescription[ results->numberOfResults ];

	for ( size_t counter = 0; counter < results->numberOfResults; ++counter )
	{
		results->descriptions[ counter ] = defaultDescription;
	}
	
	// loop to the end of the file
	while( ( loopVariable = fileBuffer[ ++loopCounter ] ) != '\0' )
	{
		// switch on the character
		switch ( loopVariable )
		{
		case ',':
			++commaCounter;
			switch ( commaCounter )
			{
			case 1:
				if ( colonCounter == 3 )
				{
					multiplyLogicUnit->approximatedNumberOfBits = atoi( tempBuffer );
					break;
				}
				currentLogicUnit->approximatedNumberOfBits = atoi( tempBuffer );
				//printf("%lu bit %i\n", resultCounter, currentLogicUnit->approximatedNumberOfBits);
				break;

			case 2:
				if ( colonCounter == 3 )
				{
					multiplyLogicUnit->approximationType = atoi( tempBuffer );
					break;
				}
				currentLogicUnit->approximationType = atoi( tempBuffer );
				break;
			case 3:
				multiplyLogicUnit->additionMethod = atoi( tempBuffer );
				break;
			}

			// convert the stored value to the correct approximatedNumberOfBits
			memset( tempBuffer, (int)'\0', tempBufferCounter );
			tempBufferCounter = 0;
			break;

		case ':':
			++colonCounter;
			switch ( colonCounter )
			{
			case 1:
				resultCounter = atoi( tempBuffer );
				currentLogicUnit = &results->descriptions[ resultCounter ].adder;
				break;

			case 2:
				currentLogicUnit->lpcApproximationMethod = atoi( tempBuffer );
				currentLogicUnit = &results->descriptions[ resultCounter ].subtractor;
				break;

			case 3:
				currentLogicUnit->lpcApproximationMethod = atoi( tempBuffer );
				multiplyLogicUnit = &results->descriptions[ resultCounter ].multiplier;
				break;
			}

			// convert the stored value to the correct approximatedNumberOfBits
			memset( tempBuffer, (int)'\0', tempBufferCounter );
			tempBufferCounter = 0;
			commaCounter = 0;
			break;

		case '\n':
			// convert the stored value to the correct approximationMethod
			//printf("First:\n");
			//printDescription( &results->descriptions[ resultCounter ] );
			results->descriptions[ resultCounter ].multiplier.multiplyMethod = atoi( tempBuffer );
			memset( tempBuffer, (int)'\0', tempBufferCounter );
			//printf("Second:\n");
			//printDescription( &results->descriptions[ resultCounter ] );
			tempBufferCounter = 0;
			commaCounter = 0;
			colonCounter = 0;
			break;

		default:
			// store the contents of the file into the buffer
			tempBuffer[ tempBufferCounter++ ] = fileBuffer[ loopCounter ];
			//printf("%s\n", tempBuffer ); 
			break;
		}
	}

	// free the buffer
	free( fileBuffer );

	// return the results
	return results;
}

char* Parser::printResults( const Parser::Results* const results )
{
#define BufferSize2 ( 2048 )
	size_t size = results->numberOfResults;
	size_t counter = 0;
	int bufferPosition;
	static char buffer[ BufferSize2 ];

	bufferPosition = snprintf( buffer, BufferSize2, "Result #, bits, approx method, mult method, add method\n" );

	for ( ; counter < size; ++counter )
	{
		bufferPosition += snprintf( buffer + bufferPosition, BufferSize2 - bufferPosition, "%lu->%i,%i,%i:%i,%i,%i:%i,%i,%i,%i\n"
				, counter
				, results->descriptions[ counter ].adder.approximatedNumberOfBits
				, results->descriptions[ counter ].adder.approximationType
				, results->descriptions[ counter ].adder.lpcApproximationMethod

				, results->descriptions[ counter ].subtractor.approximatedNumberOfBits
				, results->descriptions[ counter ].subtractor.approximationType
				, results->descriptions[ counter ].subtractor.lpcApproximationMethod

				, results->descriptions[ counter ].multiplier.approximatedNumberOfBits
				, results->descriptions[ counter ].multiplier.approximationType 
				, results->descriptions[ counter ].multiplier.additionMethod
				, results->descriptions[ counter ].multiplier.multiplyMethod );
	}
	return buffer;
}

void Parser::deleteResults( const Parser::Results* const results )
{
	delete[] results->descriptions;  
	delete results;
}

void Parser::printDescription( const CgraPeDescription* const CgraPeDescription )
{
	printf( "%i,%i,%i:%i,%i,%i:%i,%i,%i,%i\n"
			, CgraPeDescription->adder.approximatedNumberOfBits
			, CgraPeDescription->adder.approximationType
			, CgraPeDescription->adder.lpcApproximationMethod

			, CgraPeDescription->subtractor.approximatedNumberOfBits
			, CgraPeDescription->subtractor.approximationType
			, CgraPeDescription->subtractor.lpcApproximationMethod

			, CgraPeDescription->multiplier.approximatedNumberOfBits
			, CgraPeDescription->multiplier.approximationType
			, CgraPeDescription->multiplier.additionMethod
			, CgraPeDescription->multiplier.multiplyMethod );
}

} // namespace FileHelper
} // namespace ApproximateComputing