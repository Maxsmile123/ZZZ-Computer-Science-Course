#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool IsLessThenThreeDigits(uint64_t number) {
    const uint8_t num_100 = 100;
    return (number < num_100) ? true : false;
}

uint8_t FirstNum(uint64_t number, uint8_t num_10) {
    return number % num_10;
}

uint8_t SecondNum(uint64_t number, uint8_t num_10) {
    return (number / num_10) % num_10;
}

uint8_t ThirdNum(uint64_t number, uint8_t num_10) {
    return (number / (num_10 * num_10)) % num_10;
}

int Task() {
    uint64_t num = 0;
    scanf("%lu", &num);
    const uint8_t num_10 = 10;
    if (IsLessThenThreeDigits(num)) {
        return 0;
    }
    while (!IsLessThenThreeDigits(num)) {
        if (FirstNum(num, num_10) > SecondNum(num, num_10) && SecondNum(num, num_10) > ThirdNum(num, num_10)) {
            printf("%u%u%u\n", ThirdNum(num, num_10), SecondNum(num, num_10), FirstNum(num, num_10));
        }
        num /= num_10;
    }
    return 0;
}