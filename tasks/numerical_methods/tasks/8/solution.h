#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const long double LOWER_LIMIT = 2.0;
const long double UPPER_LIMIT = 3.0;
const long double SOLUTION_1 = 2.4200;
const long double SOLUTION_2 = 2.0267;

long double Func1(long double x) {
    return (0.6 * pow(3, x) - 2.3 * x - 3);
}

long double Func2(long double x) {
    return (pow(x, 2) - logl(1 + x) - 3);
}

long double EquivalentFunc2(long double x) {
    return (sqrt(log(1 + x) + 3));
}

long double DychotomyMethod(long double x_0, long double x_1, long double (*function)(long double)) {
    long double middle_of_interval = 0.0;
    while (fabsl(x_1 - x_0) > DBL_EPSILON) {
        middle_of_interval = (x_1 + x_0) / 2.0;
        if ((function(x_0) * function(middle_of_interval)) < 0) {
            x_1 = middle_of_interval;
        } else {
            x_0 = middle_of_interval;
        }
    }
    return x_0;
}

long double IterativeMethod(long double x_0, long double x_1, long double (*function)(long double)) {
    long double previous_x = (x_0 + x_1) / 2.0;
    long double current_x = function(previous_x);
    while (fabsl(previous_x - current_x) >= DBL_EPSILON) {
        previous_x = current_x;
        current_x = function(previous_x);
    }
    return current_x;
}

int Task() {
    // write your solution here
    printf("-----------------------------\n");
    printf("Dychotomy Method:\nProgram: %Lf\nSolution: %Lf\n", DychotomyMethod(LOWER_LIMIT, UPPER_LIMIT, Func1),
           SOLUTION_1);
    printf("-----------------------------\n");
    printf("Iterative Method:\nProgram: %Lf\nSolution: %Lf\n",
           IterativeMethod(LOWER_LIMIT, UPPER_LIMIT, EquivalentFunc2), SOLUTION_2);
    printf("-----------------------------\n");
    return 0;
}