#pragma once

#include <stdint.h>
#include <stdio.h>

int64_t Sign(int64_t number) {
    if (number < 0) {
        return -1;
    } else if (number > 0) {
        return 1;
    } else {
        return 0;
    }
}

int64_t DeleteEvenDigits(int64_t number, int64_t sign_of_number) {
    int64_t reversed_result = 0;
    int64_t digit = 0;
    while (number != 0) {
        digit = number % 10 * sign_of_number;
        number /= 10;
        if (digit % 2 != 0) {
            reversed_result *= 10;
            reversed_result += digit;
        }
    }
    return reversed_result;
}

int64_t Reverse(int64_t number_to_reverse) {
    int64_t result = 0;
    int64_t digit = 0;
    while (number_to_reverse > 0) {
        digit = number_to_reverse % 10;
        number_to_reverse /= 10;
        result *= 10;
        result += digit;
    }
    return result;
}

int Task() {
    int64_t number = 0;
    int64_t sign_of_number = 0;
    scanf("%li", &number);
    sign_of_number = Sign(number);
    number = DeleteEvenDigits(number, sign_of_number);
    number = Reverse(number);
    number *= sign_of_number;
    printf("%li", number);
    return 0;
}