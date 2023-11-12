#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

void CheckVowelFreedom(Bitset bitset) {
    const uint8_t max_vowels = 6;
    const uint8_t len_alphabet = 26;
    uint8_t count = 0;
    for (int i = len_alphabet; i >= 0; --i) {
        if ((bitset >> i) & 1) {
            ++count;
        }
    }
    if (count < max_vowels) {
        printf("\n\nYes\n");
    } else {
        printf("\n\nNo\n");
    }
}

int Task() {
    const Bitset all_vowels = 17842449;
    char c = 0;
    Bitset bitset = 0;
    while (true) {
        c = (char)getchar();
        if (c == EOF) {
            break;
        }
        if ((all_vowels >> (c - 'a')) & 1) {
            bitset = bitset | (1u << (c - 'a'));
        }
    }
    CheckVowelFreedom(bitset);
    return 0;
}