#pragma once

#include <stdint.h>

static inline uint32_t pjw_hash(const char *str)
{
    uint32_t hash = 0;
    uint32_t test = 0;

    for (; *str; str++) {
        hash = (hash << 4) + (unsigned char)(*str);

        if ((test = hash & 0xf0000000) != 0) {
            hash = ((hash ^ (test >> 24)) & (0xfffffff));
        }
    }

    return hash;
}
