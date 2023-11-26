#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t INPUT_NUMBER = -12345;

int64_t Abs(int64_t num) {
    if (num < 0) {
        return num *= -1;
    } else {
        return num;
    }
}

int64_t Sign(int64_t num) {
    if (num > 0) {
        return 1;
    } else if (num < 0) {
        return -1;
    } else {
        return 0;
    }
}

int64_t DecrementOfEvenNumbers(int64_t number) {
    int64_t new_number = 0;
    int64_t value_power_of_ten = 1;
    int64_t digit = 0;
    while (number >= value_power_of_ten) {
        digit = (number / value_power_of_ten) % 10;
        if (digit) {
            digit -= (digit % 2 == 0);
        }
        new_number += digit * value_power_of_ten;
        value_power_of_ten *= 10;
    }
    return new_number;
}

int Task() {
    int64_t input_number = INPUT_NUMBER;
    if (input_number == INT64_MIN) {
        printf("-%ld7\n", DecrementOfEvenNumbers(input_number / -10));
    } else {
        int64_t sign_of_number = Sign(input_number);
        input_number = Abs(input_number);
        printf("%ld\n", sign_of_number * DecrementOfEvenNumbers(input_number));
    }
    return 0;
}
