#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

const Bitset VOWELS = 17842449;

bool IsAllVowelsInWord(const Bitset text) {
    return (text & VOWELS) == VOWELS;
}

int Task() {
    Bitset input_text = 0;
    char c = 0;
    while ((c = (char)getchar()) != EOF) {
        input_text = input_text | 1u << (c - 'a');
    }
    if (IsAllVowelsInWord(input_text)) {
        printf("\nno\n");
    } else {
        printf("\nyes\n");
    }
    return 0;
}