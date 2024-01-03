#pragma once
#include <stdint.h>
#include <stdio.h>

uint32_t SquareOfTen(uint32_t cycle_counter) {
    uint32_t result_of_function = 1;
    for (uint32_t degree_counter = 1; degree_counter <= cycle_counter; ++degree_counter) {
        result_of_function = result_of_function * 10;
    }
    return result_of_function;
}

uint32_t ConvertFromDecimalToOctal(uint32_t input_number) {
    uint32_t output_number = 0;
    uint32_t cycle_counter = 0;
    while (input_number > 0) {
        output_number += (input_number % 8) * SquareOfTen(cycle_counter);
        ++cycle_counter;
        input_number /= 8;
    }
    return output_number;
}

int Task() {
    uint32_t input_number = 34555674;  // input number here
    uint32_t result = ConvertFromDecimalToOctal(input_number);
    printf("The result: %u\n", result);
    return 0;
}