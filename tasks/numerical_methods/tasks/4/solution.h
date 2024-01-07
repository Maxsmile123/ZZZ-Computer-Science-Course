#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const int32_t MAX_ITERATION = 100;
const double_t DICHOTOMYLEFTBORDER = 0;
const double_t DICHOTOMYRIGHTBORDER = 1;
const double_t NEWTONLEFTBORDER = 1;
const double_t NEWTONYRIGHTBORDER = 3;

double_t NewtonFunction(double_t x) {
    return (3 * x - 14 + exp(x) - exp(-x));
}

double_t NewtonFunctionPrime(double_t x) {
    return (3 + exp(x) + exp(-x));
}

double_t DichotomyFunction(double_t x) {
    return (sqrt(1 - x) - tan(x));
}

double_t DichotomyMethod(double_t left, double_t right, double_t (*function)(double_t)) {
    double_t middle = (right - left) / 2;
    for (int32_t i = 0; i < MAX_ITERATION; ++i) {
        if (fabs(right - left) <= DBL_EPSILON) {
            return middle;
        } else {
            if (function(left) * function(middle) < 0) {
                right = middle;
            } else {
                left = middle;
            }
            middle = (right + left) / 2;
        }
    }
    return middle;
}

double_t NewtonMethod(double_t left, double_t right, double_t (*function)(double_t),
                      double_t (*function_prime)(double_t)) {
    double_t previous = (right - left) / 2;
    double_t current = previous - function(previous) / function_prime(previous);
    double_t next = current - function(current) / function_prime(current);
    int32_t iteration_counter = 0;
    while ((fabs((next - current) / (1 - ((next - current) / (current - previous)))) > DBL_EPSILON) &&
           (iteration_counter <= MAX_ITERATION)) {
        previous = current;
        current = next;
        next = current - function(current) / function_prime(current);
        ++iteration_counter;
    }
    // printf("debuginfo %d \n", iteration_counter);
    return next;
}

int Task() {
    double_t dichotomy_result = DichotomyMethod(DICHOTOMYLEFTBORDER, DICHOTOMYRIGHTBORDER, DichotomyFunction);
    double_t newton_result = NewtonMethod(NEWTONLEFTBORDER, NEWTONYRIGHTBORDER, NewtonFunction, NewtonFunctionPrime);
    printf("| Newton method    | Segment: [%2.lf,%2.lf] | Calculated result: %10.8lf | Given result: 2.0692 |\n",
           NEWTONLEFTBORDER, NEWTONYRIGHTBORDER, newton_result);
    printf("| Dichotomy method | Segment: [%2.lf,%2.lf] | Calculated result: %10.8lf | Given result: 0.5768 |\n",
           DICHOTOMYLEFTBORDER, DICHOTOMYRIGHTBORDER, dichotomy_result);
    return 0;
}