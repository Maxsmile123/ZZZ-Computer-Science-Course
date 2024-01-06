#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const double_t EPSILON = 1e-6;
const int MAX_ITERATIONS = 100;
const int A_N = 1;
const int B_N = 3;
const int A_D = 2;
const int B_D = 3;

double_t DychotomyFunc(double_t x) {
    return 0.6 * pow(3, x) - 2.3 * x - 3;
}

double_t Dychotomy(double_t x0, double_t x1, double_t (*func)(double_t)) {
    double_t middle_x = 0;
    double_t middle_y = 0;
    for (int i = 0; i < 100; ++i) {
        if (fabs(x1 - x0) >= EPSILON) {
            middle_x = (x0 + x1) / 2;
            middle_y = func(middle_x);
            if (middle_y > 0) {
                x1 = middle_x;
            } else {
                x0 = middle_x;
            }
        } else {
            return (x1 < -x0 ? x1 : x0);
        }
    }
    return -1;
}

double_t NyutonFunc(double_t x) {
    return 3 * pow(log(x), 2) + 6 * log(x) - 5;
}

double_t NyutonDerivative(double_t x, int counter) {
    return (6 * log(x) + 6) / x;
}

double_t Nyuton(double_t x0, double_t x_prev, double_t (*derivative)(double_t, int), double_t (*func)(double_t)) {
    int counter = 2;
    double_t x = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        x = x0 - (func(x0) / derivative(x0, counter));
        if (fabs((x - x0) / (1 - ((x - x0) / (x - x_prev)))) < EPSILON) {
            return x;
        }
        x_prev = x0;
        x0 = x;
        ++counter;
    }
    return -1;
}

void Output(double_t nyuton_result, double_t dichotomy_result) {
    printf("| Отрезок  |   Метод   | Результат  |\n");
    for (int i = 0; i < 37; ++i) {
        printf("-");
    }
    printf("\n");
    printf("|  [1, 3]  |  Ньютона  |   %.4f   |\n", nyuton_result);
    for (int i = 0; i < 37; ++i) {
        printf("-");
    }
    printf("\n");
    printf("|  [2, 3]  | Дихотомии |   %.4f   |\n", dichotomy_result);
}

int Task() {
    double_t first_num = (A_N + B_N) / 2;
    double_t nyuton_second_num = first_num - (NyutonFunc(first_num) / NyutonDerivative(first_num, 1));
    double_t nyuton_result = Nyuton(nyuton_second_num, first_num, NyutonDerivative, NyutonFunc);
    double_t dichotomy_result = Dychotomy(A_D, B_D, DychotomyFunc);
    Output(nyuton_result, dichotomy_result);
    return 0;
}
