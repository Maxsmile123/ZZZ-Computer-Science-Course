#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

double Function(double x) {
    return cos(x) - pow(M_E, (pow(x, 2) / -2)) + x - 1;
}

double Func(double x) {
    return 1 - x + sin(x) - log(1 + x);
}

double SimpleIterations(double a, double b, double tol) {
    double x = a;
    double y = Func(a);
    double x1 = 0;
    double y1 = 0;
    int count = 0;

    if (y * Func(b) > 0) {
        printf("Root does not lie between %f and %f\n", a, b);
        return -1;
    }

    while (fabs(y) > tol) {
        x1 = x - y / ((1 - x) + sin(x) - (1 + x) / (1 + x));
        y1 = Func(x1);

        if (fabs(y1) <= tol) {
            return x1;
        }

        x = x1;
        y = y1;

        count += 1;
        if (count > 10000) {
            break;
        }
    }

    return x;
}

double Dichotomy(double left, double right, double eps) {
    double mid = (left + right) / 2;

    if (fabs(Function(mid)) <= eps) {
        return mid;
    } else if (Function(left) * Function(mid) < 0) {
        return Dichotomy(left, mid, eps);
    } else {
        return Dichotomy(mid, right, eps);
    }
}

int Task() {
    double left = 1;
    double right = 2;
    double eps = DBL_EPSILON;

    double a = 1;
    double b = 1.5;

    printf("The root of the equation using Dichotomy method is %.6f\n", Dichotomy(left, right, eps));

    printf("The root of the equation using iterations method if %.6f\n", SimpleIterations(a, b, eps));

    return 0;
}