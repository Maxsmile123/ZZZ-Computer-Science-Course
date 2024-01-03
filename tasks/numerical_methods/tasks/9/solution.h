#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const double ROOT_1 = 2.0267;
const double ROOT_2 = 0.6533;

double FuncIterations(double x) {
    return x * x - log(1 + x) - 3;
}

double FuncNewton(double x) {
    return 2 * x * sin(x) - cos(x);
}

void IterationsMethod(double x_0, double (*func_iterations)(double x)) {
    double x = func_iterations(x_0);
    double x_next = func_iterations(x);
    printf("The function takes the following values using the simple iteration method:\n");
    for (int8_t i = 0; i < 2; ++i) {
        printf("%lf %lf %lf\n", x_0, x, x_next);
        x_0 = x;
        x = x_next;
        x_next = func_iterations(x_next);
    }
    printf(
        "For x = %lf, the function x * x - log(1 + x) - 3 is not defined, since the sub-log expression is < 0,\n"
        "therefore, there is no solution using this method.\n\n",
        x);
}

double DerivativeNewton(double x) {
    return 2 * x * cos(x) + 3 * sin(x);
}

double NewtonMethod(double x_0, double (*func_newton)(double x)) {
    double x = x_0 - (func_newton(x_0) / DerivativeNewton(x_0));
    double x_next = x - (func_newton(x) / DerivativeNewton(x));
    while (fabs((x_next - x) / (1 - (x_next - x) / (x - x_0))) >= DBL_EPSILON) {
        x_0 = x;
        x = x_next;
        x_next = x - (func_newton(x) / DerivativeNewton(x));
    }
    return x;
}

void PrintAnswer(double x, double root) {
    printf("The root found using Newton's method = %lf\nError = %lf - %lf = %lf\n", x, root, x, fabs(root - x));
}

int Task() {
    // write your solution here
    double beginning_1 = 2;
    double ending_1 = 3;
    double beginning_2 = 0.4;
    double ending_2 = 1;
    IterationsMethod((ending_1 + beginning_1) / 2, FuncIterations);
    double x2 = NewtonMethod((ending_2 + beginning_2) / 2, FuncNewton);
    PrintAnswer(x2, ROOT_2);
    return 0;
}