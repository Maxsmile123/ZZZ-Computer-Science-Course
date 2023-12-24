#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return x / (9 + x * x);
}

// Функция для вывода заголовка таблицы
void TableTitleOutput() {
    printf("                  Taylor series values table for f(x) = x / (9 + x^2)\n");
    printf(" ----------------------------------------------------------------------------------\n");
    printf("|    x   |    Taylor series    |      Function       | Iters |      Difference     |\n");
    printf("---------+---------------------+---------------------+-------+----------------------\n");
}

// Функция для вывода строки готовой таблицы
void LineOutput(long double x, long double sum_of_taylor_series, int iter) {
    printf("| %6.2Lf | % 19.15Lf | % 19.15Lf | %5d | % 19.15Lf |\n", x, sum_of_taylor_series, Func(x), iter,
           fabsl(Func(x) - sum_of_taylor_series));
}

int Task() {
    const long double a = -1.0;                      // Нижняя граница по условию
    const long double b = 1.0;                       // Верхняя граница по условию
    int32_t n = 10;                                  // Задаем значение по умолчанию для n
    int32_t k = 50;                                  // Задаем значение по умолчанию для k
    const long double precision = LDBL_EPSILON * k;  // Точность вычислений
    const long double step = (b - a) / n;
    // scanf("%d %d", &n, &k);
    long double sum_of_taylor_series = 0;  // Сумма ряда Тейлора
    int iterations_count = 0;              // Счетчик итераций для цикла

    TableTitleOutput();

    for (long double x = a; x <= b; x += step) {
        sum_of_taylor_series = 0;
        iterations_count = 0;
        // вычисление суммы ряда Тейлора
        while (fabsl(sum_of_taylor_series - Func(x)) >= precision) {
            long double current_term =
                powl(-1, iterations_count) * powl(x, 2 * iterations_count + 1) / powl(9, iterations_count + 1);
            sum_of_taylor_series += current_term;
            ++iterations_count;
            // Если дошли до заданной точности
        }

        LineOutput(x, sum_of_taylor_series, iterations_count);
    }

    printf(" ----------------------------------------------------------------------------------\n");
    printf("* machine epsilon (long double) = %.10Le\n", LDBL_EPSILON);

    return 0;
}
