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

#include <stdlib.h>
#include <math.h>

#define FLT_EPSILON 0.000001

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(v) ((v) < 0 ? -(v) : (v))
#define SIGN(t) ((t) < 0 ? -1 : (t) > 0 ? 1 : 0)
#define CLAMP(t, lo, hi) ((t) < (lo) ? (lo) : (t) > (hi) ? (hi) : (t))
#define LERP(t, a, b) ((a) + ((b) - (a)) * (t))
#define MIX(a, b, f) ((a) * (f) + (b) * (1 - (f)))
#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))
#define MINMIN(a, b, c) ((a) < (b) ? MIN(a, c) : MIN(b, c))
#define MAXMAX(a, b, c) ((a) > (b) ? MAX(a, c) : MAX(b, c))

#define RADIANS(x) ((x) * (M_PI / 180.0))
#define DEGREES(x) ((x) * (180.0 / M_PI))

#define randf() (rand() / (float)RAND_MAX)
#define randf_minmax(min_value, max_value) (min_value + (max_value - min_value) * randf())

#define M_FLOAT_TYPE float

// TODO: rework for vec types
// vector2
#define make_vector2(v, x, y) (((M_FLOAT_TYPE*)&(v))[0] = (x), ((M_FLOAT_TYPE*)&(v))[1] = (y))
#define copy_vector2(v, a) ((v)[0] = (a)[0], (v)[1] = (a)[1])
// Addition, subtraction, multiplication, division (by a vector element)
#define inc_vector2(v, a) \
    ((v)[0] += (a)[0],\
    (v)[1] += (a)[1])
#define dec_vector2(v, a)\
    ((v)[0] -= (a)[0],\
    (v)[1] -= (a)[1])
#define add_vector2(v, a, b)\
    ((v)[0] = (a)[0] + (b)[0],\
    (v)[1] = (a)[1] + (b)[1])
#define sub_vector2(v, a, b)\
    ((v)[0] = (a)[0] - (b)[0],\
    (v)[1] = (a)[1] - (b)[1])
#define mul_vector2(v, a, b)\
    ((v)[0] = (a)[0] * (b)[0],\
    (v)[1] = (a)[1] * (b)[1])
#define div_vector2(v, a, b)\
    ((v)[0] = (a)[0] / (b)[0],\
    (v)[1] = (a)[1] / (b)[1])

#define delta_vector2(a, b)\
        ((a)[0] * (b)[1] - (a)[1] * (b)[0])

#define dot_vector2(a, b)\
        ((a)[0] * (b)[0] + (a)[1] * (b)[1])

#define length_vector2(a)\
        (sqrt(dot_vector2(a, a)))

#define normalize_vector2(v) do { \
    float len = length_vector2(v); \
    len = len == 0 ? 1.f : len; \
    (v)[0] /= len;\
    (v)[1] /= len;\
    } while(0)

// vector3
// Creation, duplication
#define make_vector3(v, x, y, z) ((v)[0] = (x), (v)[1] = (y), (v)[2] = (z))
#define copy_vector3(v, a) ((v)[0] = (a)[0], (v)[1] = (a)[1], (v)[2] = (a)[2])
#define swap_vector3(a, b, t) (SWAP((a)[0], (b)[0], (t)), SWAP((a)[1], (b)[1], (t)), SWAP((a)[2], (b)[2], (t)))
// Addition, subtraction, multiplication, division (by a vector element)
#define inc_vector3(v, a) \
    ((v)[0] += (a)[0],\
    (v)[1] += (a)[1],\
    (v)[2] += (a)[2])
#define dec_vector3(v, a)\
    ((v)[0] -= (a)[0],\
    (v)[1] -= (a)[1],\
    (v)[2] -= (a)[2])
#define add_vector3(v, a, b)\
    ((v)[0] = (a)[0] + (b)[0],\
    (v)[1] = (a)[1] + (b)[1],\
    (v)[2] = (a)[2] + (b)[2])
#define sub_vector3(v, a, b)\
    ((v)[0] = (a)[0] - (b)[0],\
    (v)[1] = (a)[1] - (b)[1],\
    (v)[2] = (a)[2] - (b)[2])
#define mul_vector3(v, a, b)\
    ((v)[0] = (a)[0] * (b)[0],\
    (v)[1] = (a)[1] * (b)[1],\
    (v)[2] = (a)[2] * (b)[2])
#define div_vector3(v, a, b)\
    ((v)[0] = (a)[0] / (b)[0],\
    (v)[1] = (a)[1] / (b)[1],\
    (v)[2] = (a)[2] / (b)[2])
// Addition, subtraction, multiplication, division (by a scalar element)
#define incs_vector3(v, s)\
    ((v)[0] += (s),\
    (v)[1] += (s),\
    (v)[2] += (s))
#define decs_vector3(v, s)\
    ((v)[0] -= (s),\
    (v)[1] -= (s),\
    (v)[2] -= (s))
#define adds_vector3(v, a, s)\
    ((v)[0] = (a)[0] + (s),\
    (v)[1] = (a)[1] + (s),\
    (v)[2] = (a)[2] + (s))
#define subs_vector3(v, a, s)\
    ((v)[0] = (a)[0] - (s),\
    (v)[1] = (a)[1] - (s),\
    (v)[2] = (a)[2] - (s))
#define muls_vector3(v, a, s)\
    ((v)[0] = (a)[0] * (s),\
    (v)[1] = (a)[1] * (s),\
    (v)[2] = (a)[2] * (s))
#define divs_vector3(v, a, s)\
    ((v)[0] = (a)[0] / (s),\
    (v)[1] = (a)[1] / (s),\
    (v)[2] = (a)[2] / (s))
// Linear interpolation
#define lerp_vector3(v, t, a, b)\
    ((v)[0] = LERP((t), (a)[0], (b)[0]),\
    (v)[1] = LERP((t), (a)[1], (b)[1]),\
    (v)[2] = LERP((t), (a)[2], (b)[2]))
#define mix_vector3(v, a, b, f)\
    ((v)[0] = MIX((a)[0], (b)[0], (f)),\
    (v)[1] = MIX((a)[1], (b)[1], (f)),\
    (v)[2] = MIX((a)[2], (b)[2], (f)))
// Cross product, determinant, dot product, length, normalization
#define cross_vector3(v, a, b)\
    ((v)[0] = (a)[1] * (b)[2] - (a)[2] * (b)[1],\
    (v)[1] = (a)[2] * (b)[0] - (a)[0] * (b)[2],\
    (v)[2] = (a)[0] * (b)[1] - (a)[1] * (b)[0])
#define delta_vector3(a, b, c)\
        ((a)[0] * ((b)[1] * (c)[2] - (b)[2] * (c)[1])\
        +(a)[1] * ((b)[2] * (c)[0] - (b)[0] * (c)[2])\
        +(a)[2] * ((b)[0] * (c)[1] - (b)[1] * (c)[0]))
#define dot_vector3(a, b) ((a)[0] * (b)[0] + (a)[1] * (b)[1] + (a)[2] * (b)[2])
#define length_vector3(a) (sqrtf(dot_vector3(a, a)))
#define normalize_vector3(v) do {\
    float invlen = 1.f / length_vector3(v);\
    (v)[0] *= invlen;\
    (v)[1] *= invlen;\
    (v)[2] *= invlen;\
    } while(0)
//
#define distance_vector3(a, b)\
    (sqrt(((a)[0] - (b)[0]) * ((a)[0] - (b)[0]) +\
    ((a)[1] - (b)[1]) * ((a)[1] - (b)[1]) +\
    ((a)[2] - (b)[2]) * ((a)[2] - (b)[2])))
// min, max
#define min_vector3(v, a, b)\
    ((v)[0] = MIN((a)[0], (b)[0]),\
    (v)[1] = MIN((a)[1], (b)[1]),\
    (v)[2] = MIN((a)[2], (b)[2]))
#define max_vector3(v, a, b)\
    ((v)[0] = MAX((a)[0], (b)[0]),\
    (v)[1] = MAX((a)[1], (b)[1]),\
    (v)[2] = MAX((a)[2], (b)[2]))
// vector4
// Creation, duplication
#define make_vector4(v, x, y, z, w) ((v)[0] = (x), (v)[1] = (y), (v)[2] = (z), (v)[3] = (w))
#define copy_vector4(v, a) ((v)[0] = (a)[0], (v)[1] = (a)[1], (v)[2] = (a)[2], (v)[3] = (a)[3])
// Addition, subtraction, multiplication, division (by a vector element)
#define inc_vector4(v, a) \
    ((v)[0] += (a)[0],\
    (v)[1] += (a)[1],\
    (v)[2] += (a)[2],\
    (v)[3] += (a)[3])
#define dec_vector4(v, a)\
    ((v)[0] -= (a)[0],\
    (v)[1] -= (a)[1],\
    (v)[2] -= (a)[2],\
    (v)[3] -= (a)[3])
#define add_vector4(v, a, b)\
    ((v)[0] = (a)[0] + (b)[0],\
    (v)[1] = (a)[1] + (b)[1],\
    (v)[2] = (a)[2] + (b)[2],\
    (v)[3] = (a)[3] + (b)[3])
#define sub_vector4(v, a, b)\
    ((v)[0] = (a)[0] - (b)[0],\
    (v)[1] = (a)[1] - (b)[1],\
    (v)[2] = (a)[2] - (b)[2],\
    (v)[3] = (a)[3] - (b)[3])
#define mul_vector4(v, a, b)\
    ((v)[0] = (a)[0] * (b)[0],\
    (v)[1] = (a)[1] * (b)[1],\
    (v)[2] = (a)[2] * (b)[2],\
    (v)[3] = (a)[3] * (b)[3])
#define div_vector4(v, a, b)\
    ((v)[0] = (a)[0] / (b)[0],\
    (v)[1] = (a)[1] / (b)[1],\
    (v)[2] = (a)[2] / (b)[2],\
    (v)[3] = (a)[3] / (b)[3])
// Addition, subtraction, multiplication, division (by a scalar element)
#define incs_vector4(v, s)\
    ((v)[0] += (s),\
    (v)[1] += (s),\
    (v)[2] += (s),\
    (v)[3] += (s))
#define decs_vector4(v, s)\
    ((v)[0] -= (s),\
    (v)[1] -= (s),\
    (v)[2] -= (s),\
    (v)[3] -= (s))
#define adds_vector4(v, a, s)\
    ((v)[0] = (a)[0] + (s),\
    (v)[1] = (a)[1] + (s),\
    (v)[2] = (a)[2] + (s),\
    (v)[3] = (a)[3] + (s))
#define subs_vector4(v, a, s)\
    ((v)[0] = (a)[0] - (s),\
    (v)[1] = (a)[1] - (s),\
    (v)[2] = (a)[2] - (s),\
    (v)[3] = (a)[3] - (s))
#define muls_vector4(v, a, s)\
    ((v)[0] = (a)[0] * (s),\
    (v)[1] = (a)[1] * (s),\
    (v)[2] = (a)[2] * (s),\
    (v)[3] = (a)[3] * (s))
#define divs_vector4(v, a, b)\
    ((v)[0] = (a)[0] / (b)[0],\
    (v)[1] = (a)[1] / (b)[1],\
    (v)[2] = (a)[2] / (b)[2],\
    (v)[3] = (a)[3] / (b)[3])
// Linear interpolation
#define lerp_vector4(v, t, a, b)\
    ((v)[0] = LERP((t), (a)[0], (b)[0]),\
    (v)[1] = LERP((t), (a)[1], (b)[1]),\
    (v)[2] = LERP((t), (a)[2], (b)[2]),\
    (v)[3] = LERP((t), (a)[3], (b)[3]))
#define mix_vector4(v, a, b, f)\
    ((v)[0] = MIX((a)[0], (b)[0], (f)),\
    (v)[1] = MIX((a)[1], (b)[1], (f)),\
    (v)[2] = MIX((a)[2], (b)[2], (f)),\
    (v)[3] = MIX((a)[3], (b)[3], (f)))
// Dot product, length, normalization
#define dot_vector4(a, b) ((a)[0] * (b)[0] + (a)[1] * (b)[1] + (a)[2] * (b)[2] + (a)[3] * (b)[3])
#define length_vector4(a) (sqrt(dot_vector4(a, a)))
#define normalize_vector4(v) do {\
    float invlen = 1.f / length_vector4(v);\
    (v)[0] *= invlen,\
    (v)[1] *= invlen,\
    (v)[2] *= invlen,\
    (v)[3] *= invlen;\
    } while(0)
// matrix2
// Creation, duplication
#define make_matrix2(m, a, b)\
    (copy_vector2((m)[0], (a)),\
    copy_vector2((m)[1], (b)))
#define copy_matrix2(m, a)\
    (copy_vector2((m)[0], (a)[0]),\
    copy_vector2((m)[1], (a)[1]))

#define delta_matrix2(m) \
    (delta_vector2((m)[0], (m)[1]))

#define transpose_matrix2(m, a) \
    ((m)[0][0] = (a)[0][0], (m)[0][1] = (a)[1][0],\
    (m)[1][0] = (a)[0][1], (m)[1][1] = (a)[1][1])

// matrix3
// Creation, duplication
#define make_matrix3(m, a, b, c)\
    (copy_vector3((m)[0], (a)),\
    copy_vector3((m)[1], (b)),\
    copy_vector3((m)[2], (c)))
#define copy_matrix3(m, a)\
    (copy_vector3((m)[0], (a)[0]),\
    copy_vector3((m)[1], (a)[1]),\
    copy_vector3((m)[2], (a)[2]))
// Addition, subtraction, multiplication, division (by a matrix element)
#define inc_matrix3(m, a)\
    (inc_vector3((m)[0], (a)[0]),\
    inc_vector3((m)[1], (a)[1]),\
    inc_vector3((m)[2], (a)[2]))
#define dec_matrix3(m, a)\
    (dec_vector3((m)[0], (a)[0]),\
    dec_vector3((m)[1], (a)[1]),\
    dec_vector3((m)[2], (a)[2]))
#define add_matrix3(m, a, b)\
    (add_vector3((m)[0], (a)[0], (b)[0]),\
    add_vector3((m)[1], (a)[1], (b)[1]),\
    add_vector3((m)[2], (a)[2], (b)[2]))
#define sub_matrix3(m, a, b)\
    (sub_vector3((m)[0], (a)[0], (b)[0]),\
    sub_vector3((m)[1], (a)[1], (b)[1]),\
    sub_vector3((m)[2], (a)[2], (b)[2]))
#define mul_matrix3(m, a, b)\
    (mul_vector3((m)[0], (a)[0], (b)[0]),\
    mul_vector3((m)[1], (a)[1], (b)[1]),\
    mul_vector3((m)[2], (a)[2], (b)[2]))
#define div_matrix3(m, a, b)\
    (div_vector3((m)[0], (a)[0], (b)[0]),\
    div_vector3((m)[1], (a)[1], (b)[1]),\
    div_vector3((m)[2], (a)[2], (b)[2]))
// Addition, subtraction, multiplication, division (by a scalar element)
#define adds_matrix3(m, a, s)\
    (adds_vector3((m)[0], (a)[0], s),\
    adds_vector3((m)[1], (a)[1], s),\
    adds_vector3((m)[2], (a)[2], s))
#define subs_matrix3(m, a, s)\
    (subs_vector3((m)[0], (a)[0], s),\
    subs_vector3((m)[1], (a)[1], s),\
    subs_vector3((m)[2], (a)[2], s))
#define muls_matrix3(m, a, s)\
    (muls_vector3((m)[0], (a)[0], s),\
    muls_vector3((m)[1], (a)[1], s),\
    muls_vector3((m)[2], (a)[2], s))
#define divs_matrix3(m, a, s)\
    (divs_vector3((m)[0], (a)[0], s),\
    divs_vector3((m)[1], (a)[1], s),\
    divs_vector3((m)[2], (a)[2], s))
// Determinant, transposition, adjunction, inversion
#define delta_matrix3(m) (delta_vector3((m)[0], (m)[1], (m)[2]))
// same as delta_matrix3 but not use any things else
#define det_matrix3(m) \
    (((m)[0][0] * (m)[1][1] * (m)[2][2]) + \
    ((m)[0][1] * (m)[1][2] * (m)[2][0]) + \
    ((m)[0][2] * (m)[1][0] * (m)[2][1]) - \
    ((m)[0][2] * (m)[1][1] * (m)[2][0]) - \
    ((m)[0][1] * (m)[1][0] * (m)[2][2]) - \
    ((m)[0][0] * (m)[1][2] * (m)[2][1]))

#define transpose_matrix3(m, a)\
    ((m)[0][0] = (a)[0][0], (m)[0][1] = (a)[1][0], (m)[0][2] = (a)[2][0],\
    (m)[1][0] = (a)[0][1], (m)[1][1] = (a)[1][1], (m)[1][2] = (a)[2][1],\
    (m)[2][0] = (a)[0][2], (m)[2][1] = (a)[1][2], (m)[2][2] = (a)[2][2])
#define adjunction_matrix3(m, a)\
    ((m)[0][0] = (a)[1][1] * (a)[2][2] - (a)[1][2] * (a)[2][1],\
    (m)[1][0] = (a)[2][1] * (a)[0][2] - (a)[2][2] * (a)[0][1],\
    (m)[2][0] = (a)[0][1] * (a)[1][2] - (a)[0][2] * (a)[1][1],\
    (m)[0][1] = (a)[1][2] * (a)[2][0] - (a)[1][0] * (a)[2][2],\
    (m)[1][1] = (a)[2][2] * (a)[0][0] - (a)[2][0] * (a)[0][2],\
    (m)[2][1] = (a)[0][2] * (a)[1][0] - (a)[0][0] * (a)[1][2],\
    (m)[0][2] = (a)[1][0] * (a)[2][1] - (a)[1][1] * (a)[2][0],\
    (m)[1][2] = (a)[2][0] * (a)[0][1] - (a)[2][1] * (a)[0][0],\
    (m)[2][2] = (a)[0][0] * (a)[1][1] - (a)[0][1] * (a)[1][0])
#define inverse_matrix3(m, a) do {\
    adjunction_matrix3(m, a);\
    float _fac = dot_vector3((m)[0], (a)[0]);\
    divs_matrix3(m, m, _fac);\
    } while(0)
#define inverse2_matrix3(m, a) do {\
    M_FLOAT_TYPE fac = 1.0 / det_matrix3(a);\
    M_FLOAT_TYPE subfactor0[2] = {(a)[1][1], (a)[1][2]};\
    M_FLOAT_TYPE subfactor1[2] = {(a)[2][1], (a)[2][2]};\
    M_FLOAT_TYPE subfactor2[2] = {(a)[0][2], (a)[0][1]};\
    M_FLOAT_TYPE subfactor3[2] = {(a)[2][2], (a)[2][1]};\
    M_FLOAT_TYPE subfactor4[2] = {(a)[0][1], (a)[0][2]};\
    M_FLOAT_TYPE subfactor5[2] = {(a)[1][1], (a)[1][2]};\
    M_FLOAT_TYPE subfactor6[2] = {(a)[1][2], (a)[1][0]};\
    M_FLOAT_TYPE subfactor7[2] = {(a)[2][2], (a)[2][0]};\
    M_FLOAT_TYPE subfactor8[2] = {(a)[0][0], (a)[0][2]};\
    M_FLOAT_TYPE subfactor9[2] = {(a)[2][0], (a)[2][2]};\
    M_FLOAT_TYPE subfactor10[2] = {(a)[0][2], (a)[0][0]};\
    M_FLOAT_TYPE subfactor11[2] = {(a)[1][2], (a)[1][0]};\
    M_FLOAT_TYPE subfactor12[2] = {(a)[1][0], (a)[1][1]};\
    M_FLOAT_TYPE subfactor13[2] = {(a)[2][0], (a)[2][1]};\
    M_FLOAT_TYPE subfactor14[2] = {(a)[0][1], (a)[0][0]};\
    M_FLOAT_TYPE subfactor15[2] = {(a)[2][0], (a)[2][1]};\
    M_FLOAT_TYPE subfactor16[2] = {(a)[0][0], (a)[0][1]};\
    M_FLOAT_TYPE subfactor17[2] = {(a)[1][0], (a)[1][1]};\
    (m)[0][0] = fac * delta_vector2(subfactor0, subfactor1); \
    (m)[0][1] = fac * delta_vector2(subfactor2, subfactor3); \
    (m)[0][2] = fac * delta_vector2(subfactor4, subfactor5); \
    (m)[1][0] = fac * delta_vector2(subfactor6, subfactor7); \
    (m)[1][1] = fac * delta_vector2(subfactor8, subfactor9); \
    (m)[1][2] = fac * delta_vector2(subfactor10, subfactor11); \
    (m)[2][0] = fac * delta_vector2(subfactor12, subfactor13); \
    (m)[2][1] = fac * delta_vector2(subfactor14, subfactor15); \
    (m)[2][2] = fac * delta_vector2(subfactor16, subfactor17); \
    } while(0)
// Matrix product, left vector product, right vector product
#define row_vector3(v, m, n)\
    ((v)[0] * (m)[0][n] + (v)[1] * (m)[1][n] + (v)[2] * (m)[2][n])
#define product_matrix3(m, a, b)\
    ((m)[0][0] = row_vector3((a)[0], (b), 0),\
    (m)[0][1] = row_vector3((a)[0], (b), 1),\
    (m)[0][2] = row_vector3((a)[0], (b), 2),\
    (m)[1][0] = row_vector3((a)[1], (b), 0),\
    (m)[1][1] = row_vector3((a)[1], (b), 1),\
    (m)[1][2] = row_vector3((a)[1], (b), 2),\
    (m)[2][0] = row_vector3((a)[2], (b), 0),\
    (m)[2][1] = row_vector3((a)[2], (b), 1),\
    (m)[2][2] = row_vector3((a)[2], (b), 2))
#define left_product_matrix3_vector3(v, a, m)\
    ((v)[0] = row_vector3((a), (m), 0),\
    (v)[1] = row_vector3((a), (m), 1),\
    (v)[2] = row_vector3((a), (m), 2))
#define right_product_matrix3_vector3(v, m, a)\
    ((v)[0] = dot_vector3((a), (m)[0]),\
    (v)[1] = dot_vector3((a), (m)[1]),\
    (v)[2] = dot_vector3((a), (m)[2]))
// Simple usage of matrix product
#define multiply_matrix3(m, n) do {\
    matrix3 _temp;\
    product_matrix3(_temp, (m), (n));\
    copy_matrix3(m, _temp);\
    } while(0)
// Identity
#define identity_matrix3(m)\
    (make_vector3((m)[0], 1, 0, 0),\
    make_vector3((m)[1], 0, 1, 0),\
    make_vector3((m)[2], 0, 0, 1))
// Rotation, Scale
#define rotate_x_matrix3(m, a) do {\
    const float _c = cosf((a));\
    const float _s = sinf((a));\
    matrix3 _n = {{1, 0, 0},\
    {0, _c, -_s},\
    {0, _s, _c}};\
    matrix3 _temp;\
    product_matrix3(_temp, (m), _n);\
    copy_matrix3((m), _temp);\
    } while(0)
#define rotate_y_matrix3(m, a) do {\
    const float _c = cosf((a));\
    const float _s = sinf((a));\
    matrix3 _n = {{_c, 0, _s},\
    {0, 1, 0},\
    {-_s, 0, _c}};\
    matrix3 _temp;\
    product_matrix3(_temp, (m), _n);\
    copy_matrix3((m), _temp);\
    } while(0)
#define rotate_z_matrix3(m, a) do {\
    const float _c = cosf((a));\
    const float _s = sinf((a));\
    matrix3 _n = {{_c, -_s, 0},\
    {_s, _c, 0},\
    {0, 0, 1}};\
    matrix3 _temp;\
    product_matrix3(_temp, (m), _n);\
    copy_matrix3((m), _temp);\
    } while(0)
#define scale_matrix3(m, v) do {\
    matrix3 _n = {{(v)[0], 0, 0},\
    {0, (v)[1], 0},\
    {0, 0, (v)[2]}};\
    matrix3 _temp;\
    product_matrix3(_temp, (m), _n);\
    copy_matrix3((m), _temp);\
    } while(0)

// matrix4
// Creation, duplication
#define make_matrix4(m, a, b, c, d)\
    (copy_vector4((m)[0], (a)),\
    copy_vector4((m)[1], (b)),\
    copy_vector4((m)[2], (c)),\
    copy_vector4((m)[3], (d)))
#define copy_matrix4(m, a)\
    (copy_vector4((m)[0], (a)[0]),\
    copy_vector4((m)[1], (a)[1]),\
    copy_vector4((m)[2], (a)[2]),\
    copy_vector4((m)[3], (a)[3]))
// Matrix product, left vector product, right vector product
#define row_vector4(m, n, v)\
    ((m)[0][n] * (v)[0] + (m)[1][n] * (v)[1] + (m)[2][n] * (v)[2] + (m)[3][n] * (v)[3])
#define product_matrix4(m, a, b)\
    ((m)[0][0] = row_vector4((a), 0, (b)[0]),\
    (m)[0][1] = row_vector4((a), 1, (b)[0]),\
    (m)[0][2] = row_vector4((a), 2, (b)[0]),\
    (m)[0][3] = row_vector4((a), 3, (b)[0]),\
    (m)[1][0] = row_vector4((a), 0, (b)[1]),\
    (m)[1][1] = row_vector4((a), 1, (b)[1]),\
    (m)[1][2] = row_vector4((a), 2, (b)[1]),\
    (m)[1][3] = row_vector4((a), 3, (b)[1]),\
    (m)[2][0] = row_vector4((a), 0, (b)[2]),\
    (m)[2][1] = row_vector4((a), 1, (b)[2]),\
    (m)[2][2] = row_vector4((a), 2, (b)[2]),\
    (m)[2][3] = row_vector4((a), 3, (b)[2]),\
    (m)[3][0] = row_vector4((a), 0, (b)[3]),\
    (m)[3][1] = row_vector4((a), 1, (b)[3]),\
    (m)[3][2] = row_vector4((a), 2, (b)[3]),\
    (m)[3][3] = row_vector4((a), 3, (b)[3]))
#define left_product_matrix4_vector4(v, a, m)\
    ((v)[0] = row_vector4((m), 0, (a)),\
    (v)[1] = row_vector4((m), 1, (a)),\
    (v)[2] = row_vector4((m), 2, (a)),\
    (v)[3] = row_vector4((m), 3, (a)))
#define right_product_matrix4_vector4(v, m, a)\
    ((v)[0] = dot_vector4((a), (m)[0]),\
    (v)[1] = dot_vector4((a), (m)[1]),\
    (v)[2] = dot_vector4((a), (m)[2]),\
    (v)[3] = dot_vector4((a), (m)[3]))
#define transpose_matrix4(m, a)\
    ((m)[0][0] = (a)[0][0], (m)[0][1] = (a)[1][0], (m)[0][2] = (a)[2][0], (m)[0][3] = (a)[3][0],\
    (m)[1][0] = (a)[0][1], (m)[1][1] = (a)[1][1], (m)[1][2] = (a)[2][1], (m)[1][3] = (a)[3][1],\
    (m)[2][0] = (a)[0][2], (m)[2][1] = (a)[1][2], (m)[2][2] = (a)[2][2], (m)[2][3] = (a)[3][2],\
    (m)[3][0] = (a)[0][3], (m)[3][1] = (a)[1][3], (m)[3][2] = (a)[2][3], (m)[3][3] = (a)[3][3])

// Simple usage of matrix product
#define multiply_matrix4(m, n) do {\
    matrix4 _temp;\
    product_matrix4(_temp, (m), (n));\
    copy_matrix4(m, _temp);\
    } while(0)
// identity
#define identity_matrix4(m)\
    (make_vector4((m)[0], 1, 0, 0, 0),\
    make_vector4((m)[1], 0, 1, 0, 0),\
    make_vector4((m)[2], 0, 0, 1, 0),\
    make_vector4((m)[3], 0, 0, 0, 1))
// Translation, rotation, scale of matrix
#define translate_matrix4(m, v) do {\
    matrix4 n = {{1,0,0,0},\
    {0,1,0,0},\
    {0,0,1,0},\
    {(v)[0],(v)[1],(v)[2],1}};\
    multiply_matrix4(m, n);\
    } while(0)
#define rotate_x_matrix4(m, a) do {\
    const float _c = cosf((a));\
    const float _s = sinf((a));\
    matrix4 _n = {{1, 0, 0, 0},\
    {0, _c, -_s, 0},\
    {0, _s, _c, 0},\
    {0, 0, 0, 1}};\
    matrix4 _temp;\
    product_matrix4(_temp, (m), _n);\
    copy_matrix4((m), _temp);\
    } while(0)
#define rotate_y_matrix4(m, a) do {\
    const float _c = cosf((a));\
    const float _s = sinf((a));\
    matrix4 _n = {{_c, 0, _s, 0},\
    {0, 1, 0, 0},\
    {-_s, 0, _c, 0},\
    {0, 0, 0, 1}};\
    matrix4 _temp;\
    product_matrix4(_temp, (m), _n);\
    copy_matrix4((m), _temp);\
    } while(0)
#define rotate_z_matrix4(m, a) do {\
    const float _c = cosf((a));\
    const float _s = sinf((a));\
    matrix4 _n = {{_c, -_s, 0, 0},\
    {_s, _c, 0, 0},\
    {0, 0, 1, 0},\
    {0, 0, 0, 1}};\
    matrix4 _temp;\
    product_matrix4(_temp, (m), _n);\
    copy_matrix4((m), _temp);\
    } while(0)
#define scale_matrix4(m, v) do {\
    matrix4 _n = {{(v)[0], 0, 0, 0},\
    {0, (v)[1], 0, 0},\
    {0, 0, (v)[2], 0},\
    {0, 0, 0, 1}};\
    matrix4 _temp;\
    product_matrix4(_temp, (m), _n);\
    copy_matrix4((m), _temp);\
    } while(0)
// Build perspective matrix
#define perspective_matrix4(m, fov, aspect, znear, zfar) do {\
    const float range = tanf((fov) * (M_PI / 360.0)) * (znear);\
    make_vector4((m)[0], (2 * (znear)) / ((range * (aspect)) - (-range * (aspect))), 0, 0, 0);\
    make_vector4((m)[1], 0, (2 * (znear)) / (2 * range), 0, 0);\
    make_vector4((m)[2], 0, 0, -((zfar) + (znear)) / ((zfar) - (znear)), -1);\
    make_vector4((m)[3], 0, 0, -(2 * (zfar) * (znear)) / ((zfar) - (znear)), 0);\
    } while(0)
/*#define ortho_matrix4(m, left, right, bottom, top, znear, zfar) do { \
    make_vector4((m)[0], (2.0) / ((right) - (left)), 0, 0, 0);\
    make_vector4((m)[1], 0, (2.0) / ((top) - (bottom)), 0, 0);\
    make_vector4((m)[2], 0, 0, (2.0) / (zfar - znear), 0);\
    make_vector4((m)[3], - ((right) + (left)) / ((right) - (left)), - ((top) + (bottom)) / ((top) - (bottom)), - ((zfar) + (znear)) / ((zfar) - (znear)), 1);\
    } while(0)*/
#define ortho_matrix4(m, left, right, bottom, top, znear, zfar) do { \
    make_vector4((m)[0], 1, 0, 0, 0);\
    make_vector4((m)[1], 0, 1, 0, 0);\
    make_vector4((m)[2], 0, 0, 1, 0);\
    make_vector4((m)[3], 0, 0, 0, 1);\
    (m)[0][0] = (2.0) / ((right) - (left));\
    (m)[1][1] = (2.0) / ((top) - (bottom));\
    (m)[2][2] = - (2.0) / ((zfar) - (znear));\
    (m)[3][0] = - ((right) + (left)) / ((right) - (left));\
    (m)[3][1] = - ((top) + (bottom)) / ((top) - (bottom));\
    (m)[3][2] = - ((zfar) + (znear)) / ((zfar) - (znear));\
    } while(0)

/* float3 zaxis; \
    float3 xaxis; \
    float3 yaxis; \
    float3 neg_eye = {-(eye)[0], -(eye)[1], -(eye)[2]};\
    sub_vector3(zaxis, eye, target); \
    normalize_vector3(zaxis); \
    cross_vector3(xaxis, up, zaxis); \
    normalize_vector3(xaxis); \
    cross_vector3(yaxis, zaxis, xaxis); \
    muls_vector3(zaxis, zaxis, -1.f); \
    identity_matrix4(m); \
    copy_vector3((m)[0], xaxis); \
    copy_vector3((m)[1], yaxis); \
    copy_vector3((m)[2], zaxis); \
    translate_matrix4(m, neg_eye); \*/

// right handed
#define look_at_matrix4(m, eye, target, up) do {\
    float3 f, s, u; \
    sub_vector3(f, target, eye); \
    normalize_vector3(f); \
    cross_vector3(s, f, up); \
    normalize_vector3(s); \
    cross_vector3(u, s, f); \
    (m)[0][0] = s[0]; \
    (m)[1][0] = s[1]; \
    (m)[2][0] = s[2]; \
    (m)[0][1] = u[0]; \
    (m)[1][1] = u[1]; \
    (m)[2][1] = u[2]; \
    (m)[0][2] = -f[0]; \
    (m)[1][2] = -f[1]; \
    (m)[2][2] = -f[2]; \
    (m)[3][0] = -dot_vector3(s, eye); \
    (m)[3][1] = -dot_vector3(u, eye); \
    (m)[3][2] = dot_vector3(f, eye); \
    }while(0)
    /*float3 f, s, u; \
    sub_vector3(f, target, eye); \
    normalize_vector3(f); \
    cross_vector3(s, up, f); \
    normalize_vector3(s); \
    cross_vector3(u, f, s); \
    (m)[0][0] = s[0]; \
    (m)[1][0] = s[1]; \
    (m)[2][0] = s[2]; \
    (m)[0][1] = u[0]; \
    (m)[1][1] = u[1]; \
    (m)[2][1] = u[2]; \
    (m)[0][2] = f[0]; \
    (m)[1][2] = f[1]; \
    (m)[2][2] = f[2]; \
    (m)[3][0] = -dot_vector3(s, eye); \
    (m)[3][1] = -dot_vector3(u, eye); \
    (m)[3][2] = -dot_vector3(f, eye); \
    }while(0)*/

// Matrix convertion
#define matrix3_to_matrix4(a, b)\
    (copy_vector3((b)[0], (a)[0]), (b)[0][3] = 0,\
    copy_vector3((b)[1], (a)[1]), (b)[1][3] = 0,\
    copy_vector3((b)[2], (a)[2]), (b)[2][3] = 0,\
    make_vector4((b)[3], 0, 0, 0, 1))
#define matrix4_from_matrix3(a, b) matrix3_to_matrix4(b, a)
#define matrix4_to_matrix3(a, b)\
    (copy_vector3((b)[0], (a)[0]),\
    copy_vector3((b)[1], (a)[1]),\
    copy_vector3((b)[2], (a)[2]))

// Quaternion
#define make_quat(q, x, y, z, w) ((q)[0] = (x), (q)[1] = (y), (q)[2] = (z), (q)[3] = (w))
#define copy_quat(q, p) ((q)[0] = (p)[0], (q)[1] = (p)[1], (q)[2] = (p)[2], (q)[3] = (p)[3])
#define identity_quat(q) make_quat(q, 0, 0, 0, 1)
// Addition, subtraction, multiplication, division
#define inc_quat(q, p) \
    ((q)[0] += (p)[0],\
    (q)[1] += (p)[1],\
    (q)[2] += (p)[2],\
    (q)[3] += (p)[3])
#define dec_quat(q, p) \
    ((q)[0] -= (p)[0],\
    (q)[1] -= (p)[1],\
    (q)[2] -= (p)[2],\
    (q)[3] -= (p)[3])
#define add_quat(q, a, b) \
    ((q)[0] = (a)[0] + (b)[0],\
    (q)[1] = (a)[1] + (b)[1],\
    (q)[2] = (a)[2] + (b)[2],\
    (q)[3] = (a)[3] + (b)[3])
#define sub_quat(q, a, b) \
    ((q)[0] = (a)[0] - (b)[0],\
    (q)[1] = (a)[1] - (b)[1],\
    (q)[2] = (a)[2] - (b)[2],\
    (q)[3] = (a)[3] - (b)[3])
#define mul_quat(q, q1, q2) \
    ((q)[0] =  (q1)[0] * (q2)[3] + (q1)[1] * (q2)[2] - (q1)[2] * (q2)[1] + (q1)[3] * (q2)[0],\
    (q)[1] = -(q1)[0] * (q2)[2] + (q1)[1] * (q2)[3] + (q1)[2] * (q2)[0] + (q1)[3] * (q2)[1],\
    (q)[2] =  (q1)[0] * (q2)[1] - (q1)[1] * (q2)[0] + (q1)[2] * (q2)[3] + (q1)[3] * (q2)[2],\
    (q)[3] = -(q1)[0] * (q2)[0] - (q1)[1] * (q2)[1] - (q1)[2] * (q2)[2] + (q1)[3] * (q2)[3])
// Addition, subtraction, multiplication, division (by a scalar element)
#define incs_quat(q, s) \
    ((q)[0] += (s),\
    (q)[1] += (s),\
    (q)[2] += (s),\
    (q)[3] += (s))
#define decs_quat(q, s) \
    ((q)[0] -= (s),\
    (q)[1] -= (s),\
    (q)[2] -= (s),\
    (q)[3] -= (s))
#define muls_quat(q, s) \
    ((q)[0] *= (s),\
    (q)[1] *= (s),\
    (q)[2] *= (s),\
    (q)[3] *= (s))
#define divs_quat(q, s) \
    ((q)[0] /= (s),\
    (q)[1] /= (s),\
    (q)[2] /= (s),\
    (q)[3] /= (s))
#define norm_quat(q) (q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3])
#define conj_quat(q, p) make_quat(q, -(p)[0], -(p)[1], -(p)[2], (p)[3])
// radians
#define quat_from_euler(q, r) do {\
    float cx = cosf((r)[0] * 0.5f);\
    float cy = cosf((r)[1] * 0.5f);\
    float cz = cosf((r)[2] * 0.5f);\
    float sx = sinf((r)[0] * 0.5f);\
    float sy = sinf((r)[1] * 0.5f);\
    float sz = sinf((r)[2] * 0.5f);\
    make_quat(q,\
    sx * cy * cz - cx * sy * sz,\
    cx * sy * cz + sx * cy * sz,\
    cx * cy * sz - sx * sy * cz,\
    cx * cy * cz + sx * sy * sz);\
    } while(0)
/*#define quat_from_euler3(q, x, y, z) do {\
    float cx = cosf((x) * 0.5f);\
    float cy = cosf((y) * 0.5f);\
    float cz = cosf((z) * 0.5f);\
    float sx = sinf((x) * 0.5f);\
    float sy = sinf((y) * 0.5f);\
    float sz = sinf((z) * 0.5f);\
    make_quat(q,\
    cx * cy * sz + sx * sy * cz,\
    sx * cy * cz + cx * sy * sz,\
    cx * sy * cz - sx * cy * sz,\
    cx * cy * cz - sx * sy * sz);\
    } while(0)*/
#define quat_from_euler3(q, heading, attitude, bank) do {\
    float c1 = cosf((heading) * 0.5f); \
    float s1 = sinf((heading)* 0.5f); \
    float c2 = cosf((attitude) * 0.5f); \
    float s2 = sinf((attitude) * 0.5f); \
    float c3 = cosf((bank) * 0.5f); \
    float s3 = sinf((bank) * 0.5f); \
    float c1c2 = c1 * c2; \
    float s1s2 = s1 * s2; \
    make_quat(q, c1c2 * s3 + s1s2 * c3,\
    s1 * c2 * c3 + c1 * s2 * s3,\
    c1 * s2 * c3 - s1 * c2 * s3,\
    c1c2 * c3 - s1s2 * s3);\
    } while(0)
// radians
#define quat_from_axis(q, x, y, z, a) do {\
    float _fs = sinf((a) * 0.5f);\
    make_quat(q, (x) * _fs, (y) * _fs, (z) * _fs, cosf((a) * 0.5f));\
    } while(0)
/*#define apply_relative_yaw_pitch_roll(q, yaw, pitch, roll) do {\
    quat qyaw, qpitch, qroll, qrot, q1, q2, q3, q4;\
    quat_from_axis(qyaw, 0.0, 1.0, 0.0, yaw);\
    quat_from_axis(qpitch, 0.0, 0.0, 1.0, pitch);\
    quat_from_axis(qroll, 1.0, 0.0, 0.0, roll);\
    mul_quat(q1, qyaw, qpitch);\
    mul_quat(qrot, q1, qroll);\
    mul_quat(q1, q, qrot);\
    conj_quat(q2, q);\
    mul_quat(q3, q1, q2);\
    mul_quat(q4, q3, q);\
    normalize_quat(q4);\
    copy_quat(q, q4);\
    } while(0)*/
#define quat_rotate(q, x, y, z) do {\
    quat q1, q2, q3;\
    quat_from_axis(q1, 0.0, 1.0, 0.0, y);\
    quat_from_axis(q2, 0.0, 0.0, 1.0, z);\
    quat_from_axis(q3, 1.0, 0.0, 0.0, x);\
    quat p, r;\
    mul_quat(p, q1, q2);\
    mul_quat(r, p, q3);\
    copy_quat(q, r);\
    normalize_quat(q);\
    } while(0)
// quaternion need be normalised
#define quat_to_axis4(q, x, y, z, a) do {\
    a = 2.0f * acosf((q)[3]); \
    float s = sqrtf(1.0 - (q)[3] * (q)[3]);\
    if (s < FLT_EPSILON) \
    (a) = 0, (x) = 1, (y) = 0, (z) = 0; \
    else \
    (x) = q[0] / s, (y) = (q)[1] / s, (z) = (q)[2] / s; \
    } while(0)
/*#define matrix3_from_quat(m, q) do {\
    float qxx = (q)[0] * (q)[0];\
    float qyy = (q)[1] * (q)[1];\
    float qzz = (q)[2] * (q)[2];\
    float qxz = (q)[0] * (q)[2];\
    float qxy = (q)[0] * (q)[1];\
    float qyz = (q)[1] * (q)[2];\
    float qwx = (q)[3] * (q)[0];\
    float qwy = (q)[3] * (q)[1];\
    float qwz = (q)[3] * (q)[2];\
    make_vector3((m)[0], 1 - 2 * (qyy +  qzz), 2 * (qxy + qwz), 2 * (qxz - qwy));\
    make_vector3((m)[1], 2 * (qxy - qwz), 1 - 2 * (qxx +  qzz), 2 * (qyz + qwx));\
    make_vector3((m)[2], 2 * (qxz + qwy), 2 * (qyz - qwx), 1 - 2 * (qxx +  qyy));\
    } while(0)*/
#define matrix3_from_quat(m, q) do {\
    float sqx = (q)[0] * (q)[0];\
    float sqy = (q)[1] * (q)[1];\
    float sqz = (q)[2] * (q)[2];\
    float sqw = (q)[3] * (q)[3];\
    float invs = 1 / (sqx + sqy + sqz + sqw);\
    (m)[0][0] = ( sqx - sqy - sqz + sqw) * invs;\
    (m)[1][1] = (-sqx + sqy - sqz + sqw) * invs;\
    (m)[2][2] = (-sqx - sqy + sqz + sqw) * invs;\
    float tmp1 = q[0] * q[1];\
    float tmp2 = q[2] * q[3];\
    (m)[1][0] = 2.f * (tmp1 + tmp2) * invs;\
    (m)[0][1] = 2.f * (tmp1 - tmp2) * invs;\
    tmp1 = q[0] * q[2];\
    tmp2 = q[1] * q[3];\
    (m)[2][0] = 2.f * (tmp1 - tmp2) * invs;\
    (m)[0][2] = 2.f * (tmp1 + tmp2) * invs;\
    tmp1 = q[1] * q[2];\
    tmp2 = q[0] * q[3];\
    (m)[2][1] = 2.f * (tmp1 + tmp2) * invs;\
    (m)[1][2] = 2.f * (tmp1 - tmp2) * invs;\
    } while(0)
#define matrix3_from_angle_axis(m, v, a) do {\
    float c = cos(a);\
    float s = sin(a);\
    float nc = 1 - c;\
    (m)[0][0] = (v)[0] * (v)[0] * nc + c;\
    (m)[0][1] = (v)[0] * (v)[1] * nc - (v)[2] * s;\
    (m)[0][2] = (v)[0] * (v)[2] * nc + (v)[1] * s;\
    (m)[1][0] = (v)[1] * (v)[0] * nc + (v)[2] * s;\
    (m)[1][1] = (v)[1] * (v)[1] * nc + c;\
    (m)[1][2] = (v)[1] * (v)[2] * nc - (v)[0] * s;\
    (m)[2][0] = (v)[2] * (v)[0] * nc - (v)[1] * s;\
    (m)[2][1] = (v)[2] * (v)[1] * nc + (v)[0] * s;\
    (m)[2][2] = (v)[2] * (v)[2] * nc + c;\
    } while(0)
#define normalize_quat(q) do {\
    float invlen = 1.f / length_quat(q);\
    muls_quat(q, invlen); \
    } while(0)
// magnitude
#define length_quat(q) sqrtf((q)[0] * (q)[0] + (q)[1] * (q)[1] + (q)[2] * (q)[2] + (q)[3] * (q)[3])

// AABB
#define make_aabb2(p, s, aabb) do { \
    (aabb).min[0] = (p)[0] - (s)[0]; \
    (aabb).min[1] = (p)[1] - (s)[1]; \
    (aabb).min[2] = (p)[2] - (s)[2]; \
    (aabb).max[0] = (p)[0] + (s)[0]; \
    (aabb).max[1] = (p)[1] + (s)[1]; \
    (aabb).max[2] = (p)[2] + (s)[2]; \
    } while(0)
#define make_aabb3(px, py, pz, sx, sy, sz, aabb) do { \
    (aabb).min[0] = (px) - (sx); \
    (aabb).min[1] = (py) - (sy); \
    (aabb).min[2] = (pz) - (sz); \
    (aabb).max[0] = (px) + (sx); \
    (aabb).max[1] = (py) + (sy); \
    (aabb).max[2] = (pz) + (sz); \
    } while(0)
#define make_aabb_from_vertices(vertices, count, aabb) do { \
    float3 minv;\
    float3 maxv;\
    copy_vector3(minv, (vertices)[0].position); \
    copy_vector3(maxv, (vertices)[0].position); \
    for (size_t _i = 0; _i < count; _i++) {\
        min_vector3(minv, minv, (vertices)[_i].position);\
        max_vector3(maxv, maxv, (vertices)[_i].position);\
    }\
    copy_vector3((aabb).max, maxv); \
    copy_vector3((aabb).min, minv); \
    } while(0)
#define copy_aabb(a, b) \
    (copy_vector3((a).min, (b).min),\
    copy_vector3((a).max, (b).max))
#define mul_aabb(a, b, c) mul3((a).min, (b).min, (c).min), mul3((a).max, (b).max, (c).max)

#define compute_rotation(m, p, r, s) do {\
    identity_matrix3((m));\
    rotate_x_matrix3((m), (r)[0]);\
    rotate_y_matrix3((m), (r)[1]);\
    rotate_z_matrix3((m), (r)[2]);\
    scale_matrix3((m), (s));\
    } while(0)
#define compute_world(m, p, r, s) do {\
    identity_matrix4((m));\
    translate_matrix4((m), (p));\
    rotate_z_matrix4((m), (r)[2]);\
    rotate_y_matrix4((m), (r)[1]);\
    rotate_x_matrix4((m), (r)[0]);\
    scale_matrix4((m), (s));\
    } while(0)

#define merge_aabb(a, b, c) do { \
    (c).min[0] = MIN((a).min[0], (b).min[0]); \
    (c).min[1] = MIN((a).min[1], (b).min[1]); \
    (c).min[2] = MIN((a).min[2], (b).min[2]); \
    (c).max[0] = MAX((a).max[0], (b).max[0]); \
    (c).max[1] = MAX((a).max[1], (b).max[1]); \
    (c).max[2] = MAX((a).max[2], (b).max[1]); \
    } while(0)
#define compute_aabb(bound, m, p, r, s, aabb) do {\
    identity_matrix3((m));\
    scale_matrix3((m), (s));\
    rotate_x_matrix3((m), (r)[0]);\
    rotate_y_matrix3((m), (r)[1]);\
    rotate_z_matrix3((m), (r)[2]);\
    transform_aabb(&(bound), &(m)[0][0], (p), &(aabb));\
    } while(0)
#define copy_obb(a, b) \
    (copy_vector3((a).position, (b).position),\
    copy_vector3((a).size, (b).size),\
    copy_vector3((a).axis[0], (b).axis[0]),\
    copy_vector3((a).axis[1], (b).axis[1]),\
    copy_vector3((a).axis[2], (b).axis[2]))
#define compute_obb(bound, p, r, s, obb) do {\
    copy_vector3((obb).position, (p));\
    make_vector3((obb).size, 0, 0, 0);\
    inc_vector3((obb).size, (bound).max);\
    dec_vector3((obb).size, (bound).min);\
    muls_vector3((obb).size, (obb).size, 0.5);\
    mul_vector3((obb).size, (obb).size, (s));\
    identity_matrix3((obb).axis);\
    rotate_x_matrix3((obb).axis, (r)[0]);\
    rotate_y_matrix3((obb).axis, (r)[1]);\
    rotate_z_matrix3((obb).axis, (r)[2]);\
    } while(0)
#define transform_obb(obb, w, result) do {\
    matrix4 tmp;\
    matrix4_from_matrix3(tmp, (obb).axis);\
    copy_vector3(tmp[3], (obb).position);\
    matrix4 tmp2;\
    product_matrix4(tmp2, w, tmp);\
    matrix4_to_matrix3(tmp2, (result).axis);\
    copy_vector3((result).size, (obb).size);\
    copy_vector3((result).position, tmp2[3]);\
    } while(0)
#define make_bsphere(p, s, bsphere) do {\
    copy_vector3((bsphere).position, (p));\
    (bsphere).radius = (s);\
    } while(0)

#define ZERO_MATRIX3 {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
#define ZERO_MATRIX4 {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}
#define IDENTITY_MATRIX3 {1, 0, 0}, {0, 1, 0}, {0, 0, 1}
#define IDENTITY_MATRIX4 {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}

typedef float   float2[2];
typedef float   float3[3];
typedef float   float4[4];
typedef int     int2[2];
typedef int     int3[3];
typedef int     int4[4];

typedef float2  matrix2[2];
typedef float3  matrix3[3];
typedef float4  matrix4[4];

typedef struct vec2 {
    float x, y;
} vec2;

typedef struct vec3 {
    float x, y, z;
} vec3;

typedef struct vec4 {
    float x, y, z, w;
} vec4;

typedef struct mat3 {
    vec3 rows[3];
} mat3;

typedef struct mat4 {
    vec4 rows[4];
} mat4;

typedef struct quat {
    float x, y, z, w;
} quat;

// Rect
typedef struct Rect {
    float x, y, width, height;
} RECT;

#define make_rect(rc, _x, _y, _width, _height) ((rc).x = (_x), (rc).y = (_y), (rc).width = (_width), (rc).height = (_height))
#define copy_rect(ra, rb) ((ra).x = (rb).x, (ra).y = (rb).y, (ra).width = (rb).width, (ra).height = (rb).height)
#define center_rect(r, c) ((c)[0] = ((r).x + (r).width) * 0.5, (c)[1] = ((r).y + (r).height) * 0.5)
#define coord_in_rect(r, a, b) ((a) >= (r).x && (a) <= (r).width + (r).x && (b) >= (r).y && (b) <= (r).height + (r).y)
#define point_in_rect(r, p) coord_in_rect(r, (p)[0], (p)[1])
#define intersect_rect(a, b) ((a).x < (b).x + (b).width) &&\
    ((a).x + (a).width > (b).x) &&\
    ((a).y < (b).y + (b).height) &&\
    ((a).y + (a).height > (b).y)

void randv3(float *v);
void randv3_minmax(float *v, float *min_value, float *max_value);
