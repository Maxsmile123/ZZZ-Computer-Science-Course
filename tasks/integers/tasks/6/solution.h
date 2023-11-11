#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int Task() {
    int64_t number = 0;
    scanf("%ld", &number);
    int64_t digit = 0;
    int64_t difference = 0;
    while (abs(number / 100) > 0) {
        digit = abs(number / 100 % 10);
        difference = abs(abs(number % 10) - abs(number % 100 / 10));
        if (digit == difference) {
            printf("%ld %ld %li\n", digit, abs(number % 100 / 10), abs(number % 10));
        }
        number = number / 10;
    }
    return 0;
}