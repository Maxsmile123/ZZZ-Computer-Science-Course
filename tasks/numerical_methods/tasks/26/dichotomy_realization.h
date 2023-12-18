#pragma once

#include "header.h"

double_t DychotomyFunc(double_t x) {
    return (sin(log(x)) - cos(log(x)) + 2 * log(x));
}

double_t Dychotomy(double_t x0, double_t x1, double_t (*func)(double_t)) {
    double_t middle_x = 0;
    double_t middle_y = 0;
    for (int i = 0; i < 100; ++i) {
        if (fabs(x1 - x0) >= EPSILON) {
            middle_x = (x0 + x1) / 2;
            middle_y = func(middle_x);
            if (middle_y > 0) {
                x1 = middle_x;
            } else {
                x0 = middle_x;
            }
        } else {
            return (x1 < -x0 ? x1 : x0);
        }
    }
    return -1;
}