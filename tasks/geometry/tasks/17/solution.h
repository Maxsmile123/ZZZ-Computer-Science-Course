#pragma once

#include <stdint.h>
#include <stdio.h>

const int32_t I = 13;
const int32_t J = 19;
const int32_t L = 14;
const int32_t ITERATIONS = 50;

typedef struct {
    int32_t x;
    int32_t y;
} Point;

int32_t Abs(int a) {
    return ((a >= 0) ? a : (a * -1));
}

int32_t Sign(int32_t a) {
    return ((a < 0) ? -1 : 1);
}

int32_t Max(int32_t a, int32_t b) {
    return ((a > b) ? a : b);
}

int32_t Min(int32_t a, int32_t b) {
    return ((a < b) ? a : b);
}

int32_t Mod(int32_t a, int32_t x) {

    if (a < 0) {
        return x + (a % x);
    }
    return a % x;
}

int32_t CheckZone(Point p) {
    return ((p.x + p.y + 10 <= 0) && (p.x + p.y + 20 >= 0));
}

int Task() {

    Point a;
    a.x = I;
    a.y = J;

    int32_t l = L;
    int32_t count = 0;

    for (size_t k = 0; k < ITERATIONS; ++k) {

        if (CheckZone(a)) {
            count += 1;
        }

        int32_t i = Sign(a.x + 1) * Abs(Abs((int32_t)k - a.y) - Abs(a.x - l));
        int32_t j = Mod(a.y, 20) + Max(Mod(a.x, 20), Min(a.y - (int32_t)k, l - (int32_t)k)) - 10;
        int32_t q = Mod((int32_t)k * (a.x + 1) * (a.y + 2) * (l + 3), 20);

        a.x = i;
        a.y = j;
        l = q;
    }

    printf("Number of points in the zone - %d\n", count);

    return 0;
}
