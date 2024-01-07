#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { START, READ_CHAR, PRINT_TERNARY, END, STATECOUNT } StateName;

typedef struct State State;

const int64_t BITS_COUNT = 32;

typedef struct {
    State *pipeline;
    StateName cur_state;
    char current_ternary_state[BITS_COUNT + 1];
    int last_char;
    int current_length;
    char current_char;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine *);
} State;