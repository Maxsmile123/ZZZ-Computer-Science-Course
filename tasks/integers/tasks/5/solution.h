#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool IsMoreTwoDigits(uint64_t number) {
    return number >= 100;
}

uint64_t FirstNumber(uint64_t number) {
    return number % 10;
}

uint64_t SecondNumber(uint64_t number) {
    return number % 100 / 10;
}

uint64_t ThirdNumber(uint64_t number) {
    return number % 1000 / 100;
}

int Task() {
    bool is_solution_exist = false;
    uint64_t number = 358325775252;

    while (IsMoreTwoDigits(number)) {
        if (FirstNumber(number) == SecondNumber(number) + ThirdNumber(number)) {
            printf("%lu\n", FirstNumber(number));
            is_solution_exist = true;
        }

        number /= 10;
    }

    if (is_solution_exist == false) {
        printf("There are no numbers that satisfy the condition");
    }

    return 0;
}
