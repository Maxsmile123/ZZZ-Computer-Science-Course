#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool IsIterAvailible(double x0, double x1) {
    return fabs((x1 - x0) / (1.0 - ((x1 - x0) / (x1 - x0)))) > DBL_EPSILON;
}

// block SimplyIteration functions

double IterationsMethodHelper(double x0) {
    return (3.8 - 3 * sin(sqrt(x0))) / 0.35;
}

double IterationsMethod(double a, double b) {
    double x0 = (a + b) / 2.0;
    double x1 = IterationsMethodHelper(x0);
    while (IsIterAvailible(x0, x1)) {
        x0 = x1;
        x1 = IterationsMethodHelper(x0);
    }
    return x1;
}

// block Newton method functions

double Func(double x) {
    return 0.25 * x * x * x + x - 1.2502;
}

double DerivativeFunc(double x) {
    return 0.5 * x * x + 1.0;
}

double NewtonMethod(double a, double b) {
    double x0 = (a + b) / 2.0;
    double x1 = x0 - Func(x0) / DerivativeFunc(x0);
    while (IsIterAvailible(x0, x1)) {
        x0 = x1;
        x1 = x0 - Func(x0) / DerivativeFunc(x0);
    }
    return x1;
}
int Task() {
    // block for first method - simply operations
    const double a1 = 2.0;
    const double b1 = 3.0;
    printf("%.4f Table result - 2.2985\n", IterationsMethod(a1, b1));
    // block for second method - newton
    const double a2 = 0.0;
    const double b2 = 2.0;
    printf("%.4f Table result - 1.0001\n", NewtonMethod(a2, b2));
    return 0;
}