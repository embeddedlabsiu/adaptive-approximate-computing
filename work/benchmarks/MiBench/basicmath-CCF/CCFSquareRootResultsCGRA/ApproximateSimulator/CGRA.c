#include "CGRA.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "CGRADefinitions.h"

//****Helper Functions For This File****//
/**
 * This helper function just opens a file and checks for validity, then returns the file pointer
 */
static FILE* openFile( const char* fileToOpen, const char* filePermission )
{
	FILE* file = NULL;
	
	// open the file
	file = fopen ( fileToOpen, filePermission );
	
	// did the file open
	if ( file == NULL )
	{
		fputs( "BAD FILE@@@@@@@@@@@@@@@@\n", stderr );
		return NULL;
	}

	return file;
}

/**
 * This method calls the openFile, buffers the file, then returns the character buffer.
 */
static char* openAndBufferFile( const char* fileToOpen )
{
	size_t size;
	size_t result;
	char* fileBuffer;
	
	FILE* file = openFile( fileToOpen, "r" );

	// move "cursor" to the end
	fseek( file, 0, SEEK_END );

	// get the size of the file
	size = ftell( file );

	// if file is empty
	if ( size == 0 )
	{
		fputs( "!!!!File Size error\n", stderr );
		printf("FILE SIZE ERROR\n" );
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

/**
 * This method loops through the file buffer and creates the CGRA data structure.
 */
static size_t getPEs( CGRA cgra, char* fileBuffer, size_t* loopCounter )
{
	// init the variables
	char tempBuffer[ BufferSize ];
	int newLineCounter = 0;
	size_t tempLoopCounter = *loopCounter;
	size_t tempBufferCounter = 0;
	size_t maxPENumber = 0;
	--tempLoopCounter; // done because the buffer is set to the first PE

	// while the file is not parse
	while ( newLineCounter < 3 )
	{
		// increment the counter
		tempLoopCounter++;

		// if there is an empty PE list, skip it and increment the new line counter
		if ( fileBuffer[ tempLoopCounter ] == '!' )
		{
			tempLoopCounter += 1;
			++newLineCounter; 	  
			continue;
		}

		// if the current character is a digit
		if ( isdigit( fileBuffer[ tempLoopCounter ] ) )
		{
			// store the digit
			tempBuffer[ tempBufferCounter++ ] = fileBuffer[ tempLoopCounter ];	
		}

		// if there is a , or a new line, it is the end of the PE integer
		if ( fileBuffer[ tempLoopCounter ] == ',' || fileBuffer[ tempLoopCounter ] == '\n' )
		{
			int peNumber = atoi( tempBuffer );
			
			// get the PE from the map or create it if it does not exit
			ArithmeticPEDescription* description = &cgra[ peNumber ];

			if ( peNumber > maxPENumber )
			{
				maxPENumber = peNumber;
			}
			
			// what kind of PE (adder, subtractor, multiplier)
			switch ( newLineCounter )
			{
			case 0:
				// set the appropriate number of bits to the default value if the PE's arithmetic unit is being used.
				description->adder.isUsed = true;
				description->adder.approximatedNumberOfBits = 0;
				description->adder.approximationType = AdderTypesStandardAddition;
				description->adder.lpcApproximationMethod = LPCLibraryMethodZeroApproximation;
				break;
			
			case 1:
				// set the appropriate number of bits to the default value if the PE's arithmetic unit is being used.
				description->multiplier.isUsed = true;
				description->multiplier.approximatedNumberOfBits = 0;
				description->multiplier.approximationType = MultiplierTypesStandardMultiplier;
				description->multiplier.additionMethod = -1;
				description->multiplier.multiplyMethod = -1;
				break;

			case 2:
				// set the appropriate number of bits to the default value if the PE's arithmetic unit is being used.
				description->subtractor.isUsed = true;
				description->subtractor.approximatedNumberOfBits = 0;
				description->subtractor.approximationType = SubtractorTypesLpCLibMethod;
				description->subtractor.lpcApproximationMethod = LPCLibraryMethodZeroApproximation;
				break; 
			}
			
			// clear the temporary buffer
			memset( tempBuffer, (int)'\0', tempBufferCounter );

			// reset the counter
			tempBufferCounter = 0;	
		}

		// increment the new line counter appropriately
		if ( fileBuffer[ tempLoopCounter ] == '\n' ) 
		{
			++newLineCounter;	
		}
	}

	*loopCounter = tempLoopCounter;
	return maxPENumber;
}

//****Header Functions For This File****//
void initCGRA( ArithmeticPEDescription* cgra )
{
	for ( size_t loop = 0; loop < CGRAMaxArraySize; ++loop )
	{
		initArithmeticPEDescription( &cgra[ loop ] );
	}
}

size_t parseArithmeticPEsListFile( const char* fileToOpen, CGRA cgra )
{
	// init variables
	char* fileBuffer;	
	size_t loopCounter = 0;
	size_t maxPENumber;

	fileBuffer = openAndBufferFile( fileToOpen );
	
	// skip the comment section
	while ( fileBuffer[ loopCounter ] == '#' )
	{	
		while ( fileBuffer[ loopCounter++ ] != '\n' )
		{}
	}

	// printf( "%lu\n", loopCounter );
	maxPENumber = getPEs( cgra, fileBuffer, &loopCounter );

	// free the buffer
	free( fileBuffer );

	// return the results
	return maxPENumber;
}

void printCGRA( const CGRA const cgra, size_t cgraSize, char* buffer, int* bufferPosition )
{
	if ( cgraSize == 0 )
	{
		printf("CGRA Print Returned!!!!\n");
		return;
	}

	const ArithmeticPEDescription* description;

	for ( size_t loop = 0; loop <= cgraSize; ++loop )
	{
		description = &cgra[ loop ];

		if ( description->adder.isUsed 
		||	description->multiplier.isUsed
		||	description->subtractor.isUsed )
		{
			*bufferPosition += snprintf( buffer + *bufferPosition, BufferSize - *bufferPosition, "%lu:", loop );
			printArithmeticPEDescription( description, buffer, bufferPosition );	
		}
	}
}
	// "#The descriptions are the same for the adder and subtractor, but different for the multiplier.\n"
	// "#The adder and subtractor are as follows:\n"\
	// "#Approximated bits,approximate type (exact, LP C Lib, Low Power), LP C Library method ( 0 Approx, First Approx, etc).\n"
	// "#The multiplier is as follows: Approximated bits, approximationType, add method, multiply method\n"
	// "#adder:subtractor:multiply\n"
	// "#TODO: FIX PE SIZE\n"
	//  ""8:4,0:16,-1:16,-1,1"" would set PE 8 to the associated settings\n"
void createPEDescriptionFile( const char* fileToOpen, const CGRA cgra, size_t cgraSize )
{
	int bufferPosition = 0;
	static char buffer[ BufferSize ];
	const char* preamble = 
	
	"#For example,\n"
	"Total Number of CGRA_PE:36\n"
	"Default:0,-1,0:0,-1,0:0,-1,-1,-1\n";

	// const char* defaultValue = 
	// "Default:4,2,1:0,-1,0:0,1,-1,-1\n";

	printCGRA( cgra, cgraSize, buffer, &bufferPosition );

	if ( access( fileToOpen, F_OK ) != -1 ) 
	{
		remove( fileToOpen );
	} 
	
	FILE* file = openFile( fileToOpen, "w" );
	fprintf( file, "%s", preamble );
	fprintf( file, "%s", buffer );
	
	fclose( file );
}

void printPEDescriptionFile( const char* fileToOpen )
{
	// init variables
	char* fileBuffer;	
	
	fileBuffer = openAndBufferFile( fileToOpen );
	
	printf("%s", fileBuffer );

	// free the buffer
	free( fileBuffer );
}