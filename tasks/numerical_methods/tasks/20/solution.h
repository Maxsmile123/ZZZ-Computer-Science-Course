#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

double FuncNewton(double x) {
    return 0.1 * pow(x, 2.0) - x * log(x);
}

double DerivativeFuncNewton(double x) {
    return 0.2 * x - 1.0;
}

double NewtonsMethod(double (*func)(double), double (*derivative_func)(double)) {
    double a = 1.0;
    double b = 2.0;
    double x_previous = a;
    double x = b;
    while (abs(x - x_previous) > DBL_EPSILON) {
        x = x_previous - (func(x_previous) / derivative_func(x_previous));
        x_previous = x - (func(x) / derivative_func(x));
    }
    return x;
}

double FuncDichotomy(double x) {
    return tan(x) - (pow(tan(x), 3.0) / 3.0) + (pow(tan(x), 5.0) / 5.0) - (1.0 / 3.0);
}

double DichotomyMethod(double (*func)(double)) {
    double a = 0.0;
    double b = 0.8;
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