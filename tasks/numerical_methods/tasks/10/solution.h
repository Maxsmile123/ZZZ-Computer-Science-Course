#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define ld long double

const ld EXPECTED_VALUE_NEWTON = 0.6533;
const ld EXPECTED_VALUE_DICHOTOMY = -0.2877;

ld FuncNewton(ld x) {
    return 2 * x * sin(x) - cos(x);
}

ld FuncDichotomy(ld x) {
    return exp(x) + sqrt(1 + exp(2 * x)) - 2;
}

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

ld DerivativeNewton(ld x) {
    return 2 * x * cos(x) + 3 * sin(x);
}

ld NewtonMethod(ld x0, ld x1, ld (*func_newton)(ld)) {
    ld x_middle = (x0 + x1) / 2;
    ld x = x_middle - (func_newton(x_middle) / DerivativeNewton(x_middle));
    ld x_next = x - (func_newton(x) / DerivativeNewton(x));
    while (fabs((x_next - x) / (1 - (x_next - x) / (x - x_middle))) >= LDBL_EPSILON) {
        x_middle = x;
        x = x_next;
        x_next = x - (func_newton(x) / DerivativeNewton(x));
    }
    return x;
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

void SolveEquation(ld x0, ld x1, ld (*func)(ld), ld (*method)(ld, ld, ld (*)(ld)), uint8_t precision, const ld ex_val) {
    printf("%.*Lf (%Lg)\n", precision, method(x0, x1, func), ex_val);
}

int Task() {
    // write your solution here
    SolveEquation(0.4, 1.0, FuncNewton, NewtonMethod, 10, EXPECTED_VALUE_NEWTON);
    SolveEquation(-1.0, 0.0, FuncDichotomy, DichotomyMethod, 10, EXPECTED_VALUE_DICHOTOMY);
    return 0;
}