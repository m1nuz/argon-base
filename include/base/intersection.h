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
#pragma once

#include "base/math_ext.h"

// Axis-Aligned Bounding Box
typedef struct AxisAlignedBoundingBox
{
    float3 min;
    float3 max;
} AABB;

// Oriented Bounding Box
typedef struct OrientedBoundingBox
{
    float3 position;
    float3 size;
    float3 axis[3];
} OBB;

// Bounding Sphere
typedef struct BoundingSphere
{
    float3 position;
    float  radius;
} BSPHR;

int intersect_aabb(const AABB * restrict a, const AABB * restrict b);
int intersect_aabb_sphere(const AABB * restrict bb, const BSPHR * restrict sphere);
void transform_aabb(const AABB * restrict a, const float * restrict m, const float *t, AABB * restrict b);

void make_oob_from_aabb(OBB *obb, const AABB *aabb);
int intersect_obb(const OBB *obb0, const OBB *obb1);
