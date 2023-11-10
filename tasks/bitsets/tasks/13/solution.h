#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void Checker(uint8_t count, uint8_t max_glasn) {
    if (count < max_glasn) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}

typedef uint32_t Bitset;

int Task() {
    char c = 0;
    Bitset bitset = 0;
    while (true) {
        c = (char)getchar();
        if (c == EOF) {
            break;
        }
        if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y') {
            bitset = bitset | (1u << (c - 'a'));
        }
    }
    const uint8_t max_glasn = 6;
    const uint8_t lens = 26;
    uint8_t count = 0;
    for (int i = lens; i >= 0; --i) {
        if ((bitset >> i) & 1) {
            ++count;
        }
    }
    Checker(count, max_glasn);
    return 0;
}