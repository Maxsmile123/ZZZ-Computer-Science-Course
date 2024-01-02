#pragma once

#include <stdio.h>

#include "shared_header.h"

StateName CheckSymbolFirst(StateMachine* sm) {
    if (sm->current_symbol == '{') {
        return WORDS_IN_COMMENT;
    }
    return CHECK_SYMBOL_FIRST;
}

StateName WordsInComment(StateMachine* sm) {
    if (('a' <= sm->current_symbol && sm->current_symbol <= 'z') ||
        ('A' <= sm->current_symbol && sm->current_symbol <= 'Z')) {
        return CHECK_WORD;
    } else if (sm->current_symbol == '}') {
        return END;
    }
    return WORDS_IN_COMMENT;
}

StateName CheckWord(StateMachine* sm) {
    if (sm->current_symbol != ' ') {
        return CHECK_WORD;
    }
    ++sm->count_words;
    return WORDS_IN_COMMENT;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * (int)STATECOUNT);
    int i = -1;
    st[i] = State{(StateName)i++, &CheckSymbolFirst};
    st[i] = State{(StateName)i++, &WordsInComment};
    st[i] = State{(StateName)i++, &CheckWord};
    return st;
}

void DeleteStates(State* st) {
    free(st);
}