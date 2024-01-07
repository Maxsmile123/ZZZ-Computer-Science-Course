#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "shared_header.h"

StateName Start(StateMachine* sm) {
    if ((sm->current_char == '/') && (sm->slash_count == 1)) {
        return COUNT;
    }
    if ((sm->current_char == '/') && (sm->slash_count == 0)) {
        ++sm->slash_count;
        return START;
    }
    if (sm->current_char != '/') {
        sm->slash_count = 0;
        return START;
    }

    return START;
}

StateName Count(StateMachine* sm) {
    if ((!sm->check_word) && (sm->current_char == ' ')) {
        return COUNT;
    }
    if ((sm->current_char != ' ') && (sm->current_char != '\n')) {
        sm->check_word = true;
        return COUNT;
    }
    if ((sm->current_char == ' ') && (sm->check_word)) {
        ++sm->word_count;
        return COUNT;
    }
    if (sm->current_char == '\n') {
        sm->check_word = false;
        sm->slash_count = 0;
        return START;
    }

    return COUNT;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);

    StateName (*actions[STATECOUNT])(StateMachine*) = {&Start, &Count};
    for (size_t i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* pipeline) {
    free(pipeline);
}
