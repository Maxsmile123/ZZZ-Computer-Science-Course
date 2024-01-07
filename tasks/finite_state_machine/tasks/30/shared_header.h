#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int INT_MAXS = 99;

typedef enum {
    FIND_NUMBER,
    VALUE_FORMING,
    COMPARE_VALUES,
    END,
    COUNT,
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName current_state;
    char current_char;
    int current_number;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;
