#pragma once

#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

int Task() {
    // write your solution here
    char c;
    Bitset bitset = 0;
    int count_glas_1 = 0;
    int count_glas_2 = 0;
    while (true) {
        c = (char)getchar();
        if (c == EOF) {
            break;
        }
        if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y') {
            ++count_glas_1;
        if (count_glas_1 == count_glas_2) {
            printf("YES");
        } else {
            printf("NO");
            }
        }
        if (c == " " && count_glas_1 != 0) {
            count_glas_2 = count_glas_1;
            count_glas_1 = 0;
        }
    }
    return 0;
}
