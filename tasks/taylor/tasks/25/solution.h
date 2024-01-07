#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const long double A = 0.0;
const long double B = 1.0;
const int32_t K = 50;
const int32_t ITERATIONS = 100;
const long double PRECISION = LDBL_EPSILON * K;

void Function(long double x, long double *res1) {
    (*res1) = 1 / (4 - powl(x, 4));
}

void Taylor(const long double *x, const long double *res1, long double *res2, int32_t *count) {
    while (fabsl((*res2) - (*res1)) > PRECISION) {
        (*res2) += (powl(*x, 4 * (*count)) / powl(4, (*count) + 1));
        ++(*count);
    }
}

int Task() {

    int32_t n = 10;
    // scanf("%d", &n);

    const long double step = (B - A) / n;
    long double res1 = 0;
    long double res2 = 0;
    int32_t count = 0;

    printf(
        "------------------------------------------------------------\n|     x    |       Taylor      |      Function  "
        "   | Iters |\n");

    for (long double x = A; x <= B; x += step) {

        Function(x, &res1);
        Taylor(&x, &res1, &res2, &count);

        printf("| %Lf | %1.15Lf | %1.15Lf | %5d |\n", x, res1, res2, count);
        count = 0;
        res2 = 0;
    }

    printf("------------------------------------------------------------\n");

    return 0;
}
