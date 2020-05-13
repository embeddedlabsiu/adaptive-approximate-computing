#include "snipmath.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/* The printf's may be removed to isolate just the math calculations */

#include "DynamicCGRAControl.h"

//#define LOOPMAX ( 65536 )
#define LOOPMAX ( 882 )
int main(void)
{
	// int     solutions;
	// unsigned int i;
	// unsigned long l = 0x3fed0169L;
	// struct int_sqrt q;
	// struct int_sqrt w;
	// long n = 0;

	// DynamicCGRAControl dynamic;
	// initDynamicCGRAControl( &dynamic, "ArithmeticPEsList.txt" );
	//printAllLists( &dynamic );
	// dynamicControl( &dynamic );

	#define LOOPMAX ( 200 )

	#define ErrorRate ( 2 )
	// int     solutions;
	unsigned long int i = 0;
	// unsigned long l = 0x3fed0169L;
	struct int_sqrt q;
	struct int_sqrt w;
	// long n = 0;
	// // at the end of this function, call createPEDescriptionFile if the PE's approximation settings change
	// static unsigned counter = 0;
	LinkedList* list;
	Node* node;
	ArithmeticLogicUnitNode* data;
	int bufferPosition = 0;
	char buffer[ 2048 ] = {'\0'};
	int lastLpcApproximationMethod = -1;
	int currentLpcApproximationMethod = -1;

	bool shouldCreateNewFile = false;

	FILE *fp;
	fp = fopen("test.csv", "w");
	fprintf(fp, "!!Operation,Result,Actual,Error\n");
	
	for (i = 0; i <= 65529; i += 81)
	{
		// list = dynamic.subtractorList;
		// node = list->head;

		// while ( node != NULL )
		// {
		// 	data = (ArithmeticLogicUnitNode*)node->data;
		// 	data->desc->approximationType = 0;
		// 	data->desc->approximatedNumberOfBits = 4;
		// 	// data->desc->lpcApproximationMethod = getApproximateMethod( i, 4, ErrorRate );
		// 	currentLpcApproximationMethod = getApproximateMethod( i, 16, ErrorRate );
		// 	if ( lastLpcApproximationMethod != currentLpcApproximationMethod )
		// 	{
		// 		// this only works with one item in the list!
		// 		data->desc->lpcApproximationMethod = currentLpcApproximationMethod;
		// 		lastLpcApproximationMethod = currentLpcApproximationMethod;
		// 		shouldCreateNewFile = true;
		// 	}
			
		// 	node = node->next;
		// }


		// // createPEDescriptionFile( "./CGRA_PE_Description.txt", dynamicCGRAControl->cgra, dynamicCGRAControl->cgraSize );	
		// if ( shouldCreateNewFile == true )
		// {
		// 	// printf("CREATED FILE\n");
		// 	shouldCreateNewFile = false;
		// 	//createPEDescriptionFile( "./CGRA_PE_Description.txt", dynamic.cgra, dynamic.cgraSize );	
		// }
		
		
		//printPEDescriptionFile("./CGRA_PE_Description.txt" );

		//usleep( 1000000 );
		usqrt(i, &w);
		CGRA_usqrt(i, &q);
		// remainder differs on some machines
	
		double result = (((double)(q.sqrt))/65536.0);
		double actual = (((double)(w.sqrt))/65536.0);

		// printf("val %lu approx %i\n", i, currentLpcApproximationMethod );

		
		fprintf(fp, "sqrt(%d),%lf,%lf,%lf\n",i,result,actual, fabs( result-actual) / actual );	
	}

	fclose(fp);
	
// 	printAllLists( &dynamic );
// FILE *fp;
// 	fp = fopen("test.csv", "w");
// 	fprintf(fp, "Operation,Result,Actual,Error\n");


//     //dynamicControl( &dynamic, 0 );	
// 	/* perform some integer square roots */

// 	// at the end of this function, call createPEDescriptionFile if the PE's approximation settings change
// 	static unsigned counter = 0;


// 	for (i = 0; i < LOOPMAX; i+=81)
// 	{
// 		usqrt(i, &w);
// 		CGRA_usqrt(i, &q);
//     	// remainder differs on some machines
// 		// printf("sqrt(%3d) = %2d, remainder = %2d\n",
// 		float result = (((float)(q.sqrt))/65536.0);
// 		float actual = (((float)(w.sqrt))/65536.0);
		
// 		// dynamicControl( &dynamic, result - actual );	
// 		fprintf(fp, "sqrt(%d),%f,%f,%f\n",i,result,actual,result-actual),
// 		printf("sqrt(%3d) = %2f | Expected = %2f\n",i, result, actual);
		
// 	}	
// 	fclose(fp);
	// freeDynamicCGRAControl( &dynamic );
	return 0;
}
