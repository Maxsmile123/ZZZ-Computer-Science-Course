#pragma once

#include <stdio.h>

typedef enum {
    START = 0,
    SYMBOLCHECK,
    // Add new states here
    STATECOUNT,
    END
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    char last_symbol;
    FILE* file_out;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*, char c);
} State;