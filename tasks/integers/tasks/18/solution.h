#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t BASE = 10;
const int64_t EXAMPLE = 1234;

int Task() {
    // write your solution here
    if (EXAMPLE == INT64_MIN) {
        printf("-9023372036854775828");
    } else {

        int64_t number_with_sign = EXAMPLE;
        int64_t sign = 0;
        if (number_with_sign < 0) {
            sign = -1;
        } else {
            sign = 1;
        }

        int64_t number = abs(EXAMPLE);
        int64_t copy_number = abs(EXAMPLE);
        int64_t second_digit = 0;
        int64_t penultimate_digit = (number / BASE) % BASE;
        int64_t position_of_second_digit = 1;
        while (copy_number > BASE) {
            second_digit = copy_number % BASE;
            copy_number = copy_number / BASE;
            position_of_second_digit = position_of_second_digit * BASE;
        }
        position_of_second_digit = position_of_second_digit / BASE;

        int64_t new_number = (number - second_digit * position_of_second_digit - penultimate_digit * BASE +
                              penultimate_digit * position_of_second_digit + second_digit * BASE) *
                             sign;
        printf("%ld\n", new_number);
    }
    return 0;
}