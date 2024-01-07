#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// 000000zyxwvutsrqponmlkjihgfedcba
// 00000001000100000100000100010001
const Bitset VOWELS = 17842449;
// 1 бит - начинается с гласной, 2 бит - заканчвается гласной
const Bitset RELEVANT_WORD = 3;

bool IsAlpha(char letter) {
    return (('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z'));
}

bool ToLower(char letter) {
    if ('A' <= letter && letter <= 'Z') {
        return letter + 32;
    } else {
        return letter;
    }
}

bool IsVowel(char letter) {
    return VOWELS & (1u << (ToLower(letter) - 'a'));
}

int Task() {
    char current_char = 0;
    char previous_char = 0;
    Bitset is_relevant_word = 0;
    bool is_word_found = false;
    while ((current_char = (char)getchar()) != EOF) {
        if (IsAlpha(current_char)) {
            if (!IsAlpha(previous_char) && (IsVowel(current_char))) {
                is_relevant_word = is_relevant_word | 1;
            }
        } else {
            if (IsVowel(previous_char)) {
                is_relevant_word = is_relevant_word | 2;
            }
            if (is_relevant_word == RELEVANT_WORD) {
                is_word_found = true;
            }
            is_relevant_word = 0;
        }
        previous_char = current_char;
    }
    if (is_word_found) {
        printf("There is a word starts and ends with vowels");
    } else {
        printf("There are no words starts and ends with vowels");
    }
    return 0;
}