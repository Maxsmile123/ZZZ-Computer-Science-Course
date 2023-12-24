#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

const double APPROXIMATION_VALUE_1 = 1.1474;
const double APPROXIMATION_VALUE_2 = 2.0692;
const int ACCURACY = 10;

double Func1(double x) {
    return 1 - x + sin(x) - log(1 + x);
}

double Func2(double x) {
    return 3 * x - 14 + exp(x) - exp(-x);
}

double MethodOfIterative(double x0, double x1, double (*func)(double)) {
    double x = (x0 + x1) / 2.0;
    double prev_x = x0;
    while (fabsl((func(x) - x) / (1 - ((func(x) - x) / (x - prev_x)))) >= DBL_EPSILON) {
        prev_x = x;
        x = func(x) + x;
    }
    return func(x) + x;
}

double Func2Derivative(double x) {
    return 3 + exp(x) + exp(x);
}

double MethodOfNewton(double x0, double x1, double (*func)(double)) {
    double xn0 = 0.0;
    double xn1 = (x0 + x1) / 2;
    while (fabs(xn1 - xn0) >= DBL_EPSILON) {
        xn0 = xn1;
        xn1 = xn0 - func(xn0) / Func2Derivative(xn0);
    }
    return xn1;
}

void OutputAnswer(double x0, double x1, double (*func)(double), double (*method)(double, double, double (*)(double)),
                  uint8_t accuracy, const double ex_val) {
    printf("-Отрезок: [%.2lf, %.2lf]\n", x0, x1);
    printf("-Найденный корень: %.*f\n", accuracy, method(x0, x1, func));
    printf("-Значение для сравнения: %g\n", ex_val);
    printf("-------------------------------\n");
}

int Task() {
    double start_section_1 = 1.0;
    double start_section_2 = 1.0;
    double end_section_1 = 1.5;
    double end_section_2 = 3.0;
    printf("-------------------------------\n");
    printf("Method: Iterations\n");
    OutputAnswer(start_section_1, end_section_1, Func1, MethodOfIterative, ACCURACY, APPROXIMATION_VALUE_1);
    printf("Method: Newton\n");
    OutputAnswer(start_section_2, end_section_2, Func2, MethodOfNewton, ACCURACY, APPROXIMATION_VALUE_2);
    return 0;
}
