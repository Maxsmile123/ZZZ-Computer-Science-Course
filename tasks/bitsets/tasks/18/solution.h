#pragma once

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Bitset;

int Task() {
    printf("вводные данные:\n");
    Bitset lower = 0;
    Bitset upper = 0;
    Bitset prev_lower = 0;
    Bitset prev_upper = 0;
    char line[100] = {};
    scanf("%s", line);
    for (size_t i = 0; i < strlen(line); i++) {
        if ((line[i] - 'A') < 26 && (line[i] - 'A') >= 0) {
            printf("big\n");
            if (!((line[i] == 'A') || (line[i] == 'E') || (line[i] == 'I') || (line[i] == 'O') || (line[i] == 'U'))) {
                upper = upper | (1 << (line[i] - 'A'));
            }
            if (prev_upper == (prev_upper | (1 << (line[i] - 'A')))) {
                return 0;
            }
        } else if (abs(line[i] - 'a') < 26 && (line[i] - 'a') >= 0) {
            printf("small\n");
            if (!((line[i] == 'a') || (line[i] == 'e') || (line[i] == 'i') || (line[i] == 'o') || (line[i] == 'u'))) {
                lower = lower | (1 << (line[i] - 'a'));
            }
            if (prev_lower == (prev_lower | (1 << (line[i] - 'a')))) {
                return 0;
            }
        } else {
            if (!(upper == 0)) {
                prev_upper = upper;
            }
            if (!(lower == 0)) {
                prev_lower = lower;
            }
            upper = 0;
            lower = 0;
        }
    }
    printf("не пересекаются");
    return 0;
}
