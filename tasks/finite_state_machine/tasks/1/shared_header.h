#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
    START,
    COUNT,
    STATECOUNT,
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    size_t slash_count;
    size_t word_count;
    char current_char;
    bool check_word;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;
