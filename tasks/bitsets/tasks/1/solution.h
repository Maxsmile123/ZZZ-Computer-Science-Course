#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const Bitset ALL_VOWELS = 17842449;

Bitset vowelAlphabet() {
    uint32_t vowel_amount = 5;
    char text[] = {'a', 'e', 'i', 'o', 'y'};
    uint32_t set = 0;
    for (uint32_t i = 0; i < vowel_amount; i++) {
        set = set | (1u << (text[i] - 'a'));
    }
    return set;
}

bool Isvowel(char letter) {
    return ALL_VOWELS & (1u << (letter - 'a'));
}

bool IsBeenBefore(char symbol, Bitset vowel_before) {
    return (vowel_before >= (vowel_before ^ (1u << (symbol - 'a'))));
}

int Task() {
    bool repeated_vowel = false;
    uint32_t space_counter = 0;
    Bitset vowel = 0u;
    Bitset vowel_before = 0;
    char symbol = 0;
    vowel = vowelAlphabet();
    while ((symbol = (char)getchar()) != EOF) {
        if ((symbol == ' ') || (symbol == EOF)) {
            if ((repeated_vowel == false) && (space_counter == 0)) {
                printf("there is at least one word with non-repeating vowels");
                return 0;
            }
            ++space_counter;
            vowel_before = 0;
            repeated_vowel = false;
            continue;
        }
        space_counter = 0;
        if (Isvowel(symbol)) {
            if (IsBeenBefore(symbol, vowel_before) == false) {
                vowel_before = (vowel_before ^ (1u << (symbol - 'a')));
            } else {
                repeated_vowel = true;
            }
        }
    }
    if (repeated_vowel == 0) {
        printf("there is at least one word with non-repeating vowels\n");
        return 0;
    }
    printf("no word with non-repeating vowels\n");
    return 0;
}
