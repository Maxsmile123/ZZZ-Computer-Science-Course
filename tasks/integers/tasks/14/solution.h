#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t TEN = 10;
const int64_t INPUT_NUM = 12345678987654321;

int Task() {
    int64_t num = INPUT_NUM;
    int flag = 0;
    // scanf("%lld", &num);
    if (num < TEN) {
        printf("No");
    } else {
        while (num >= TEN) {
            if (num % TEN == (num / TEN) % TEN) {
                flag = 1;
                break;
            }
            num /= TEN;
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}