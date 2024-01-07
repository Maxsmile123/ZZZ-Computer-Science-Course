#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { SEARCH = 0, ADD_NUM, SAVE_NUM, RESULT, STATECOUNT, END } StateName;

typedef struct State State;

typedef struct {
    StateName activeState;
    State* pipeline;

    char cur_char;
    int32_t cur_num;
    int32_t first_num;
    int32_t last_num;

} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;