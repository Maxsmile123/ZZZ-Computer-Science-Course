#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t TEN = 10;

int Task() {
    int64_t num = 0;
    bool flag = false;
    scanf("%lld", &num);
    if (num < TEN) {
        printf("No");
    } else {
        while (num >= TEN) {
            if (num % TEN == (num / TEN) % TEN) {
                flag = true;
                break;
            }
            num /= TEN;
        }
        if (flag) {
            printf("Yes");
        } else {
            printf("No");
        }
    }
    return 0;
}