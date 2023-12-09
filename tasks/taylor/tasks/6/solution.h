#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return (exp(x) - exp(-x)) / 2;
}

// Вывод заголовка таблицы
void TableTitleOutput() {
    printf("-----------------------------------------------------------------\n");
    printf("  Taylor series values table for f(x) = (exp(x) - exp(-x)) / 2  |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|     X     |       Taylor      |      Function     | Iteration |\n");
    printf("-----------------------------------------------------------------\n");
}

// Вывод строки таблицы
void LineOutput(long double x, long double row_of_taylor, int count_iterations) {
    printf("| %.7Lf | %.15Lf | %.15Lf |     %.2d    |\n", x, row_of_taylor, Func(x), count_iterations);
    printf("-----------------------------------------------------------------\n");
}

int Task() {
    TableTitleOutput();
    double a = 0.0;
    double b = 1.0;
    int32_t n = 6;
    int32_t k = 50;
    int32_t count_iterations = 0;
    long double factorial = 0;
    long double row_of_taylor = 0;
    long double step = (b - a) / (double)(n - 1);
    long double precision = LDBL_EPSILON * k;
    long double x = a;
    for (int i = 0; i < n; ++i) {
        count_iterations = 0;
        row_of_taylor = 0.0;
        long double extension = LDBL_MAX;
        factorial = 1.0;
        while (fabsl(extension) >= precision) {
            count_iterations = count_iterations + 1;
            factorial = factorial * count_iterations;
            if (count_iterations % 2 != 0) {
                extension = pow(x, count_iterations) / factorial;
                row_of_taylor = row_of_taylor + extension;
            }
        }
        LineOutput(x, row_of_taylor, count_iterations);
        x = x + step;
    }
    printf("* machine epsilon (long double) = %.10Le\n", LDBL_EPSILON);
    return 0;
}
