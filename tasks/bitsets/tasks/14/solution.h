#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

const uint8_t MAX_CONSONANTS = 20;
const uint8_t LENGTH = 26;

typedef uint32_t Bitset;

bool IsVowel(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y') {
        return true;
    }
    return false;
}

uint32_t CountConsonants(Bitset bitset) {
    uint32_t checker_counter = 0;
    for (int i = 0; i <= LENGTH; ++i) {
        if (bitset & (1u << i)) {
            ++checker_counter;
        }
    }
    return checker_counter;
}

int Task() {
    Bitset bitset = 0;
    char letter = 0;
    while (true) {
        letter = (char)getchar();
        if (letter == EOF) {
            break;
        }
        if (letter >= 'a' && letter <= 'z' && !IsVowel(letter)) {
            bitset |= (1u << (letter - 'a'));
        }
    }
    uint32_t checker_counter = CountConsonants(bitset);
    if (checker_counter < MAX_CONSONANTS) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}
