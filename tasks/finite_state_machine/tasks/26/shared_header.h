#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    SKIP = 0,
    MEMORIZENUMBER,
    RESULT,
    STATECOUNT,  // DO NOT USE LIKE NAME. Нужно для определения кол-ва состояний
    END          // Означает состояние, когда можно завершать программу
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;  // Массив состояний
    StateName cur_state;
    int32_t prev_number;
    int32_t cur_number;
    char cur_char;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;