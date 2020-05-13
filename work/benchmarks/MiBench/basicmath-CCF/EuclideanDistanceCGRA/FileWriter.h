/* +++Date last modified: 05-Jul-1997 */

#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <fcntl.h>

inline void createPEDescriptionFile( const char* fileToOpen, int approximatedBits, int lpcMethod, int* fd, struct flock* lock );

#endif /* FILEWRITER_H */
