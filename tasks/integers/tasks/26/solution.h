#pragma once

#include <stdint.h>
#include <stdio.h>

int64_t Power(int64_t num1, int64_t num2) {
    int64_t res = 1;
    for (int64_t k = 1; k <= num2; k++) {
        res *= num1;
    }
    return res;
}

int Task() {
    // write your solution here
    int64_t number = 0;
    int64_t count = 1;
    scanf("%ld", &number);
    int64_t number_save = number;
    while (number / 10 != 0) {
        number = number / 10;
        count++;
    }
    number = number_save;
    int64_t number_1 = 0;
    int64_t number_2 = 0;
    int64_t result = 0;
    while (count >= 2) {
        number_1 = number / Power(10, count - 1);
        number_2 = number / Power(10, count - 2);
        number_2 %= 10;
        number = number % (int64_t)Power(10, count - 2);
        count -= 2;
        result = result * 100 + 10 * number_1 + number_2;
        if (number_1 + number_2 < 10) {
            result = result * 10 + number_1 + number_2;
        }
    }
    if (number) {
        result = result * 10 + number;
    }
    printf("%ld\n", result);
    return 0;
}
