#include <string.h>
#include "snipmath.h"

#include "ApproximateComputing.h"
#include "ApproximateBitsEquals4LookupTable.h"
#include "ApproximateBitsEquals8LookupTable.h"
#include "ApproximateBitsEquals12LookupTable.h" 
#include "ApproximateBitsEquals16LookupTable.h"
#include <stdio.h>
#define BITSPERLONG 32

#define TOP2BITS(x) ( (x & (3L << (BITSPERLONG-2))) >> (BITSPERLONG-2))
using namespace ApproximateComputing;
/* usqrt:
    ENTRY x: unsigned long
    EXIT  returns floor(sqrt(x) * pow(2, BITSPERLONG/2))

    Since the square root never uses more than half the bits
    of the input, we use the other half of the bits to contain
    extra bits of precision after the binary point.

    EXAMPLE
        suppose BITSPERLONG = 32
        then    usqrt(144) = 786432 = 12 * 65536
                usqrt(32) = 370727 = 5.66 * 65536

    NOTES
        (1) change BITSPERLONG to BITSPERLONG/2 if you do not want
            the answer scaled.  Indeed, if you want n bits of
            precision after the binary point, use BITSPERLONG/2+n.
            The code assumes that BITSPERLONG is even.
        (2) This is really better off being written in assembly.
            The line marked below is really a "arithmetic shift left"
            on the double-long value with r in the upper half
            and x in the lower half.  This operation is typically
            expressible in only one or two assembly instructions.
        (3) Unrolling this loop is probably not a bad idea.

    ALGORITHM
        The calculations are the base-two analogue of the square
        root algorithm we all learned in grammar school.  Since we're
        in base 2, there is only one nontrivial trial multiplier.

        Notice that absolutely no multiplications or divisions are performed.
        This means it'll be fast on a wide range of processors.
*/
// addition( unsigned int input_a, unsigned int input_b, int approxBits, AdderTypes::Enum adderTypes, LPCLibraryMethod::Enum lpcApproximationMethod );
int CGRA_usqrt(unsigned long x, struct int_sqrt *q, int counter, int approximateBits, int desiredTolerance )
{
      unsigned long a = 0L;                   /* accumulator      */
      unsigned long r = 0L;                   /* remainder        */
      unsigned long e = 0L;                   /* trial product    */

      int i;
      int approxMethod = -1;

      if ( desiredTolerance != -1 )
      {
            if ( approximateBits == 4 ) 
            {
                  approxMethod = lookupTable4[ counter ][0];
                  if ( lookupTable4[ counter ][ 1 ] >= desiredTolerance )
                  {
                        approxMethod = -1;
                  }
                  // printf("des %i act %i method %i\n", desiredTolerance,lookupTable4[ counter ][ 1 ], approxMethod );
            }
            else if ( approximateBits == 8 ) 
            {
                  approxMethod = lookupTable8[ counter ][0];
                  if ( lookupTable8[ counter ][ 1 ] >= desiredTolerance )
                  {
                        approxMethod = -1;
                  }
            }
            else if ( approximateBits == 12 ) 
            {
                  approxMethod = lookupTable12[ counter ][0];
                  if ( lookupTable12[ counter ][ 1 ] >= desiredTolerance )
                  {
                        approxMethod = -1;
                  }
            }
            else if ( approximateBits == 16 ) 
            {
                  approxMethod = lookupTable16[ counter ][0];
            
                  if ( lookupTable16[ counter ][ 1 ] >= desiredTolerance )
                  {
                        approxMethod = -1;
                  }
            }
      }

      //  printf("%i, %i, %i\n", lookupTable12[ arrayIndex ][ 1 ] , desiredTolerance, approxMethod  );
      for (i = 0; i < BITSPERLONG; i++)   /* NOTE 1 */
      {
            r = (r << 2) + TOP2BITS(x);
             x <<= 2; // Original
            a <<= 1;
            e = (a << 1 ) + 1;
            if (r >= e)
            {
                  r = HardwareDescription::subtraction( r , e, approximateBits, (HardwareDescription::SubtractorTypes::Enum) 0, (HardwareDescription::LPCLibraryMethod::Enum)approxMethod );
                  a++;
            }
      }
      
      memcpy(q, &a, sizeof(long));
      return approxMethod;
}

