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
#include "base/intersection.h"

extern int
intersect_aabb(const AABB * restrict a, const AABB * restrict b) {
    return  (!((a->max[0] < b->min[0]) || (a->min[0] > b->max[0]))) &&
            (!((a->max[1] < b->min[1]) || (a->min[1] > b->max[1]))) &&
            (!((a->max[2] < b->min[2]) || (a->min[2] > b->max[2])));
}

extern int
intersect_aabb_sphere(const AABB * restrict bb, const BSPHR * restrict sphere) {
    float a, d = 0.f;

    for (int i = 0; i < 3; i++) {
        if (sphere->position[i] < bb->min[i]) {
            a = sphere->position[i] - bb->min[i];
            d += a * a;
        }

        if (sphere->position[i] > bb->max[i]) {
            a = sphere->position[i] - bb->max[i];
            d += a * a;
        }
    }

    return d <= (sphere->radius * sphere->radius);
}

extern void
transform_aabb(const AABB * restrict a, const float * restrict m, const float *t, AABB * restrict b) {
    make_vector3(b->min, t[0], t[1], t[2]);
    make_vector3(b->max, t[0], t[1], t[2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float e = m[j * 3 + i] * a->min[j];
            float f = m[j * 3 + i] * a->max[j];

            if (e < f) {
                b->min[i] += e;
                b->max[i] += f;
            } else {
                b->min[i] += f;
                b->max[i] += e;
            }
        }
    }

    /*float e, f;

    // j = 0 i = 0
    e = m[0 * 3 + 0] * a->min[0];
    f = m[0 * 3 + 0] * a->max[0];

    if (e < f) {
        b->min[0] += e;
        b->max[0] += f;
    } else {
        b->min[0] += f;
        b->max[0] += e;
    }

    // j = 0  i = 1
    e = m[0 * 3 + 1] * a->min[0];
    f = m[0 * 3 + 1] * a->max[0];

    if (e < f) {
        b->min[1] += e;
        b->max[1] += f;
    } else {
        b->min[1] += f;
        b->max[1] += e;
    }

    // j = 0 i = 2
    e = m[0 * 3 + 2] * a->min[0];
    f = m[0 * 3 + 2] * a->max[0];

    if (e < f) {
        b->min[2] += e;
        b->max[2] += f;
    } else {
        b->min[2] += f;
        b->max[2] += e;
    }
    //--------------------
    // j = 1 i = 0
    e = m[1 * 3 + 0] * a->min[1];
    f = m[1 * 3 + 0] * a->max[1];

    if (e < f) {
        b->min[0] += e;
        b->max[0] += f;
    } else {
        b->min[0] += f;
        b->max[0] += e;
    }

    // j = 1  i = 1
    e = m[1 * 3 + 1] * a->min[1];
    f = m[1 * 3 + 1] * a->max[1];

    if (e < f) {
        b->min[1] += e;
        b->max[1] += f;
    } else {
        b->min[1] += f;
        b->max[1] += e;
    }

    // j = 1 i = 2
    e = m[1 * 3 + 2] * a->min[1];
    f = m[1 * 3 + 2] * a->max[1];

    if (e < f) {
        b->min[2] += e;
        b->max[2] += f;
    } else {
        b->min[2] += f;
        b->max[2] += e;
    }
    //--------------------
    // j = 2 i = 0
    e = m[2 * 3 + 0] * a->min[2];
    f = m[2 * 3 + 0] * a->max[2];

    if (e < f) {
        b->min[0] += e;
        b->max[0] += f;
    } else {
        b->min[0] += f;
        b->max[0] += e;
    }

    // j = 1  i = 1
    e = m[2 * 3 + 1] * a->min[2];
    f = m[2 * 3 + 1] * a->max[2];

    if (e < f) {
        b->min[1] += e;
        b->max[1] += f;
    } else {
        b->min[1] += f;
        b->max[1] += e;
    }

    // j = 1 i = 2
    e = m[2 * 3 + 2] * a->min[2];
    f = m[2 * 3 + 2] * a->max[2];

    if (e < f) {
        b->min[2] += e;
        b->max[2] += f;
    } else {
        b->min[2] += f;
        b->max[2] += e;
    }*/

    /*float e0 = m[0 * 3 + 0] * a->min[0];
    float f0 = m[0 * 3 + 0] * a->max[0];
    float e1 = m[0 * 3 + 1] * a->min[0];
    float f1 = m[0 * 3 + 1] * a->max[0];
    float e2 = m[0 * 3 + 2] * a->min[0];
    float f2 = m[0 * 3 + 2] * a->max[0];
    float e3 = m[1 * 3 + 0] * a->min[1];
    float f3 = m[1 * 3 + 0] * a->max[1];
    float e4 = m[1 * 3 + 1] * a->min[1];
    float f4 = m[1 * 3 + 1] * a->max[1];
    float e5 = m[1 * 3 + 2] * a->min[1];
    float f5 = m[1 * 3 + 2] * a->max[1];
    float e6 = m[2 * 3 + 0] * a->min[2];
    float f6 = m[2 * 3 + 0] * a->max[2];
    float e7 = m[2 * 3 + 1] * a->min[2];
    float f7 = m[2 * 3 + 1] * a->max[2];
    float e8 = m[2 * 3 + 2] * a->min[2];
    float f8 = m[2 * 3 + 2] * a->max[2];*/

    /*float e0 = m[0] * a->min[0];
    float e1 = m[1] * a->min[0];
    float e2 = m[2] * a->min[0];
    float e3 = m[3] * a->min[1];
    float e4 = m[4] * a->min[1];
    float e5 = m[5] * a->min[1];
    float e6 = m[6] * a->min[2];
    float e7 = m[7] * a->min[2];
    float e8 = m[8] * a->min[2];
    float f0 = m[0] * a->max[0];
    float f1 = m[1] * a->max[0];
    float f2 = m[2] * a->max[0];
    float f3 = m[3] * a->max[1];
    float f4 = m[4] * a->max[1];
    float f5 = m[5] * a->max[1];
    float f6 = m[6] * a->max[2];
    float f7 = m[7] * a->max[2];
    float f8 = m[8] * a->max[2];

    if (e0 < f0) {
        b->min[0] += e0;
        b->max[0] += f0;
    } else {
        b->min[0] += f0;
        b->max[0] += e0;
    }

    if (e1 < f1) {
        b->min[1] += e1;
        b->max[1] += f1;
    } else {
        b->min[1] += f1;
        b->max[1] += e1;
    }

    if (e2 < f2) {
        b->min[2] += e2;
        b->max[2] += f2;
    } else {
        b->min[2] += f2;
        b->max[2] += e2;
    }

    if (e3 < f3) {
        b->min[0] += e3;
        b->max[0] += f3;
    } else {
        b->min[0] += f3;
        b->max[0] += e3;
    }

    if (e4 < f4) {
        b->min[1] += e4;
        b->max[1] += f4;
    } else {
        b->min[1] += f4;
        b->max[1] += e4;
    }

    if (e5 < f5) {
        b->min[2] += e5;
        b->max[2] += f5;
    } else {
        b->min[2] += f5;
        b->max[2] += e5;
    }

    if (e6 < f6) {
        b->min[0] += e6;
        b->max[0] += f6;
    } else {
        b->min[0] += f6;
        b->max[0] += e6;
    }

    if (e7 < f7) {
        b->min[1] += e7;
        b->max[1] += f7;
    } else {
        b->min[1] += f7;
        b->max[1] += e7;
    }

    if (e8 < f8) {
        b->min[2] += e8;
        b->max[2] += f8;
    } else {
        b->min[2] += f8;
        b->max[2] += e8;
    }*/

    /*float e[9];
    float f[9];

    for (int i = 0; i < 9; i++)
        e[i] = m[i] * a->min[i / 3];

    for (int i = 0; i < 9; i++)
        f[i] = m[i] * a->max[i / 3];

    for (int i = 0; i < 9; i++)
        if (e[i] < f[i]) {
            b->min[i % 3] += e[i];
            b->max[i % 3] += f[i];
        } else {
            b->min[i % 3] += f[i];
            b->max[i % 3] += e[i];
        }*/
}

/*void
print_aabb(struct AABB *aabb) {
    puts("AABB");
    printf("\tmin %f %f %f\n", aabb->min[0], aabb->min[1], aabb->min[2]);
    printf("\tmax %f %f %f\n", aabb->max[0], aabb->max[1], aabb->max[2]);
}*/

extern void
make_oob_from_aabb(OBB *obb, const AABB *aabb) {
    copy_vector3(obb->size, aabb->max);
    dec_vector3(obb->size, aabb->min);
    muls_vector3(obb->size, obb->size, 0.5f);

    copy_vector3(obb->position, aabb->min);
    inc_vector3(obb->position, obb->size);

    identity_matrix3(obb->axis);
}

// TODO: find whats wrong with position
extern int
intersect_obb(const OBB *obb0, const OBB *obb1) {
    float3 a = {0};
    float3 b = {0};
    float3 Pa = {0};
    float3 Pb = {0};
    matrix3 A = {ZERO_MATRIX3};
    matrix3 B = {ZERO_MATRIX3};

    copy_vector3(a, obb0->size);
    copy_vector3(b, obb1->size);
    copy_vector3(Pa, obb0->position);
    copy_vector3(Pb, obb1->position);

    copy_matrix3(A, obb0->axis);
    copy_matrix3(B, obb1->axis);

    float3 v = {0};
    copy_vector3(v, Pb);
    dec_vector3(v, Pa);

    float3 T = {0};
    right_product_matrix3_vector3(T, A, v);

    matrix3 R = {ZERO_MATRIX3};
    matrix3 BT = {ZERO_MATRIX3};
    transpose_matrix3(BT, B);
    product_matrix3(R, A, BT);

    float ra, rb, t;

    for (int i = 0; i < 3; i++) {
        ra = a[i];
        rb = b[0] * fabs(R[i][0]) + b[1] * fabs(R[i][1]) + b[2] * fabs(R[i][2]);
        t = fabs(T[i]);

        if (t > ra + rb)
            return 0;
    }

    for (int k = 0; k < 3; k++) {
        ra = a[0] * fabs(R[0][k]) + a[1] * fabs(R[1][k]) + a[2] * fabs(R[2][k]);
        rb = b[k];
        t = fabs(T[0] * R[0][k] + T[1] * R[1][k] + T[2] * R[2][k]);

        if (t > ra + rb)
            return 0;
    }

    //
    //L = A0 x B0
    ra = a[1] * fabs(R[2][0]) + a[2] * fabs(R[1][0]);
    rb = b[1] * fabs(R[0][2]) + b[2] * fabs(R[0][1]);
    t = fabs(T[2] * R[1][0] - T[1] * R[2][0]);
    if (t > ra + rb)
        return 0;

    //L = A0 x B1
    ra = a[1] * fabs(R[2][1]) + a[2] * fabs(R[1][1]);
    rb = b[0] * fabs(R[0][2]) + b[2] * fabs(R[0][0]);
    t = fabs(T[2] * R[1][1] - T[1] * R[2][1]);
    if (t > ra + rb)
        return 0;

    //L = A0 x B2
    ra = a[1] * fabs(R[2][2]) + a[2] * fabs(R[1][2]);
    rb = b[0] * fabs(R[0][1]) + b[1] * fabs(R[0][0]);
    t = fabs(T[2] * R[1][2] - T[1] * R[2][2]);
    if (t > ra + rb)
        return 0;

    //L = A1 x B0
    ra = a[0] * fabs(R[2][0]) + a[2] * fabs(R[0][0]);
    rb = b[1] * fabs(R[1][2]) + b[2] * fabs(R[1][1]);
    t = fabs(T[0] * R[2][0] - T[2] * R[0][0]);
    if (t > ra + rb)
        return 0;

    //L = A1 x B1
    ra = a[0] * fabs(R[2][1]) + a[2] * fabs(R[0][1]);
    rb = b[0] * fabs(R[1][2]) + b[2] * fabs(R[1][0]);
    t = fabs(T[0] * R[2][1] - T[2] * R[0][1]);
    if(t > ra + rb)
        return 0;

    //L = A1 x B2
    ra = a[0] * fabs(R[2][2]) + a[2] * fabs(R[0][2]);
    rb = b[0] * fabs(R[1][1]) + b[1] * fabs(R[1][0]);
    t = fabs(T[0] * R[2][2] - T[2] * R[0][2]);
    if (t > ra + rb)
        return 0;

    //L = A2 x B0
    ra = a[0] * fabs(R[1][0]) + a[1] * fabs(R[0][0]);
    rb = b[1] * fabs(R[2][2]) + b[2] * fabs(R[2][1]);
    t = fabs(T[1] * R[0][0] - T[0] * R[1][0]);
    if (t > ra + rb)
        return 0;

    //L = A2 x B1
    ra = a[0] * fabs(R[1][1]) + a[1] * fabs(R[0][1]);
    rb = b[0] * fabs(R[2][2]) + b[2] * fabs(R[2][0]);
    t = fabs(T[1] * R[0][1] - T[0] * R[1][1]);
    if (t > ra + rb)
        return 0;

    //L = A2 x B2
    ra = a[0] * fabs(R[1][2]) + a[1] * fabs(R[0][2]);
    rb = b[0] * fabs(R[2][1]) + b[1] * fabs(R[2][0]);
    t = fabs(T[1]*R[0][2] - T[0]*R[1][2]);
    if (t > ra + rb)
        return 0;

    return 1;
}
