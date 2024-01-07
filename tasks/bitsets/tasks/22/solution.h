#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Bitset;
const Bitset CONSONANTS = 49266414;
const int LETTERS_IN_ALFABET = 26;

uint32_t CountConsonants(Bitset bitset) {
    uint32_t counter = 0;
    for (int i = 0; i <= LETTERS_IN_ALFABET; ++i) {
        if (bitset & (1u << i)) {
            ++counter;
        }
    }
    return counter;
}

uint32_t CheckOnlyConsonant(Bitset word) {
    Bitset consonants_in_word = word & CONSONANTS;
    return (consonants_in_word != 0 && CountConsonants(consonants_in_word) == 1);
}

int Task() {
    Bitset word = 0;
    char text[] = "qwerty asdfg zxcvb q";  // scanf при необходимости
    for (size_t i = 0; i <= strlen(text); ++i) {
        if ((text[i] >= 'a' && text[i] <= 'z') | (text[i] >= 'A' && text[i] <= 'Z')) {
            word |= (1u << (text[i] - 'a'));
        } else {
            if (CheckOnlyConsonant(word)) {
                printf("Есть слово, включающее только одну согласную\n");
                return 0;
            }
            word = 0;
        }
    }
    printf("Нет таких слов\n");
    return 0;
}
