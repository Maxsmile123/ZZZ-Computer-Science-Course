#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { SEARCH = 0, SKIP, CHECK, RESULT, STATECOUNT, END } StateName;

typedef struct State State;

typedef struct {
    StateName activeState;
    State* pipeline;

    char cur_char;
    int32_t cnt;

} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;