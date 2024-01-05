#pragma once

#include <stdint.h>
#include <stdio.h>

int64_t Sign(int64_t x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    }
}

int Task() {
    int64_t num;
    while (scanf("%ld", &num) == 1) {
        if (Sign(num) == 1) {
            printf("%ld\n", num);
            break;
        } else {
            num *= -1;
        }
        int64_t multiple = 1;
        int64_t new_num = 0;
        while (num != 0) {
            new_num += (9 - (num % 10)) * multiple;
            multiple *= 10;
            num /= 10;
        }
        printf("%ld\n", new_num);
        break;
    }
    return 0;
}
