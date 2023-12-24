#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef enum {
    ZERO,  // Состояние поиска знака '0', с которого бы начиналось HEX число
    PREFIX,  // Если после 0 идёт x, то машина встретила правильное начало числа
    SKIP,  // Шестнадцатеричные числа идут парами, пропустим первый знак
    HEX,       // Состояние проверки правильности числа
    LASTSKIP,  // в последний раз пропускаем знак
    SIGN,  // во-первых проверяем, что это верная hex цифра, во-вторых проверяем,
           // что у него в старшем бите стоит 1 (само число >= 128)
           // Новые состояние писать тут
    STATECOUNT,  // Количество состояний
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    size_t length_count;
    size_t numbers_count;
    char current_char;
    char last_char;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;

// В машине числа фиксированной длины. Считать будем количество "байтов"
const int64_t HEX_LENGTH = 4;