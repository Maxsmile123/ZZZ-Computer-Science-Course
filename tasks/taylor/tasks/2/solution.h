#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return log((1 + x) / (1 - x));
}

void TableTitleOutput() {
    printf(" -------------------------------------------------------------\n");
    printf("|    x   |    Taylor series    |      Function       | Iters |\n");
    printf("---------+---------------------+---------------------+--------\n");
}

void LineOutput(long double x, long double sum_of_taylor_series, int iter) {
    printf("| %6.2Lf | % 19.15Lf | % 19.15Lf | %5d |\n", x, sum_of_taylor_series, Func(x), iter);
}

int Task() {
    const long double a = 0.0;
    const long double b = 0.5;
    int32_t n = 10;
    int32_t k = 2;
    const long double precision = LDBL_EPSILON * k;
    const long double step = (b - a) / n;
    // scanf("%d %d", &n, &k);
    long double sum_of_taylor_series = 0;
    int iterations_count = 0;
    long double x = a;
    TableTitleOutput();
    while (n >= 0) {
        sum_of_taylor_series = 0;
        iterations_count = 0;
        while (fabsl(sum_of_taylor_series - Func(x)) >= precision) {
            long double current_term = powl(x, 2 * iterations_count + 1) / (2 * iterations_count + 1);
            sum_of_taylor_series += 2 * current_term;
            ++iterations_count;
        }
        LineOutput(x, sum_of_taylor_series, iterations_count);
        x += step;
        n--;
    }

    printf(" ----------------------------------------------------------------------------------\n");

    return 0;
}