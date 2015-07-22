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
#include <assert.h>
#include <string.h>

#ifdef USE_MEMTRACK
#include <memtrack.h>
#endif

#include "base/str_replace.h"
#include "base/math_ext.h"

#ifndef ABS
#define ABS(v) ((v) < 0 ? -(v) : (v))
#endif

#ifdef __MINGW32__
void *memmem(const void *haystack, size_t haystack_len, const void *needle, size_t needle_len);
#endif

extern char *
str_replace_once_fast(const char *orig, size_t orig_size, const char *rep, size_t rep_size, char *str, size_t str_size) {
    assert(orig != NULL);
    assert(rep != NULL);
    assert(str != NULL);

    const size_t sz = ABS((int)orig_size - (int)rep_size);
    const size_t nbytes = str_size + sz + 1;

    char *buffer = malloc(nbytes);
    buffer[nbytes - 1] = 0;

    char *p = memmem(str, str_size, orig, orig_size);
    memcpy(buffer, str, p - str);
    memcpy(buffer + (p - str), rep, rep_size);
    const size_t n = str_size - (p - str) - orig_size;
    memcpy(buffer + (p - str) + rep_size, p + orig_size, n);

    return buffer;
}

extern char *
str_replace_fast(const char *orig, size_t orig_size, const char *rep, size_t rep_size, char *str, size_t str_size) {
    assert(orig != NULL);
    assert(rep != NULL);
    assert(str != NULL);

    size_t count;
    char *t;
    char *s = str;

    for (count = 0; (t = memmem(s, str_size, orig, orig_size)) != NULL; count++)
        s = t + rep_size;

    const size_t sz = ABS((int)orig_size - (int)rep_size);
    const size_t nbytes = str_size + sz * count + 1;

    char *buffer = malloc(nbytes);
    buffer[nbytes - 1] = 0;

    char *q = str;
    char *d = buffer;
    while (count--) {
        char *p = strstr(q, orig);
        memcpy(d, q, p - q);
        memcpy(d + (p - q), rep, rep_size);
        const size_t n = str_size - (p - q) - orig_size + 1;
        memcpy(d + (p - q) + rep_size, p + orig_size, n);
        d += (p - q) + rep_size;
        q = p + orig_size;
    }

    return buffer;
}
