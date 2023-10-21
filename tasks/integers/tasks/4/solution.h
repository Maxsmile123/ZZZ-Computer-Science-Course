#pragma once

#include <stdint.h>
#include <stdio.h>

int Task() {
    uint64_t number = 0;
    scanf("%lu", &number);
    uint8_t first_ch = 0;
    uint8_t second_ch = 0;
    uint8_t third_ch = 0;
    const uint8_t num_10 = 10;
    if (number < num_10 * num_10) {
        return 0;
    }
    while (number > 0) {
        if ((number % num_10) > ((number / num_10) % num_10) &&
            ((number / num_10) % num_10 > (number / num_10 * num_10) % num_10)) {
            first_ch = number % num_10;
            second_ch = (number / num_10) % num_10;
            third_ch = (number / num_10 * num_10) % num_10;
            printf("%u%u%u\n", third_ch, second_ch, first_ch);
        }
        number /= num_10;
    }
    return 0;
}