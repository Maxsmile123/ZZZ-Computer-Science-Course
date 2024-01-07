#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const Bitset VOICED_CONSONANTS = 48446026;
const Bitset WITHOUT_LETTERS = 0;
const Bitset WITHOUT_VOWELS = 49266414;

bool AreAllConsonantsUnvoiced(const Bitset word) {
    if ((word & WITHOUT_VOWELS) == WITHOUT_LETTERS) {
        return false;
    } else {
        return (word & VOICED_CONSONANTS) == WITHOUT_LETTERS;
    }
}

int Task() {
    Bitset word = 0;
    char c = 0;
    bool the_right_word_exist = false;

    while ((c = (char)getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            if (AreAllConsonantsUnvoiced(word)) {
                the_right_word_exist = true;
            }
            word = 0;
            continue;
        }
        word = word | 1u << (tolower(c) - 'a');
    }

    if (the_right_word_exist) {
        printf("yes");
    } else {
        printf("no");
    }

    return 0;
}
