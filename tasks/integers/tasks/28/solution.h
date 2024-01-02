#pragma once

#include <stdint.h>
#include <stdio.h>

int32_t IsNegative(int32_t number) {
    if (number < 0) {
        number *= -1;
        printf("-");
    }
    return number;
}

int64_t ConvertationFromDecimalToBinary(int32_t decimal_number) {
    int64_t multyplier = 1;
    int64_t binary_number = 0;
    while (decimal_number > 0) {
        binary_number += (decimal_number % 2) * multyplier;
        decimal_number /= 2;
        multyplier *= 10;
    }
    return binary_number;
}

int Task() {
    // write your solution here
    int32_t decimal_number = 0;
    scanf("%d", &decimal_number);
    decimal_number = IsNegative(decimal_number);
    printf("%ld\n", ConvertationFromDecimalToBinary(decimal_number));
    return 0;
}