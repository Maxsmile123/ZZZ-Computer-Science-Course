#pragma once

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef uint32_t Bitset;

const Bitset SET = 0;

Bitset Check(Bitset a) {
    Bitset count = 0;
    while (a) {
        count += a & 1;
        a >>= 1;
    }
    return count;
}

int Task() {
    Bitset only_vowels = (((1 << ('a' - 'a')) | (1 << ('e' - 'a'))) | (1 << ('i' - 'a')) | (1 << ('o' - 'a')) |
                          (1 << ('u' - 'a')) | (1 << ('y' - 'a')));
    int flag = 0;
    char alpha = 0;
    Bitset new_set = SET;
    while (true) {
        alpha = getchar();
        if (isalpha((char)(alpha))) {
            new_set = new_set | (1 << (alpha - 'a'));
        } else if (!isalpha((char)(alpha)) && (alpha != EOF)) {
            if (Check((new_set | only_vowels) ^ only_vowels) >= 1) {
                flag = 1;
                break;
            } else {
                new_set = SET;
            }
        } else if (alpha == EOF) {
            break;
        }
    }
    if (flag == 0) {
        printf("NO");
    } else {
        printf("YES");
    }
    return 0;
}
