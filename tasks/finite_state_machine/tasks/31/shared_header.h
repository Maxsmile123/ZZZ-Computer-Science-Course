#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    START,         // Начальное состояние
    READ_CHAR,     // Чтение и анализ символа
    PRINT_BINARY,  // Печать каждого третьего двоичного числа
    ERROR_STATE,   // Обработка разных ошибок при выполнении программы
    END,           // Конечное состояние
    STATECOUNT     // Общее количество состояний
} StateName;

typedef struct State State;

const int64_t BITS_COUNT = 32;

typedef struct {
    State *pipeline;
    StateName cur_state;
    char current_binary_state[BITS_COUNT + 1];  // Для хранения двоичного числа как строки
    int binary_counter;                         // Счетчик двоичных чисел
    int current_length;                         // Текущая длина двоичного числа
    char current_char;                          // Текущий считываемый символ
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine *);
} State;
