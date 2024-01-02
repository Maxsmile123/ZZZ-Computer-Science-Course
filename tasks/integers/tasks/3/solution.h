#pragma once

#include <stdint.h>
#include <stdio.h>

int32_t MaxSumOfTriplets(int32_t num) {
    int32_t max_sum = 0;
    int32_t first_digit = num % 10;
    num /= 10;
    int32_t second_digit = num % 10;
    num /= 10;
    int32_t third_digit = num % 10;
    while (num > 0) {
        int32_t current_sum = first_digit + second_digit + third_digit;
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        num /= 10;
        first_digit = num % 10;
        num /= 10;
        second_digit = num % 10;
        num /= 10;
        third_digit = num % 10;
    }
    return max_sum;
}

int Task() {
    int32_t num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    int32_t max_sum = MaxSumOfTriplets(num);
    printf("Maximum sum of triplets: %dn", max_sum);
    return 0;
}
