#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double FuncNewton(double x) {
    return 3 * pow(log(x), 2) + 6 * log(x) - 5;
}

double DerivativeFuncNewton(double x) {
    return (6 * log(x) + 6) / x;
}

double NewtonsMethod(double (*func)(double), double (*derivative_func)(double)) {
    double a = 1.0;
    double b = 3.0;
    double x_previous = a;
    double x = b;
    while (abs(x - x_previous) > DBL_EPSILON) {
        x = x_previous - (func(x_previous) / derivative_func(x_previous));
        x_previous = x - (func(x) / derivative_func(x));
    }
    return x;
}

double FuncDichotomy(double x) {
    return 0.6 * pow(3, x) - 2.3 * x - 3;
}

double DichotomyMethod(double (*func)(double)) {
    double a = 2.0;
    double b = 3.0;
    double middle = 0.0;
    while (abs(a - b) > DBL_EPSILON) {
        middle = (a + b) / 2.0;
        if (func(a) * func(middle) < 0.0) {
            b = middle;
        } else {
            a = middle;
        }
    }
    return a;
}

int Task() {
    double newton_result = NewtonsMethod(*FuncNewton, *DerivativeFuncNewton);
    double dichotomy_result = DichotomyMethod(*FuncDichotomy);
    printf("| Method              | Result   | table  |\n");
    printf("===========================================\n");
    printf("| Newton's Method     | %lf | 1.1183 |\n", newton_result);
    printf("| Method of Dichotomy | %lf | 0.3333 |\n", dichotomy_result);
    return 0;
}
