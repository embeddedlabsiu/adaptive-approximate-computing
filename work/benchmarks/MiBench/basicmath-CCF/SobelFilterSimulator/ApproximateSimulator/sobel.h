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

#ifndef SOBEL_H
#define SOBEL_H

#include "macros.h"

int  sobelFilter (byte *rgb, byte **gray, byte **sobel_h_res, byte **sobel_v_res, byte **contour_img, int width, int height, int approximateBits, int tolerance );

struct Pair
{
	double value;
	double error;

	Pair();

};

struct Results
{
	Pair zeroApproximation;
	Pair firstApproximation;
	Pair thirdApproximation;

	void print();
};

#endif

