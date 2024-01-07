#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { START = 0, READ, DECODE, WRITE, STATECOUNT, END } StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    FILE* in_file;
    FILE* out_file;
    char c;
    int32_t counter;

} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;