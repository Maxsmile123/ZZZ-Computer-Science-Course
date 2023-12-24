#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// Sibilant consonants:
// sh, ch, zh, th

const Bitset VOWELS = 17842449u;
/*
    Bitset bitset = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < sizeof(vowels); ++i) {
            bitset |= (1u << (vowels[i] - 'a'));
    }
    printf("%u", bitset);
*/

const Bitset PARTS_OF_SIBILANT_CONSONANTS = 34340868u;
/*
    Bitset bitset = 0;
    char sibilants[] = {'s', 'c', 'z', 't'};
    for (int i = 0; i < sizeof(sibilants); ++i) {
            bitset |= (1u << (sibilants[i] - 'a'));
    }
    printf("%u", bitset);
*/

bool CheckForPartsOfSibilant(const char symbol) {
    return (PARTS_OF_SIBILANT_CONSONANTS & (1u << (symbol - 'a')));
}

bool CheckForVowels(const char symbol) {
    return (VOWELS & (1u << (symbol - 'a')));
}

bool IsThereWordConsistsOfSibilants() {
    bool is_there_sibilant_consonants = false;
    bool is_there_part_of_sibilant = false;
    bool is_there_non_sibilant = false;

    char input_letter = 0;
    while ((input_letter = (char)getchar()) != EOF) {
        if (isalpha(input_letter)) {
            if (!is_there_non_sibilant) {
                if (CheckForPartsOfSibilant((char)tolower(input_letter))) {
                    if (is_there_part_of_sibilant) {
                        is_there_non_sibilant = true;
                    } else {
                        is_there_part_of_sibilant = true;
                    }
                } else if ((is_there_part_of_sibilant) && (char)tolower(input_letter) == 'h') {
                    is_there_sibilant_consonants = true;
                    is_there_part_of_sibilant = false;
                } else if (CheckForVowels((char)tolower(input_letter))) {
                    if (is_there_part_of_sibilant) {
                        is_there_non_sibilant = true;
                        is_there_part_of_sibilant = false;
                    }
                } else {
                    is_there_non_sibilant = true;
                }
            }
        } else {
            if (input_letter != '\n') {
                is_there_non_sibilant = false;
            }
        }
    }
    return (is_there_sibilant_consonants && !is_there_non_sibilant && !is_there_part_of_sibilant) ? true : false;
}

int Task() {
    bool result = IsThereWordConsistsOfSibilants();
    if (result) {
        printf("There is a word whose consonants are all sibilants.");
    } else {
        printf("No words consisting only of sibilant consonants were found.");
    }
    return 0;
}