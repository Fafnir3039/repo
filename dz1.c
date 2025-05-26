#include "dz1.h"
#include <limits.h>

int CountSimilarBytes(long long int byte) {
    unsigned char bytes[sizeof(long long int)];
    int count[UCHAR_MAX + 1] = {0};
    int max_count = 0;

    for (size_t i = 0; i < sizeof(long long int); i++) {
        bytes[i] = (byte >> (i * 8)) & 0xFF;
    }

    for (size_t i = 0; i < sizeof(long long int); i++) {
        if (bytes[i] != 0x00 && bytes[i] != 0xFF) {
            count[bytes[i]]++;
        }
    }

    for (int i = 0; i <= UCHAR_MAX; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }

    return max_count;
}

void SwapBytes(unsigned short* byte) {
    *byte = (*byte >> 8) | (*byte << 8);
}

unsigned char GetMaxByte(const unsigned int* ar, size_t size) {
    unsigned char max_byte = 0;
    
    for (size_t i = 0; i < size; i++) {
        unsigned int current = ar[i];
        for (int j = 0; j < 4; j++) {
            unsigned char byte = (current >> (j * 8)) & 0xFF;
            if (byte > max_byte) {
                max_byte = byte;
            }
        }
    }
    
    return max_byte;
}