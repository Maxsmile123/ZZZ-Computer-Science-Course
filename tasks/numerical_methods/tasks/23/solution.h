#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double DihotomyMethod(long double left, long double right, long double (*func)(long double xn)) {
    long double midle = (left + right) / 2;
    while (fabs(right - left) >= DBL_EPSILON) {
        if (func(left) * func(midle) < 0) {
            right = midle;
        } else {
            left = midle;
        }
        midle = (left + right) / 2;
    }
    return midle;
}

double NewtonMethod(double left, double right, double (*func)(double xn), double (*dfunc)(double xn)) {
    double x_last = 0.0;
    double x_current = (left + right) / 2;
    while (fabs(x_current - x_last) >= DBL_EPSILON) {
        x_last = x_current;
        x_current = x_last - func(x_last) / dfunc(x_last);
    }
    return x_current;
}

long double FunctionDihotomy(long double x) {
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}

double FunctionNewton(double x) {
    return 3 * x - 4 * log(x) - 5;
}

double Derivative(double x) {
    return 3.0 - 4 / x;
}

const double ANSWER_ITERATION_METHOD = 1.8756;
const double ANSWER_NEWTON_METHOD = 3.23;

int Task() {
    printf("Newton method - %.10lf, answer: %.4lf\n", NewtonMethod(2.0, 4.0, FunctionNewton, Derivative),
           ANSWER_NEWTON_METHOD);
    printf("Dihotomy method - %.10Lf, answer: %.4lf\n", DihotomyMethod(1.0, 2.0, FunctionDihotomy),
           ANSWER_ITERATION_METHOD);
    printf("\n");
    return 0;
}