#pragma once

#include <math.h>
#include <regex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum states {
    start,
    test_for_illegal_characters,
    has_illegal_characters,
    test_for_tetriary,
    is_tetriary,
    convert_to_decimal,
    End
} State;

int Task() {
    printf("введите одно число:\n");
    regex_t regex;
    int decimal = 0;
    const char *three_or_four = "[34]";
    const char *all_numbers = "[^01234]";
    char num[] = "124";
    printf("допустим оно будет 124\n");
    int n_num = 0;
    State state = start;
    while (true) {
        switch (state) {
            case End:
                regfree(&regex);
                return 0;
            case start:
                state = test_for_illegal_characters;
                break;
            case test_for_illegal_characters:
                if (regcomp(&regex, all_numbers, 0) != 0) {
                    fprintf(stderr, "Failed to compile regex pattern\n");
                    state = End;
                    break;
                }
                regmatch_t match;
                if (regexec(&regex, num, 1, &match, 0) == 0) {
                    state = has_illegal_characters;
                } else {
                    state = test_for_tetriary;
                }
                break;
            case test_for_tetriary:
                if (regcomp(&regex, three_or_four, 0) != 0) {
                    fprintf(stderr, "Failed to compile regex pattern\n");
                    state = End;
                    break;
                }
                if (regexec(&regex, num, 1, &match, 0) == 0) {
                    state = convert_to_decimal;
                } else {
                    state = is_tetriary;
                }
                break;
            case has_illegal_characters:
                printf("%s has illegal characters\n", num);
                state = End;
                break;
            case is_tetriary:
                printf("%s is tetriary\n", num);
                state = End;
                break;
            case convert_to_decimal:
                for (size_t i = 0; i < strlen(num); i++) {
                    n_num = n_num * 10 + (num[i] - '0');
                }
                int pow = 1;
                while (n_num > 0) {
                    decimal += (n_num % 10) * pow;
                    pow *= 5;
                    n_num = (int)(n_num / 10);
                }
                printf("%d", decimal);
                state = End;
                break;
        }
    }
    return 0;
}
