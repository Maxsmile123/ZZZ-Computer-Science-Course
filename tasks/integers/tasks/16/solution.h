#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

const int64_t SIZE = 10;
const int64_t INT_INPUT = 3425167809;

/* Функция создает массив, в котором индекс соответствует цифре, а число под этим индексом - сколько эта цифра раз
 * встречается в числе */

bool CountingUniversalDigits(int64_t a) {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // берем последнюю цифру числа
    do {
        ++arr[a % SIZE];
        a = a / SIZE;
    } while (a > 0);
    // если встречаем цифру, не встречающуюся ни разу, возвращаем false
    for (int k = 0; k < SIZE; ++k) {
        if (!arr[k]) {
            return false;
        }
    }
    return true;
}

int Task() {
    int64_t num = INT_INPUT;
    // scanf("%ld", &num);
    if (!CountingUniversalDigits(num)) {
        printf("There are numbers that do not occur even once");
    } else {
        printf("There are no numbers that do not occur once");
    }
    return 0;
}
