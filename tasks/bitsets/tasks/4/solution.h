#pragma once

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t Bitset;

const int SIZE = 10;

int Hah() {
    int* a = (int*)malloc(SIZE);
    free(a);
    return printf("Hello, man!\n");
}

int Task() {
    // write your solution here
    Hah();
    Bitset set = 0;
    return set;
}