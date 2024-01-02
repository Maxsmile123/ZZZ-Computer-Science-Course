#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define ld long double

const ld EXPECTED_VALUE_1 = -0.2877;
const ld EXPECTED_VALUE_2 = 2.8459;

int8_t Sign(ld x) {
    if (fabsl(x) < LDBL_EPSILON) {
        return 0;
    } else if (x > 0.0) {
        return 1;
    }
    return -1;
}

bool HaveDifferentSign(ld x, ld y) {
    return Sign(x) != Sign(y);
}

ld Func1(ld x) {
    return exp(x) + sqrt(1 + exp(2 * x)) - 2;
}

ld Func2(ld x) {
    return log(x) - x + 1.8;
}

ld DichotomyMethod(ld x0, ld x1, ld (*func)(ld)) {
    ld x_middle = 0;
    while (fabsl(x0 - x1) >= LDBL_EPSILON) {
        x_middle = (x0 + x1) / 2.0;
        if (HaveDifferentSign(func(x0), func(x_middle))) {
            x1 = x_middle;
        } else {
            x0 = x_middle;
        }
    }
    return (x0 + x1) / 2.0;
}

ld IterativeMethod(ld x0, ld x1, ld (*func)(ld)) {
    ld x = (x0 + x1) / 2.0;
    ld prev_x = x0;
    while (fabsl((func(x) - x) / (1 - ((func(x) - x) / (x - prev_x)))) >= LDBL_EPSILON) {
        prev_x = x;
        x = func(x) + x;
    }
    return func(x) + x;
}

void SolveEquation(ld x0, ld x1, ld (*func)(ld), ld (*method)(ld, ld, ld (*)(ld)), uint8_t precision, const ld ex_val) {
    printf("%.*Lf (%Lg)\n", precision, method(x0, x1, func), ex_val);
}

int Task() {
    SolveEquation(-1.0, 0.0, Func1, DichotomyMethod, 10, EXPECTED_VALUE_1);
    SolveEquation(2.0, 3.0, Func2, IterativeMethod, 10, EXPECTED_VALUE_2);
    return 0;
}