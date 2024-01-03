#pragma once

#include <stdint.h>
#include <stdio.h>

int64_t Abs(int64_t num) {
    if (num < 0) {
        return -num;
    }
    return num;
}

int64_t CountDigits(int64_t num) {
    num = Abs(num);
    int64_t res = 1;
    num /= 10;
    while (num > 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

int64_t Pow(int64_t base, int64_t power) {
    int64_t res = 1;
    if (power < 0) {
        return -1;  // В другой раз
    } else if (power == 0) {
        return 1;
    } else {
        while (power != 0) {
            if (power % 2 == 1) {
                res *= base;
            }
            power /= 2;
            base *= base;
        }
    }
    return res;
}

int64_t DeleteMidDigit(int64_t num) {
    int64_t len = CountDigits(num);
    int64_t mid = 0;
    int64_t left = 0;
    int64_t right = 0;
    int64_t left_pow = 0;
    int64_t right_pow = 0;
    if (len == 0) {
        return 0;
    } else {
        mid = (len - 1) / 2 + 1;             // Номер средней цифры
        left_pow = Pow(10, mid);             // Для отделения левой части числа
        right_pow = left_pow / 10;           // Для отделения правой части числа
        left = (num - num % left_pow) / 10;  // Левая часть, но уже без средней цифры
        right = num % right_pow;             // Правая часть
        return left + right;
    }
}

int Task() {
    int64_t number = -INT64_MAX;
    // scanf("%lld", &number);
    printf("%ld\n", DeleteMidDigit(number));
    return 0;
}