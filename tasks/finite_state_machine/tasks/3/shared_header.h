#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum { CHECK_SYMBOL_FIRST, WORDS_IN_COMMENT, CHECK_WORD, STATECOUNT, END } StateName;

typedef struct State State;

typedef struct {
    State* pipeline;  // Массив состояний
    StateName cur_state;
    char current_symbol;
    int count_words;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;