/*
 * Copyright 2018 Pedro Melgueira
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "sobel.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

#include "macros.h"

#include "snipmath.h"
/*
 * Transforms the rgb information of an image stored in buffer to it's gray
 * representation
 */

int rgbToGray(byte *rgb, byte **gray, int buffer_size) {
    // Take size for gray image and allocate memory
    int gray_size = buffer_size / 3;
    *gray = (byte*)malloc(sizeof(byte) * gray_size);

    // Make pointers for iteration
    byte *p_rgb = rgb;
    byte *p_gray = *gray;

    // Calculate the value for every pixel in gray
    for(int i=0; i<gray_size; i++) {
        *p_gray = 0.30*p_rgb[0] + 0.59*p_rgb[1] + 0.11*p_rgb[2];
        
        p_rgb += 3;
        p_gray++;
    }

    return gray_size;
}

/*
 * Make the operation memory for iterative convolution
 */

void makeOpMem(byte *buffer, int buffer_size, int width, int cindex, byte *op_mem) {
    int bottom = cindex-width < 0;
    int top = cindex+width >= buffer_size;
    int left = cindex % width == 0;
    int right = (cindex+1) % width == 0;

    op_mem[0] = !bottom && !left  ? buffer[cindex-width-1] : 0;
    op_mem[1] = !bottom           ? buffer[cindex-width]   : 0;
    op_mem[2] = !bottom && !right ? buffer[cindex-width+1] : 0;

    op_mem[3] = !left             ? buffer[cindex-1]       : 0;
    op_mem[4] = buffer[cindex];
    op_mem[5] = !right            ? buffer[cindex+1]       : 0;

    op_mem[6] = !top && !left     ? buffer[cindex+width-1] : 0;
    op_mem[7] = !top              ? buffer[cindex+width]   : 0;
    op_mem[8] = !top && !right    ? buffer[cindex+width+1] : 0;
}

/*
 * Performs convolution between first two arguments
 */

int convolution( byte *X, int *Y, int c_size, int approximateBits, int approximateMethod ) 
{
    int sum = 0;

    for(int i=0; i<c_size; i++) 
    {
        sum += X[i] * Y[c_size-i-1];
    }

    return sum;
}

/*
 * Iterate Convolution
 */

void itConv(byte *buffer, int buffer_size, int width, int *op, byte **res, int approximateBits, int approximateMethod ) 
{
    
    // Allocate memory for result
    *res = (byte*)malloc(sizeof(byte) * buffer_size);

    // Temporary memory for each pixel operation
    byte op_mem[SOBEL_OP_SIZE];
    memset(op_mem, 0, SOBEL_OP_SIZE);
    // printf("Buffer = %i\n", buffer_size );

    // Make convolution for every pixel
    for(int i=0; i<buffer_size; i++) 
    {
        // Make op_mem
        makeOpMem(buffer, buffer_size, width, i, op_mem);
        
        // Convolution
        (*res)[i] = (byte) abs(convolution( op_mem, op, SOBEL_OP_SIZE, approximateBits, -1 ) );
        /*
         * The abs function is used in here to avoid storing negative numbers
         * in a byte data type array. It wouldn't make a different if the negative
         * value was to be stored because the next time it is used the value is
         * squared.
         */
     
    }
}

/*
 * Contour
 */

void contour(byte *sobel_h, byte *sobel_v, int gray_size, byte **contour_img, int approximateBits, int tolerance ) 
{
    static unsigned counter = 0;
    // Allocate memory for contour_img
    *contour_img = (byte*)malloc(sizeof(byte) * gray_size);
    int_sqrt squareRoot;
    int approximateMethod;
    float actualResult;
    float approxResult;


    // Iterate through every pixel to calculate the contour image
    for(int i=0; i<gray_size; i++) 
    {
        
        approximateMethod = CGRA_usqrt( ( sobel_h[i] * sobel_h[i] ) + ( sobel_v[i] * sobel_v[i] ), &squareRoot, counter, approximateBits, tolerance );
        approxResult = (byte)( (double)(squareRoot.sqrt)/65536.0 );

        CGRA_usqrt( ( sobel_h[i] * sobel_h[i] ) + ( sobel_v[i] * sobel_v[i] ), &squareRoot, counter, approximateBits, -1 );
        actualResult = (byte)( (double)(squareRoot.sqrt)/65536.0 );

        // printf("%i, %u, %i, %f, %f\n", approximateBits, counter, approximateMethod, actualResult, approxResult );
        // (*contour_img)[i] = (byte) sqrt(pow(sobel_h[i], 2) + pow(sobel_v[i], 2));
        
        // CGRA_usqrt( ( sobel_h[i] * sobel_h[i] ) + ( sobel_v[i] * sobel_v[i] ), &squareRoot, approximateBits, counter %2 == 0 ? approximateMethod : -1 );
        // printf("%u, ", (byte)( (double)(squareRoot.sqrt)/65536.0 ) );
        
        // CGRA_usqrt( ( sobel_h[i] * sobel_h[i] ) + ( sobel_v[i] * sobel_v[i] ), &squareRoot, approximateBits, 0 );
        // printf("%u, ", (byte)( (double)(squareRoot.sqrt)/65536.0 ) );

        // CGRA_usqrt( ( sobel_h[i] * sobel_h[i] ) + ( sobel_v[i] * sobel_v[i] ), &squareRoot, approximateBits, 1 );
        // printf("%u, ", (byte)( (double)(squareRoot.sqrt)/65536.0 ) );

        // CGRA_usqrt( ( sobel_h[i] * sobel_h[i] ) + ( sobel_v[i] * sobel_v[i] ), &squareRoot, approximateBits, 3 );
        // printf("%u\n", (byte)( (double)(squareRoot.sqrt)/65536.0 ) );
        ++counter;

        (*contour_img)[i] = approxResult;
    }
}


float percentError( byte actual, byte approx )
{
    float percentError = actual == 0 ? 0 : std::abs( ( (double)(abs(actual-approx)) / (double)actual ) ) * 100;

    if ( percentError < 0 )
    {
        percentError *= -1;
    }

    if ( percentError > 100 )
    {
        percentError = 100.0;
    }

    return percentError;
}
int sobelFilter(byte *rgb, byte **gray, byte **sobel_h_res, byte **sobel_v_res, byte **contour_img, int width, int height, int approximateBits, int tolerance ) 
{
    int sobel_h[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1},
        sobel_v[] = {1, 2, 1, 0, 0, 0, -1, -2, -1};

    int rgb_size = width*height*3;

    // Get gray representation of the image
    int gray_size = rgbToGray(rgb, gray, rgb_size);
    // printf("N, X, Approx_Method, Actual, Approx\n");
    
    // Make sobel operations
    itConv( *gray, gray_size, width, sobel_h, sobel_h_res, approximateBits, 0 );
    itConv( *gray, gray_size, width, sobel_v, sobel_v_res, approximateBits, 0 );

    // Calculate contour matrix
    contour( *sobel_h_res, *sobel_v_res, gray_size, contour_img, approximateBits, tolerance );
    
    // for ( int i =0; i < gray_size; ++i )
    // {
    //     byte exact = exactCountourImage[ i ];
    //     printf("%i, %i, %u, %u, %u, %u\n", approximateBits, i
    //     , exact
    //     , zeroCountourImage[ i ] 
    //     , firstCountourImage[ i ] 
    //     , thirdCountourImage[ i ] ); 
    // }

    return gray_size;
}

Pair::Pair()
	: value( 0 )
	, error( 0 )
	{}


void Results::print()
{
    printf("%lf, %lf, %lf"
    , zeroApproximation.error
    , firstApproximation.error
    , thirdApproximation.error );
}