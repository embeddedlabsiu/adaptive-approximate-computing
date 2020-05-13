#include "snipmath.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/* The printf's may be removed to isolate just the math calculations */

#include "../../../../../ApproximateComputing/DynamicRuntimeCGRAControl/DynamicCGRAControl.h"

//#define LOOPMAX ( 65536 )
#define LOOPMAX ( 882 )
int main(void)
{
	int     solutions;
	unsigned int i;
	unsigned long l = 0x3fed0169L;
	struct int_sqrt q;
	struct int_sqrt w;
	long n = 0;

	DynamicCGRAControl dynamic;
	initDynamicCGRAControl( &dynamic, "CGRAExec/L2/ArithmeticPEsList.txt" );

	printAllLists( &dynamic );

	FILE *fp;
	fp = fopen("test.csv", "w");
	fprintf(fp, "Operation,Result,Actual,Error\n");

    //dynamicControl( &dynamic, 0 );	
	/* perform some integer square roots */
	for (i = 0; i < LOOPMAX; i+=81)
	{
		usqrt(i, &w);
		CGRA_usqrt(i, &q);
    	// remainder differs on some machines
		// printf("sqrt(%3d) = %2d, remainder = %2d\n",
		float result = (((float)(q.sqrt))/65536.0);
		float actual = (((float)(w.sqrt))/65536.0);
		
		// dynamicControl( &dynamic, result - actual );	
		
		fprintf(fp, "sqrt(%d),%f,%f,%f\n",i,result,actual,result-actual),
		printf("sqrt(%3d) = %2f | Expected = %2f\n",i, result, actual);
	}
//	printAllLists( &dynamic );
	fclose(fp);

	return 0;
}



/*
#define TOP2BITS(x) ( (x & (3L << (32-2))) >> (32-2))
//#define LOOPMAX ( 65536 )
#define LOOPMAX ( 2000 )
int main(void)
{
	int     solutions;
	unsigned int i;
	unsigned long l = 0x3fed0169L;
	struct int_sqrt q;
	struct int_sqrt w;
	long n = 0;

	//DynamicCGRAControl dynamic;
	//initDynamicCGRAControl( &dynamic, "CGRAExec/L2/ArithmeticPEsList.txt" );

	//printAllLists( &dynamic );

	printf("********* INTEGER SQR ROOTS ***********\n");

	FILE *fp;
	fp = fopen("test.csv", "w");
	fprintf(fp, "Operation,Result,Actual,Error\n");

      unsigned long a = 0L;                 
      unsigned long r = 0L;                   
      unsigned long e = 0L;                   
	  int z;
	  unsigned long p;
	 perform some integer square roots 
	for (i = 0; i < LOOPMAX; i+=81)
	{
		p = i;
		usqrt(i, &w);
		//CGRA_usqrt(i, &q);
      #pragma CGRA
      for (z = 0; z < 32; z++)   
      {
            //temp = ( r - 2 ) + i;
            //temp = (r << 2) + TOP2BITS(x); x <<= 2;  // Approximate
            // r = temp - (temp%2); // set the last bit to zero as approximation
            r = ( (r << 2) + TOP2BITS(p) ); p <<= 2; // Original
            a <<= 1;
            e = (a << 1) + 1;
	      if (r >= e)
            {
                  r -= e;
                  a++;
            }
      }
	   memcpy(&q, &a, sizeof(long));

 		 a = 0L;                   
      r = 0L;                  
       e = 0L;                   
		// remainder differs on some machines
		// printf("sqrt(%3d) = %2d, remainder = %2d\n",
		float result = (((float)(q.sqrt))/65536.0);
		float actual = (((float)(w.sqrt))/65536.0);
		
		//dynamicControl( &dynamic, result - actual );	
		
		fprintf(fp, "sqrt(%d),%f,%f,%f\n",i,result,actual,result-actual),
		printf("sqrt(%3d) = %2f | Expected = %2f\n",i, result, actual);
	}
	//printAllLists( &dynamic );
	fclose(fp);

	return 0;
}*/
