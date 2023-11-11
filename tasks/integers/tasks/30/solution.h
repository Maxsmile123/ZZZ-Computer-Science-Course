#pragma once

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t BASE = 10;
const int64_t EXAMPLE = 123456789;
const int64_t VALUE_INT_MIN = -1247483648;

int64_t Pow(int64_t number, uint64_t degree) {
    int64_t result = number;
    if (degree == 0) {
        return 1;
    } else {
        while (degree != 1) {
            result *= number;
            degree -= 1;
        }
    }
    return result;
}

int64_t CountLen(int64_t number) {
    int64_t len_number = 0;
    number = abs(number);
    while (number > 0) {
        len_number += 1;
        number /= BASE;
    }
    return len_number;
}

int64_t CalculatingDigit(int64_t number, int64_t current_len) {
    int64_t digit = number / Pow(BASE, current_len) % BASE;
    return digit;
}

int64_t ConversionNum(int64_t number, int64_t len_number) {
    int64_t current_len = len_number;
    int64_t current_num = abs(number);
    int64_t first_digit = 0;
    int64_t second_digit = 0;
    while (current_len > 1) {
        first_digit = CalculatingDigit(current_num, current_len - 1);
        second_digit = CalculatingDigit(current_num, current_len - 2);
        if (first_digit > second_digit) {
            current_num =
                current_num - (first_digit - second_digit) * (Pow(BASE, current_len - 1) - Pow(BASE, current_len - 2));
        }
        current_len -= 2;
    }
    if (number == INT_MIN) {
        return VALUE_INT_MIN;
    } else if (number < 0) {
        return -current_num;
    } else {
        return current_num;
    }
}

int Task() {
    // write your solution here
    int64_t number = EXAMPLE;
    // scanf("%ld", &number);
    int64_t len_number = CountLen(number);
    int64_t new_number = ConversionNum(number, len_number);
    printf("%ld", new_number);
    return 0;
}