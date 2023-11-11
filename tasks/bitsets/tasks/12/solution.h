#pragma once

#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

const uint32_t CONSONANT = 4277124846u;  // number for all consonants

int Task() {
    Bitset word = 0u;
    Bitset consonant = CONSONANT;
    char writing = ' ';
    char imput_words[] = "mama myla ramu 0";
    uint32_t counter_words = 0;

    while (imput_words[counter_words] != '0') {  // replacing with "scanf" when we output from console
        writing = imput_words[counter_words];    // delete if "scanf"
        if (writing >= 'a' && writing <= 'z') {
            word = word | (1u << (writing - 'a'));
        } else {
            consonant = word & consonant;
            word = 0u;
        }
        ++counter_words;
    }
    if (consonant != 0u) {
        printf("Yes, words have a common consonant");
    } else {
        printf("No, words do not have a common consonant");
    }
    return 0;
}
