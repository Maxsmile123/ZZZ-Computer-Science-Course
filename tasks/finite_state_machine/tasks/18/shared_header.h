#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    START = 0,
    SUITABLECHARSEARCH,
    CELSIUSVALUEFORMING,
    CONVERSIONTOFAHRENHEIT,
    // Add new states here
    STATECOUNT,
    END
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    char ch;
    bool num_is_neg;
    int num;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;