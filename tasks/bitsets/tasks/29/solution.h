#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Bitset;

const Bitset WORD = 0;

Bitset CountLetters(Bitset bitset) {
    Bitset count = 0;
    while (bitset) {
        count += bitset & 1;
        bitset >>= 1;
    }
    return count;
}

int Task() {
    char letter = 0;
    Bitset set = WORD;
    while ((letter = (char)getchar()) != EOF) {
        if (letter >= 'A' && letter <= 'Z') {
            set |= 1 << (letter - 'A');
        } else if (letter >= 'a' && letter <= 'z') {
            continue;
        } else {
            if (CountLetters(set) > 1) {
                printf("%s\n", "There is a word that contains more than one uppercase letter");
                return 0;
            } else {
                set = WORD;
                continue;
            }
        }
    }
    if (CountLetters(set) > 1) {
        printf("\n");
        printf("%s\n", "There is a word that contains more than one uppercase letter");
    } else {
        printf("%s\n", "There are no words that contains more than one uppercase letter");
    }
    return 0;
}