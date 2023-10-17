#pragma once

#include <stdint.h>
#include <stdio.h>

// Возводит двойку в нужную степень
int64_t Pow2(size_t power) {
    int64_t result = 1;
    while (power > 0) {
        result *= 2;
        --power;
    }
    return result;
}

// Считывает символы, пока не встретит перевод строки. Подсчитывает среди них нули
size_t CountZeros() {
    size_t zero_count = 0;
    char zero = ' ';
    while (zero != '\n') {
        scanf("%c", &zero);
        if (zero == '0') {
            ++zero_count;
        }
    }
    return zero_count;
}

// Подсчитывает длину числа в довичном представлении
size_t CountBinaryLen(int64_t n) {
    if (n == 0) {
        return 1l;
    }
    size_t bin_len = 0;
    while (n != 0) {
        n /= 2l;
        ++bin_len;
    }
    return bin_len;
}

// Решает поставленную задачу
int64_t Solve(int64_t number, size_t zero_count, size_t bin_len) {
    int64_t result = 0;
    size_t half_bin_len = (bin_len + 1) >> 1;

    // Прибавляем правую часть числа без изменений
    result += number & (Pow2(half_bin_len) - 1);
    // Прибавляем левую часть числа, но с учётом вставленных нулей
    result += (number - result) << zero_count;
    return result;
}

const size_t ZERO_COUNT = 3;  // comment this line
const int64_t NUMBER = 7;     // comment this line

int Task() {
    // Считаем количество нулей и считываем число
    // size_t zero_count = CountZeros();  // uncomment this line
    // scanf("%ld", &number);  // uncomment this line

    // Считаем длину двоичного представления и решаем задачу
    size_t bin_len = CountBinaryLen(NUMBER);
    int64_t result = Solve(NUMBER, ZERO_COUNT, bin_len);
    printf("%ld\n", (NUMBER < 0) ? -result : result);  // answer 111 -> 100011 -> 35

    return 0;
}
