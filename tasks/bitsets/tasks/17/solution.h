#pragma once

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

Bitset Vowals() {
    Bitset vowals = 0u;
    char letter = 'a';
    vowals = vowals | (1u << (letter - 'a'));
    letter = 'e';
    vowals = vowals | (1u << (letter - 'a'));
    letter = 'i';
    vowals = vowals | (1u << (letter - 'a'));
    letter = 'o';
    vowals = vowals | (1u << (letter - 'a'));
    letter = 'u';
    vowals = vowals | (1u << (letter - 'a'));
    letter = 'y';
    vowals = vowals | (1u << (letter - 'a'));
    return vowals;
}

const Bitset VOWALS = Vowals();

bool IsVowal(char c) {
    return (((1u << (c - 'a')) | VOWALS) == VOWALS);
}

int Task() {
    // write your solution here
    char symbol = 0;
    Bitset vowals_of_new_word = 0u;
    Bitset vowals_of_last_word = 0u;
    int8_t is_success = 0;
    int8_t is_letter = 0;
    while (scanf("%c", &symbol) != EOF) {
        symbol = char(tolower(symbol));
        if ('a' <= symbol && symbol <= 'z') {
            if (IsVowal(symbol)) {
                vowals_of_new_word = vowals_of_new_word | (1u << (symbol - 'a'));
            }
            is_letter = 1;
        } else {
            if ((vowals_of_new_word & vowals_of_last_word) == vowals_of_new_word && is_letter) {
                printf("Есть два соседних слова с пересекающимся набором гласных.\n");
                is_success = 1;
                break;
            }
            vowals_of_last_word = vowals_of_new_word;
            vowals_of_new_word = 0u;
            is_letter = 0;
        }
    }
    if (!is_success) {
        printf("Нет двух соседних слов с пересекающимся набором гласных\n");
    }
    return 0;
}