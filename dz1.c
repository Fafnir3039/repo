#include "dz1.h"
#include <stddef.h>

int CountSimilarBytes(long long int value) {
    unsigned char bytes[sizeof(long long int)];
    int count[256] = {0};
    int max_count = 0;

    for (size_t i = 0; i < sizeof(long long int); ++i) {
        bytes[i] = (value >> (i * 8)) & 0xFF;
    }

    for (size_t i = 0; i < sizeof(long long int); ++i) {
        unsigned char b = bytes[i];
        if (b != 0x00 && b != 0xFF) {
            count[b]++;
        }
    }

    for (int i = 0; i < 256; ++i) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }

    return max_count;
}
