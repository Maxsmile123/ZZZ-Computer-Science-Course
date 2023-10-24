#pragma once

#include <stdint.h>
#include <stdio.h>

const int TEN = 10;

int Task() {
    // write your solution here
    int32_t number_in_10 = 0;
    int64_t number_in_2 = 0;
    int64_t multyplier = 1;
    scanf("%d", &number_in_10);
    if (number_in_10 < 0) {
        number_in_10 *= -1;
        printf("-");
    }
    while (number_in_10 > 0) {
        number_in_2 += (number_in_10 % 2) * multyplier;
        number_in_10 /= 2;
        multyplier *= TEN;
    }
    printf("%ld\n", number_in_2);
    return 0;
}