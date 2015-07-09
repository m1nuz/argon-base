#pragma once

#include <stddef.h>

typedef struct Text {
    size_t  size;
    char    buffer[];
} TEXT;
