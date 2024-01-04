#pragma once

#include <stdint.h>
#include <stdio.h>

int32_t Findlen(int64_t num) {
    int32_t counter = 0;
    while (num > 0) {
        num /= 10;
        counter += 1;
    }
    return counter;
}

int pow1(int i, int32_t j) {
    int k = 1;
    while (j--) {
        k = k * i;
    }
    return k;
}

int Task() {
    // write your solution here
    int64_t num = 31213;
    int32_t c = Findlen(num);
    num = pow1(10, c) + num;
    num = num * 10 + 1;
    printf("%ld", num);
}
