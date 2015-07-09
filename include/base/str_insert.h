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

#if __STDC_VERSION__ < 199901L
#error "c99 not supported"
#endif

#include <string.h>

#define str_insert(str, substr, pos) \
    str_insert_fast(str, strlen(str), substr, strlen(substr), pos)
#define str_insert_fixed(str, substr, pos) \
    str_insert_fixed_fast(str, strlen(str), substr, strlen(substr), pos)
#define str_insert_fixed_s(str, substr, pos, max_size) \
    str_insert_fixed_fast_s(str, strlen(str), substr, strlen(substr), pos, max_size)

char *str_insert_fast(const char *str, size_t str_size, const char *substr, size_t substr_size, size_t pos);
char *str_insert_fixed_fast(char *str, size_t str_size, const char *substr, size_t substr_size, size_t pos);
char *str_insert_fixed_fast_s(char *str, size_t str_size, const char *substr, size_t substr_size, size_t pos, size_t max_size);
