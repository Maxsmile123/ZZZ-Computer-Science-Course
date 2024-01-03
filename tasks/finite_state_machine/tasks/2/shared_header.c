#pragma once

#include <stdbool.h>

#include "stdlib.h"

typedef enum {
    FINDFIRSTSYMSTARTCOMM = 0,
    FINDSECONDSYMSTARTCOMM,
    COMMENTDETECTED,
    FINDFIRSTSYMFINISHCOM,
    STATECOUNT,
    END
} StateName;

typedef struct State State;

typedef struct {
    StateName cur_state;
    State* pipeline;
    int count_words;
    char last_sym;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*, char ch);
} State;