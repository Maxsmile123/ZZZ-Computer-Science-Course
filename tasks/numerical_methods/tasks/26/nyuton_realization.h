#pragma once

#include "header.h"

double_t NyutonFunc(double_t x) {
    return exp(x) - exp(-x) - 2;
}

double_t NyutonDerivative(double_t x, int counter) {
    return (counter % 2 ? exp(x) + exp(-x) : exp(x) - exp(-x));
}

double_t Nyuton(double_t x0, double_t x_prev, double_t (*derivative)(double_t, int), double_t (*func)(double_t)) {
    int counter = 2;
    double_t x = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        x = x0 - (func(x0) / derivative(x0, counter));
        if (fabs((x - x0) / (1 - ((x - x0) / (x - x_prev)))) < EPSILON) {
            return x;
        }
        x_prev = x0;
        x0 = x;
        ++counter;
    }
    return -1;
}