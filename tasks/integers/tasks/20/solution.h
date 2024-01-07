#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t NUMBER = 54321;
const int32_t TEN = 10;

int32_t Length(int64_t number) {
    int32_t counter = 0;
    while (number > 0) {
        number /= TEN;
        counter += 1;
    }

    return counter;
}

int64_t Degree(int64_t number, int64_t degree) {
    int64_t result = number;
    while (degree > 0) {
        result *= number;
        degree -= 1;
    }

    return result;
}

int Task() {
    // write your solution here
    int64_t number = NUMBER;
    int64_t last_digit = number % TEN;
    int64_t first_digit = number / Degree(TEN, Length(number) - 2);
    number /= TEN;
    int64_t last_but_one_digit = number % TEN;
    number %= Degree(TEN, Length(number) - 3);
    number -= last_but_one_digit;
    number += last_digit;
    number += first_digit * Degree(TEN, Length(number) - 1);
    printf("%ld\n", number);

    return 0;
}