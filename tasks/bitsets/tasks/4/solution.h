#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const Bitset WITHOUT_VOWELS = 4278173422;

// как я получил битсет WITHOUT_VOWELS:
// char vowels[] = {'a', 'e', 'i', 'o', 'y'};
// Bitset only_vowels = 0;
// for (int i = 0; i < VOWELS_COUNT; i++) {
//     only_vowels |= (1 << (vowels[i] - 'a'));
// }
// Bitset without_vowels = only_vowels ^ UINT32_MAX;

bool CharIsConsonant(int32_t index) {
    return (WITHOUT_VOWELS >> index) & 1;
}

int Task() {
    char inputed_char = 0;
    bool word_with_repeated_consonant_is_found = false;
    int32_t index = 0;
    Bitset previous_letters_set = 0;
    Bitset letters_set = 0;
    while ((inputed_char = (char)getchar()) != EOF) {
        if (isalpha(inputed_char)) {
            inputed_char = (char)tolower(inputed_char);
            index = inputed_char - 'a';
            letters_set |= (1 << index);
            if (previous_letters_set == letters_set && CharIsConsonant(index)) {
                word_with_repeated_consonant_is_found = true;
                break;
            } else {
                previous_letters_set = letters_set;
            }
        } else {
            letters_set = 0;
            previous_letters_set = 0;
        }
    }
    if (word_with_repeated_consonant_is_found) {
        printf("A word with at least one repeating consonant was found\n");
    } else {
        printf("A word with at least one repeating consonant was not found\n");
    }
    return 0;
}