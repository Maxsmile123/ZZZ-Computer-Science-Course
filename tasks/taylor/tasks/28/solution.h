#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const long double A = M_PI / 5;
const long double B = (6 * M_PI) / 5;
const long double EPSILON = LDBL_EPSILON;
const int32_t K = 100000;
const int32_t N = 10;
const int32_t MAX_ITERATIONS = 100;
const long double STEP = (B - A) / N;

long double Function(long double x) {
    return (logl(fabs(2.0 * sin(x / 2.0))) * (-1.0));
}

long double Taylor(int32_t n, long double x) {
    return (cos(n * x) / n);
}

int Task() {
    long double x = A;
    long double sum = 0;
    int32_t iteration = 1;
    printf("\n==========================================================================\n");
    printf("|| Step\t x\t            Sum of row            function            i     ||\n");
    printf("\n======================================================================\n");
    while (x <= B) {
        while (iteration < MAX_ITERATIONS) {
            sum += Taylor(iteration, x);
            if (fabsl(sum - Function(x)) >= EPSILON * K) {
                iteration += 1;
            } else {
                printf(" %0.2Lf | %20.20Lf | %20.15Lf | %5d |\n", x, sum, Function(x), iteration);
                printf("-------------------------------------------------------------\n");
                iteration = 1;
                sum = 0;
                break;
            }
        }
        x += STEP;
    }
    return 0;
}