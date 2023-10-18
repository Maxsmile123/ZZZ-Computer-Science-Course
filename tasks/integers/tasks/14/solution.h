#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t TEN = 10;
const int64_t INPUT_NUM = -123456789;

bool IsOneDigit(int64_t x) {
    return -TEN < x and x < TEN;
}

bool HasEqualPairDigits(int64_t num) {
    while (num >= TEN or num <= -TEN) {
        if (num % TEN == (num / TEN) % TEN) {
            return true;
            break;
        }
        num /= TEN;
    }
    return false;
}

int Task() {
    int64_t num = INPUT_NUM;
    // scanf("%lld", &num);
    if (IsOneDigit(num)) {
        printf("No\n");
    } else {
        if (HasEqualPairDigits(num)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}