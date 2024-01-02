#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

const int32_t MAX_ITERATIONS = 100;
const int64_t K = 277;
const double A = 0.0;
const long double B = 0.5;
const int N = 10;
const int NUMBER_OF_DASHES = 72;

long double TylorCounting(long double x, int* counter_of_iterations) {
    long double tylor_result = 0.0;
    long double power = x;
    int n = 1;
    int64_t factorial = 1;
    long double tylor_member = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        *counter_of_iterations += 1;
        tylor_member = (power / factorial) * pow(-1, i);
        tylor_result += tylor_member;
        if (fabsl((long double)sin(x) - tylor_result) < K * LDBL_EPSILON) {
            return tylor_result;
        }
        power *= (x * x);
        factorial *= (n + 1) * (n + 2);
        n += 2;
    }
    return 1.0;
}

void Output(long double tylor, long double sinus, int counter, long double x) {
    printf("|  %.2Lf  | %.20Lf | %.20Lf |     %d     |\n", x, tylor, sinus, counter);
}

void PrintDashs(int n) {
    for (int i = 0; i < n; ++i) {
        printf("~");
    }
    printf("\n");
}

int Task() {
    long double step = (B - A) / N;
    long double tylor_result = 0.0;
    int counter_of_iterations = 0;
    printf("| Number |          Tylor         |          Real          | Iteration |\n");
    PrintDashs(NUMBER_OF_DASHES);
    for (long double x = A; x <= B + step; x += step) {
        counter_of_iterations = 0;
        tylor_result = TylorCounting(x, &counter_of_iterations);
        Output(tylor_result, sin(x), counter_of_iterations, x);
    }
    return 0;
}