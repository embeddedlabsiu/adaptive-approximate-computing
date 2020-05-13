/* +++Date last modified: 05-Jul-1997 */

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
int CGRA_usqrt(unsigned long x, struct int_sqrt *q, int approximateBits, int desiredTolerance, unsigned arrayIndex )
{
      unsigned long a = 0L;                   /* accumulator      */
      unsigned long r = 0L;                   /* remainder        */
      unsigned long e = 0L;                   /* trial product    */

      int i;
      // size_t arrayIndex = x - 1;// account for zero offset ( square root of 1 should look at index 0 of the array)
      int approxMethod;
      // printf("input!! %lu\n", x );

      if ( approximateBits == 4 ) 
      {
            approxMethod = lookupTable4[ arrayIndex ][0];
            if ( lookupTable4[ arrayIndex ][ 1 ] >= desiredTolerance && desiredTolerance != -1 )
            {
                  approxMethod = -1;
            }
      }
      else if ( approximateBits == 8 ) 
      {
            approxMethod = lookupTable8[ arrayIndex ][0];
            if ( lookupTable8[ arrayIndex ][ 1 ] >= desiredTolerance && desiredTolerance != -1 )
            {
                  approxMethod = -1;
            }
      }
      else if ( approximateBits == 12 ) 
      {
            approxMethod = lookupTable12[ arrayIndex ][0];
            if ( lookupTable12[ arrayIndex ][ 1 ] >= desiredTolerance && desiredTolerance != -1 )
            {
                  approxMethod = -1;
            }
      }
      else if ( approximateBits == 16 ) 
      {
            approxMethod = lookupTable16[ arrayIndex ][0];
            if ( lookupTable16[ arrayIndex ][ 1 ] >= desiredTolerance && desiredTolerance != -1 )
            {
                  approxMethod = -1;
            }

            // printf( "input %i, error %i, tolerance %i\n", x, lookupTable16[ arrayIndex ][ 1 ], desiredTolerance );
      }

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


void usqrt(unsigned long x, struct int_sqrt *q)
{
      unsigned long a = 0L;                   /* accumulator      */
      unsigned long r = 0L;                   /* remainder        */
      unsigned long e = 0L;                   /* trial product    */

  
      int i;
      for (i = 0; i < BITSPERLONG; i++)   /* NOTE 1 */
      {
            //temp = r*5;
            //temp = (r << 2) + TOP2BITS(x); x <<= 2;  // Approximate
            // r = temp - (temp%2); // set the last bit to zero as approximation
            r = (r << 2) + TOP2BITS(x); x <<= 2; // Original
            a <<= 1;
            e = (a << 1) + 1;
            if (r >= e)
            {
                  r -= e;
                  a++;
            }
      }
      
      memcpy(q, &a, sizeof(long));
}

#ifdef TEST

#include <stdio.h>
#include <stdlib.h>

main(void)
{
      int i;
      unsigned long l = 0x3fed0169L;
      struct int_sqrt q;

      for (i = 0; i < 101; ++i)
      {
            usqrt(i, &q);
            printf("sqrt(%3d) = %2d, remainder = %2d\n",
                  i, q.sqrt, q.frac);
      }
      usqrt(l, &q);
      printf("\nsqrt(%lX) = %X, remainder = %X\n", l, q.sqrt, q.frac);
      return 0;
}

#endif /* TEST */
