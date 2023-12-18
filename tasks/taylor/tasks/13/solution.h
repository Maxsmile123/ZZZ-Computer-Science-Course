#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int32_t MAX_ITERATIONS = 100;
const int64_t K = 277;
const double A = 0.0;
const long double B = 0.5;
const int N = 10;
typedef long double Ld;

Ld TylorCounting(Ld x, int* counter_of_iterations) {
    Ld tylor_result = 0.0;
    Ld power = x;
    int n = 1;
    int64_t factorial = 1;
    Ld one_tylor_member = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        *counter_of_iterations += 1;
        one_tylor_member = (power / factorial);
        if (i % 2) {
            one_tylor_member *= -1;
        }
        tylor_result += one_tylor_member;
        if (fabsl((Ld)sin(x) - tylor_result) < K * LDBL_EPSILON) {
            return tylor_result;
        }
        power *= (x * x);
        factorial *= (n + 1) * (n + 2);
        n += 2;
    }
    return 1.0;
}

void Output(Ld tylor, Ld sinus, int counter, Ld x) {
    printf("|  %.2Lf  | %.20Lf | %.20f |     %d     |\n", x, tylor, sinus, counter);
}

void PrintDashs(int n) {
    for (int i = 0; i < n; ++i) {
        printf("~");
    }
    printf("\n");
}

int Task() {
    Ld step = (B - A) / N;
    Ld tylor_result = 0.0;
    int counter_of_iterations = 0;
    printf("| Number |          Tylor         |          Real          | Iteration |\n");
    PrintDashs(72);
    for (Ld x = A; x <= B + step; x += step) {
        counter_of_iterations = 0;
        tylor_result = TylorCounting(x, &counter_of_iterations);
        Output(tylor_result, sin(x), counter_of_iterations, x);
    }
    return 0;
}
