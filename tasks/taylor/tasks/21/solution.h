#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return (((x * x) / 4) + (x / 2) + 1) * expl(x / 2);
}

long double Factorial(int32_t x) {
    if (x == 0 || x == 1) {
        return 1.0;
    }
    return x * Factorial(x - 1);
}

// функция для вывода заголовка таблицы
void TableTitle() {
    printf("       Taylor series values table for f(x) = ((x^2 / 4) + (x / 2) + 1) * e^x/2\n");
    printf(" ----------------------------------------------------------------------------------\n");
    printf("|    X   |    Taylor series    |      Function       | Iters |      Difference     |\n");
    printf("---------+---------------------+---------------------+-------+----------------------\n");
}

// функция вывода строки в таблицу для заданных значений "x"
void LineOutput(long double x, long double seriesSum, int iter) {
    printf("| %6.2Lf | % 19.15Lf | % 19.15Lf | %5d | % 19.15Lf |\n", x, seriesSum, Func(x), iter,
           fabsl(Func(x) - series_sum));
}

int Task() {
    // данные границы из условия
    const long double start_a = 0.1;
    const long double end_b = 0.6;

    // задаем кол-во итераций для n
    int32_t n = 10;
    // задаем значение для m
    int32_t m = 50;

    // точность вычислений
    const long double calculation_accuracy = LDBL_EPSILON * m;
    // шаг итераций
    const long double iteration_step = (end_b - start_a) / n;

    // вывод заголовка таблицы
    TableTitle();

    for (long double x = start_a; x <= end_b; x += iteration_step) {
        // сумма ряда
        long double series_sum = 0;
        // кол-во итераций
        int iterations = 0;

        // вычисление ряда Тейлора
        while (fabsl(series_sum - Func(x)) >= calculation_accuracy) {
            long double current_term = (powl(iterations, 2) + 1) / Factorial(iterations) * powl((x / 2), iterations);
            series_sum += current_term;
            ++iterations;
        }
        // вывод получившихся значений
        LineOutput(x, series_sum, iterations);
    }

    return 0;
}
