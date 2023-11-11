#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t NUMBER = 555;  // comment this line
const int64_t TEN = 10;
const int64_t HUNDRED = 100;

int64_t IsLessThenThreeDigits(int64_t num) {
    if (num < HUNDRED) {
        printf("Слишком мало разрядов");
        return 1;
    }
    return 0;
}
int64_t Abs(int64_t x) {
    if (x > 0) {
        return x;
    } else {
        return x * (-1);
    }
}

int Task() {
    if (NUMBER < -9223372036854775807) {
        printf("22337203685477580");  // обработка самого маленького числа
        return 0;
    }
    // scanf("%lld", &number); // uncomment this line
    int64_t number = Abs(NUMBER);  // comment this line

    if (IsLessThenThreeDigits(number)) {
        return 0;  // Числа до трех разрядов без изменений
    }

    // Отсекаем последнюю цифру
    number /= TEN;

    // Отсекаем первую цифру
    int64_t max_digit_of_number = 1;
    while (number / (max_digit_of_number * TEN) > 0) {
        max_digit_of_number *= TEN;
    }
    number %= max_digit_of_number;

    printf("%ld\n", number);

    return 0;
}