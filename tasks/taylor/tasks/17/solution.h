#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return 0.5 * log(x);
}

long double Degree(long double exp, uint8_t n) {
    long double res_exp = 1.0;
    while (n > 0) {
        res_exp *= exp;
        --n;
    }
    return res_exp;
}

long double TaylorSeriesTerm(long double x, int iter) {
    return (long double)1 / (2 * iter + 1) * Degree((x - 1.0) / (x + 1.0), 2 * iter + 1);
}

bool IsBreakCalc(long double x, long double tailor_result, uint8_t precision) {
    return fabsl(tailor_result - Func(x)) < DBL_EPSILON * precision;
}

long double TailorResult(long double x, uint16_t iterations, uint8_t precision, uint8_t* num_taylor_it) {
    *num_taylor_it = 0;
    long double result = 0.0;
    for (int i = 0; i < iterations; ++i) {
        ++(*num_taylor_it);
        result += TaylorSeriesTerm(x, i);
        if (IsBreakCalc(x, result, precision)) {
            break;
        }
    }
    return result;
}

void PrintTable(long double x, long double tayl_res, long double func_res, uint8_t num_tayl_it) {
    static int it = 0;
    if (it == 0) {
        printf(" ----------------------------------------------------\n");
        printf("|    x   |   Taylor series |     Function    | Iters| \n");
        printf("---------+-----------------+-----------------+-------\n");
    }
    printf("%.6Lf | %.12Lf | %.12Lf | %u\n", x, tayl_res, func_res, num_tayl_it);
    ++it;
}

int Task() {
    uint8_t precision = 40;
    uint8_t num_taylor_it = 0;
    uint8_t n = 10;
    uint16_t iterations_for_tailor = 100;
    const long double a = 0.2;
    const long double b = 0.7;
    long double step = (b - a) / n;
    long double x = a;
    long double taylor_result = 0.0;
    for (int i = 0; i <= n; ++i) {
        taylor_result = TailorResult(x, iterations_for_tailor, precision, &num_taylor_it);
        PrintTable(x, Func(x), taylor_result, num_taylor_it);
        x += step;
    }
    return 0;
}