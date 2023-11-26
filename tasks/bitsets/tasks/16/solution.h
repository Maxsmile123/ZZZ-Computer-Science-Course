#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

unsigned int char_to_set(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z' || c == 'a' || c == 'u' || c == 'o' || c == 'e' || c == 'i') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

int Task() {
    char c;
    unsigned int letters_set_1 = 0;
    unsigned int letters_set_2 = 0;
    bool answer = false;
    while ((c = getchar()) != EOF) {
        letters_set_2 = letters_set_2 | char_to_set(c);
        if (c == ' ' || c == '\n') {
            if (letters_set_2 == letters_set_1) {
                answer = true;
            }
            letters_set_1 = letters_set_2;
            letters_set_2 = 0;
        }
    }
    if (answer == true) {
        printf("YES");
    } else {
        printf("NO");
    }
}