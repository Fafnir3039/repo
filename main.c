#include "dz1.h"
#include <stdio.h>

int main() {
    printf("Testing CountSimilarBytes:\n");
    long long int test1[] = {
        0x0101010202030408,
        0x0101010202020208,
        0x0102030405060708,
        0x0101010101010101,
        0xFFFFFF00000000FF
    };
    
    for (int i = 0; i < 5; i++) {
        printf("Test %d: %d\n", i+1, CountSimilarBytes(test1[i]));
    }
    
    printf("\nTesting SwapBytes:\n");
    unsigned short test2[] = {0x0102, 0xFF01};
    for (int i = 0; i < 2; i++) {
        printf("Before: 0x%04X, ", test2[i]);
        SwapBytes(&test2[i]);
        printf("After: 0x%04X\n", test2[i]);
    }

    printf("\nTesting GetMaxByte:\n");
    unsigned int test3_1[] = {0x01020109, 0x07890909, 0x8899AABB};
    unsigned int test3_2[] = {2291772091, 16908553, 126421257, 382091489};
    
    printf("Test 1: 0x%02X\n", GetMaxByte(test3_1, 3));
    printf("Test 2: %d (0x%02X)\n", GetMaxByte(test3_2, 4), GetMaxByte(test3_2, 4));
    
    return 0;
}