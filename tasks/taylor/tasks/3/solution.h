#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <tgmath.h>

void Table(long double x, long double taylor_result, long double result, int i) {
    printf("------------------------------------------------------------------\n");
    printf("|%0.3Lf | %10.13Lf | %10.13Lf | %15d |\n", x, taylor_result, result, i);
}

long double Func(long double x) {
    long double ans = logl(1 + x - (2 * x * x));
    return ans;
}

int Task() {
    int n = 0;
    scanf("%d", &n);
    printf("------------------------------------------------------------------\n");
    printf("|x      |част.сумма ряда   |значении функции   |число итераций   |\n");
    int k = 1;
    long double a = -0.2;
    long double b = 0.3;
    const long double eps = DBL_EPSILON;
    for (long double x = a; x < b; x += (b - a) / n) {
        long double taylor_result = 0.0;
        long double result = Func(x);
        int iter = 0;
        for (int i = 1; i < 101; i++) {
            taylor_result += ((pow((-1), (i + 1)) * pow(2, i) - 1) * pow(x, i) / i);
            iter = i;
            if (abs(taylor_result - result) < eps * k) {
                break;
            }
        }
        Table(x, taylor_result, result, iter);
    }
    printf("------------------------------------------------------------------\n");
    return 0;
}
