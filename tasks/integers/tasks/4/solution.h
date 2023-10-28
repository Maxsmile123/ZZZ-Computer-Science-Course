#pragma once

#include <stdint.h>
#include <stdio.h>

const uint8_t NUM_10 = 10;

uint8_t ThirdDigit(uint64_t number) {
    return (number / (NUM_10 * NUM_10)) % NUM_10;
}

uint8_t SecondDigit(uint64_t number) {
    return (number / NUM_10) % NUM_10;
}

uint8_t FirstDigit(uint64_t number) {
    return number % NUM_10;
}

int Task() {
    uint64_t number = 0;
    scanf("%lu", &number);
    uint8_t first_num = 0;
    uint8_t second_num = 0;
    uint8_t third_num = 0;
    if (number < NUM_10 * NUM_10) {
        return 0;
    }
    while (number > 0) {
        first_num = FirstDigit(number);
        second_num = SecondDigit(number);
        third_num = ThirdDigit(number);
        if (first_num > second_num && second_num > third_num) {
            printf("%u%u%u\n", third_num, second_num, first_num);
        }
        number /= NUM_10;
    }
    return 0;
}