#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return expl(powl(x, 2));
}

// Функция для вывода заголовка таблицы
void TableTitleOutput() {
    printf("                  Taylor series values table for f(x) = e^(x^2)\n");
    printf(" -------------------------------------------------------------\n");
    printf("|    x   |    Taylor series    |      Function       | Iters |\n");
    printf("---------+---------------------+---------------------+-------+\n");
}

// Функция для вывода строки готовой таблицы
void LineOutput(long double x, long double sum_of_taylor_series, int iter) {
    printf("| %6.2Lf | % 19.15Lf | % 19.15Lf | %5d |\n", x, sum_of_taylor_series, Func(x), iter);
}

int Task() {
    double a = 0.0;
    double b = 0.1;
    int32_t n = 5;
    int32_t k = 50;
    long double factorial = 0;
    long double sum_teylor = 0;
    // scanf("%d %d", &n, &k);
    TableTitleOutput();
    long double step = (b - a) / (double)(n - 1);
    long double precision = LDBL_EPSILON * k;
    long double x_value = a;
    int32_t iteration_num = 0;
    long double extension = LDBL_MAX;
    for (int i = 0; i < n; ++i) {
        factorial = 1.0;
        sum_teylor = 1.0;
        iteration_num = 0;
        extension = LDBL_MAX;
        while (fabsl(extension) >= precision) {
            ++iteration_num;
            factorial *= iteration_num;
            extension = powl(x_value, 2 * iteration_num) / factorial;
            sum_teylor += extension;
        }

        LineOutput(x_value, sum_teylor, iteration_num);
        x_value += step;
    }

    printf(" ----------------------------------------------------------------------------------\n");
    printf("* machine epsilon (long double) = %.10Le\n", LDBL_EPSILON);
    return 0;
}
