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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"
#include "sobel.h"
#include "file_operations.h"
#include "snipmath.h"
#define ARGS_NEEDED 4

int main(int argc, char *argv[]) {

    // unsigned long product = 0;


    // product = multiply( 2, 144 );

    // printf( "%lu\n", product );
    char *fi, *file_in,
         *file_out,
         *file_out_h ,
         *file_out_v,
         *file_gray;

    byte *rgb,
         *gray,
         *sobel_h_res,
         *sobel_v_res,
         *contour_img;

    int rgb_size,
        width,
        height;
    int inter_files = 0,
        gray_file = 0;

    // Get arguments
    // if(argc < ARGS_NEEDED) {
    //     printf("Usage: TODO\n");
    //     return 1;
    // }

    file_in = "../imgs/img.rgb";
    file_out = "img_out.gray";

    width = 512;
    height = 512;

    
    rgb_size = width*height*3;

    // Get optional arguments
    int arg_index = ARGS_NEEDED;
    printf("STARTED\n");
    // Read file to rgb and get size
    readFile(file_in, &rgb, rgb_size);
    printf("read file\n");
    int gray_size = sobelFilter(rgb, &gray, &sobel_h_res, &sobel_v_res, &contour_img, width, height);

    printf("sobeled it\n");
    // Write gray image

    if(gray_file) {
        writeFile(file_gray, gray, gray_size);
    }

    // Write image after each sobel operator
    if(inter_files) {
        writeFile(file_out_h, sobel_h_res, gray_size);
        writeFile(file_out_v, sobel_v_res, gray_size);
    }

    // Write sobel img to a file
    writeFile(file_out, contour_img, gray_size);

    return 0;
}

