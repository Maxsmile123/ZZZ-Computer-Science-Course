#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const double PI = 3.141592653589793;
const double A = PI / 5;
const double B = PI;
const double N = 10.0;
const double PRECISION = 1000000000000.0;

const size_t MAX_ITERATIONS = 100;

long double Func(long double x) {
    return (1. / 4) * (x * x - PI * PI / 3.);
}

double Taylor(double x, size_t* iterations) {
    double answer = 0;
    size_t i = 1;

    double raise = DBL_EPSILON * PRECISION;
    while (i < MAX_ITERATIONS && fabs(raise) >= DBL_EPSILON * PRECISION) {
        raise = cos((double)i * x) / (double)(i * i);
        raise *= ((i % 2) ? -1 : 1);

        answer += raise;
        ++i;
    }

    *iterations = i;
    return answer;
}

int Task() {

    size_t iterations = 0;
    long double y_func = 0.0;
    double y_taylor = 0.0;

    printf("|                   Result of program for function (1 / 4) * (x ^ 2 - PI ^ 2 / 3) |\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("|   x    |         Func(x)         |      Taylor(x)         |number of iterations |\n");
    printf("-----------------------------------------------------------------------------------\n");

    double delta = (B - A) / N;
    for (double x = A; x <= B; x += delta) {
        iterations = 0;
        y_func = Func(x);
        y_taylor = Taylor(x, &iterations);
        printf("| %6.3lf | %22.20Lf | %22.19lf | %20lu |\n", x, y_func, y_taylor, iterations);
    }
    return 0;
}
