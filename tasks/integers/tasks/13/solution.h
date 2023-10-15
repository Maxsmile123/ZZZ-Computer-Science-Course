#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Максимальная длина 8-байтового числа (нужно для записи в строку)
const size_t MAX_NUMBER_LEN = 20;

int Task() {
    // Получаем число в виде строки
    char str_number[MAX_NUMBER_LEN];
    printf("Enter the number with leading zeros: ");
    scanf("%s", str_number);

    // Подсчитываем количество ведущих нулей, а также смотрим на знак числа
    int16_t count_of_zeros = 0;
    int16_t is_negative = 0;

    for (size_t i = 0; i < MAX_NUMBER_LEN; ++i) {
        if (str_number[i] == '-') {
            is_negative = 1;
        } else if (str_number[i] != '0') {
            break;
        } else {
            ++count_of_zeros;
        }
    }

    // Далее будем работать с введённым числом как с числом, а не строкой
    int64_t number = atol(str_number);
    number *= (is_negative) ? -1 : 1;

    // Теперь нужно узнать, сколько знаков будет в двоичном представлении
    int64_t number_copy = number;
    size_t bin_len = 0;
    while (number_copy > 0) {
        ++bin_len;
        number_copy /= 2;
    }
    
    // Переводим число в двоичную систему счисления с добавлением нулей в середину
    size_t half_bin_len = (bin_len + 1) >> 1;
    int64_t number_left = (number >> half_bin_len) << half_bin_len;
    int64_t number_right = number - number_left;
    int64_t result = (number_left << count_of_zeros) + number_right;

    printf("%ld", (is_negative) ? -result : result);

    return 0;
}
