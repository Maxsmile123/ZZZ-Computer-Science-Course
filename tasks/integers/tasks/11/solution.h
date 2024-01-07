#pragma once

#include <stdint.h>
#include <stdio.h>

int32_t Len(int64_t num) {
    int32_t counter = 0;
    while (num > 0) {
        num /= 10;
        counter += 1;
    }
    return counter;
}

int Pow(int i, int32_t j) {
    int k = 1;
    while (j--) {
        k = k * i;
    }
    return k;
}

int Task() {
    int64_t num = 56243;
    int32_t a = Len(num);
    num = (Pow(10, (a - 1)) * (num % 10)) + (num / 10);
    printf("%ld", num);
    return 0;
}
