#pragma once

#include <float.h>
#include <math.h>
#include <stdio.h>

double Function1(double x) {
    return tan(x / 2) - (1 / tan(x / 2)) + x;
}

double Function2(double x) {
    return 0.4 + atan(sqrt(x));
}

double DichotomyMethod(double (*function)(double), double left, double right) {

    double mid = (left + right) / 2;

    while (fabs(function(mid)) > DBL_EPSILON) {

        if (function(left) * function(mid) < 0) {
            right = mid;
        } else {
            left = mid;
        }

        mid = (left + right) / 2;
    }
    return mid;
}

double IterationMethod(double (*function)(double), double left, double right) {

    double x0 = function((left + right) / 2);
    double x1 = function(x0);
    const size_t iterations = 1000;
    size_t count = 0;

    while ((fabs(x0 - x1) > DBL_EPSILON) || (count < iterations)) {
        x0 = x1;
        x1 = function(x0);
        count += 1;
    }
    return x1;
}

int Task() {

    printf("%.10f\n", DichotomyMethod(Function1, 1, 2));
    printf("%.10f\n", IterationMethod(Function2, 1, 2));

    return 0;
}
