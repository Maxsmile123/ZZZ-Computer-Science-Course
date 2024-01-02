#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    START = 0,
    // Пользовательские состояния
    READ,
    ENCODE,
    WRITE,
    //
    STATECOUNT,
    END
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    // Штуки нужные для решения задачи
    FILE* in_file;
    FILE* out_file;
    char c;
    int32_t char_counter;
    int32_t shift;

} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;