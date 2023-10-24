#pragma once

#include <stdint.h>
#include <stdio.h>

int Task() {
    // write your solution here
    int32_t number_in_10;
    int64_t number_in_2;
    int64_t multyplier = 1;
    scanf("%d", &number_in_10);
    if (number_in_10 < 0) {
        number_in_10 *= -1;
        printf("-");
    }
    while (number_in_10 > 0) {
        number_in_2 += (number_in_10 % 2) * multyplier;
        number_in_10 /= 2;
        multyplier *= 10;
    }
    printf("%ld", number_in_2);
    return 0;
}