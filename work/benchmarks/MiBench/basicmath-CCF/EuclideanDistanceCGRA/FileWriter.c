#define _GNU_SOURCE
#include "FileWriter.h"


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


#include <pthread.h>
static int globalLPC = 0;


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

void createPEDescriptionFile( const char* fileToOpen, int approximatedBits, int lpcMethod, int* fd, struct flock* lock )
{
	// if ( lpcMethod == globalLPC )
	// {
	// 	return;
	// }

	// globalLPC = lpcMethod;
    // #define BufferSize ( 2048 )
	// static char buffer[ BufferSize ] = {'\0'};
	// int subtractorType = -1;
	// int length;

	// if ( lpcMethod != -1 )
	// {
	// 	subtractorType = 0;
	// }

	// const char* preamble = 
	
	// "#For example1111,\n"
	// "Total Number of CGRA_PE:36\n"
	// "Default:0,-1,0:0,-1,0:0,-1,-1,-1\n";

	// // const char* defaultValue = 
	// // "Default:4,2,1:0,-1,0:0,1,-1,-1\n";

	// lpcMethod = lpcMethod == -1 ? 0 : lpcMethod;
	// length = snprintf( buffer, BufferSize, "%s2:-1,-1,0:%i,%i,%i:-1,-1,-1,-1", preamble, approximatedBits, subtractorType, lpcMethod );
	// // printf("%s\n", buffer );

	// // if ( access( fileToOpen, F_OK ) != -1 ) 
	// // {
	// //     remove( fileToOpen );
	// // } 
	
	// lock->l_type = F_RDLCK;
    // // fcntl( *fd, F_OFD_SETLKW, lock );
 	// write( *fd, buffer, length );
	
	// fsync (fd);

    // lock->l_type = F_UNLCK;
    // // fcntl( *fd, F_OFD_SETLK, lock );


	// usleep( 1000000 );
}

