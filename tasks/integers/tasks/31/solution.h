#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t BASE = 10;
const int64_t EXAMPLE = 214365879;

int64_t Max(int64_t first, int64_t second) {
    return first > second ? first : second;
}

int64_t Min(int64_t first, int64_t second) {
    return first < second ? first : second;
}

int64_t Abs(int64_t number) {
    return number > 0 ? number : -number;
}

int64_t Sign(int64_t number) {
    return number > 0 ? 1 : number < 0 ? -1 : 0;
}

int64_t Pow(int64_t number, int64_t degree) {
    int64_t multiplied_number = number;
    while (degree > 1) {
        degree--;
        multiplied_number *= number;
    }
    return multiplied_number;
}

int64_t CountLen(int64_t number) {
    int length = 0;
    while (number != 0) {
        length++;
        number = number / BASE;
    }
    return length;
}

int64_t ChangeNumber(int64_t number, int64_t len_of_number) {
    int64_t changed_number = 0;
    while (len_of_number > 1) {
        int64_t degree_of_base = Pow(BASE, len_of_number - 1);
        int64_t first_number = (number / degree_of_base);
        number %= degree_of_base;
        degree_of_base /= 10;
        int64_t second_number = (number / degree_of_base);
        number %= degree_of_base;
        len_of_number -= 2;
        changed_number =
            changed_number * 100 + Max(first_number, second_number) * 10 + Min(first_number, second_number);
    }
    if (len_of_number > 0) {
        changed_number = changed_number * 10 + number;
    }
    return changed_number;
}

int Task() {
    // write your solution here
    int64_t number = EXAMPLE;
    scanf("%ld", &number);
    int64_t len_of_number = CountLen(number);
    int64_t new_number = Sign(number) * ChangeNumber(Abs(number), len_of_number);
    printf("%ld", new_number);
    return 0;
}
