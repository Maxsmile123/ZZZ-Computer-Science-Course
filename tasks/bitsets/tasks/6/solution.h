#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

const Bitset VOWELS_SECOND_KIND = 17826048;
const Bitset ALL_VOWELS = 17842449;

bool IsVowel(char letter) {
    return ALL_VOWELS & (1u << (letter - 'a'));
}

int Task() {
    // write your solution here
    char introduced_char = 0;
    Bitset word = 0;
    int8_t is_word_found = 0;
    while ((introduced_char = (char)getchar()) != EOF) {
        introduced_char = (char)tolower(introduced_char);
        if ('a' <= introduced_char && introduced_char <= 'z') {
            if (IsVowel(introduced_char)) {
                word = word | (1u << (introduced_char - 'a'));
            }
        } else {
            if (VOWELS_SECOND_KIND == (VOWELS_SECOND_KIND | word) && word != 0) {
                is_word_found = 1;
            }
            word = 0;
        }
    }
    if (is_word_found) {
        printf("There are words containing vowels of 2 kinds");
    } else {
        printf("There are no words containing vowels of the 2nd kind");
    }
    return 0;
}