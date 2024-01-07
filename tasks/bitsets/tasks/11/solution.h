#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Bitset;
const Bitset CONSONANTS = 17842449;  // 01000100000100000100010001
const int LETTRRS_IN_ALFABET = 26;

uint32_t CheckOnlyVovel(Bitset word) {
    return (word & CONSONANTS);
}

int Task() {
    Bitset word = 0;
    Bitset count = 17842449;
    char words[] = "wrte gtfe nhte vcxe";  // write words
    for (size_t i = 0; i <= strlen(words); ++i) {
        if (words[i] >= 'a' && words[i] <= 'z') {
            word |= (1u << (words[i] - 'a'));
        } else {
            count &= CheckOnlyVovel(word);
            word = 0;
        }
    }
    if (count > 0) {
        printf("there are vowels included in all words\n");
    } else {
        printf("there are no vowels included in all words\n");
    }
    return 0;
}
