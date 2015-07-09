/*
 * Copyright (c) 2015 Poddubny Michael
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#include "base/math_ext.h"

extern void
randv3(float *v) {
    // Pick a random Z between -1.0f and 1.0f
    float vz = randf_minmax(-1.0, 1.0);

    // Get radius of this circle
    const float radius = (float)sqrt(1 - vz * vz);

    // Pick a random point on a circle
    const float t = randf_minmax(-M_PI, M_PI);

    // Compute matching X and Y for our Z.
    float vx = (float)cosf(t) * radius;
    float vy = (float)sinf(t) * radius;

    v[0] = vx;
    v[1] = vy;
    v[2] = vz;
}

extern void
randv3_minmax(float *v, float *min_value, float *max_value) {
    v[0] = LERP(randf(), min_value[0], max_value[0]);
    v[1] = LERP(randf(), min_value[1], max_value[1]);
    v[2] = LERP(randf(), min_value[2], max_value[2]);
}

