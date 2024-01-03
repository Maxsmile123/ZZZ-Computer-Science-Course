#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
const double ROOT_1 = 0.5629;
const double ROOT_2 = 3.23;
const int PRECISION = 10;

double DerivativeFunc2(double x) {
    return 3 - (4 / x);
}

double Func1(double x) {
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

double Func2(double x) {
    return 3 * x - 4 * log(x) - 5;
}

double NewtonMethod(double x0, double x1, double (*func)(double)) {
    double xn0 = (x0 + x1) / 2.0;
    double xn1 = xn0 - func(xn0) / DerivativeFunc2(xn0);
    while (fabs((xn1 - xn0) / (1.0 - ((xn1 - xn0) / (xn1 - xn0)))) >= DBL_EPSILON) {
        xn0 = xn1;
        xn1 = xn0 - func(xn0) / DerivativeFunc2(xn0);
    }
    return xn1;
}

double IterativeMethod(double x0, double x1, double (*func)(double)) {
    double x = (x0 + x1) / 2.0;
    double prev_x = x0;
    while (fabs((func(x) - x) / (1 - ((func(x) - x) / (x - prev_x)))) >= DBL_EPSILON) {
        prev_x = x;
        x = func(x) + x;
    }
    return func(x) + x;
}

void SolveEquation(double x0, double x1, double (*func)(double), double (*method)(double, double, double (*)(double)),
                   uint8_t precision, const double ex_val) {
    printf("Найденный корень:%.*f Значение для сравнения:%g\n", precision, method(x0, x1, func), ex_val);
}

int Task() {
    double start_segment_1 = 0.0;
    double end_segment_1 = 1.0;
    double start_segmetn_2 = 2.0;
    double end_segment_2 = 4.0;
    SolveEquation(start_segment_1, end_segment_1, Func1, IterativeMethod, PRECISION, ROOT_1);
    SolveEquation(start_segmetn_2, end_segment_2, Func2, NewtonMethod, PRECISION, ROOT_2);
    return 0;
}
