#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t NUMBER = 21356789;

int Task() {
    int64_t number = NUMBER;
    int64_t first_digit = 0;
    int64_t second_digit = 0;
    int64_t difference = 0;
    int stop = 1;
    while (stop <= number) {
        stop *= 10;
    }
    stop /= 10;
    for (int i = stop; i >= 10; i /= 100) {
        first_digit = (number / i) % 10;
        second_digit = (number / (i / 10)) % 10;
        difference = abs(first_digit - second_digit);
        printf("%lu%lu%lu", first_digit, second_digit, difference);
    }
    return 0;
}