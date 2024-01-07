#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "shared_header.h"

StateName Skip(StateMachine* sm) {
    if (sm->cur_char == EOF) {
        return RESULT;
    }
    if (sm->cur_char >= 'a' && sm->cur_char <= 'z') {
        return SKIP;
    }
    if (sm->cur_char >= 'A' && sm->cur_char <= 'Z') {
        return SKIP;
    }
    return SEARCH;
}

StateName Search(StateMachine* sm) {
    if (sm->cur_char == EOF) {
        return RESULT;
    }
    if (sm->cur_char >= 'a' && sm->cur_char <= 'z') {
        return CHECK;
    }
    if (sm->cur_char >= 'A' && sm->cur_char <= 'Z') {
        return SKIP;
    }
    return SEARCH;
}

StateName Check(StateMachine* sm) {
    if (sm->cur_char == EOF) {
        sm->cnt++;
        return RESULT;
    }
    if (sm->cur_char >= 'a' && sm->cur_char <= 'z') {
        return CHECK;
    }
    if (sm->cur_char >= 'A' && sm->cur_char <= 'Z') {
        return SKIP;
    }
    sm->cnt++;
    return SEARCH;
}

StateName Result(StateMachine* sm) {
    printf("%d\n", sm->cnt);
    return END;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    StateName (*actions[STATECOUNT])(StateMachine*) = {&Search, &Skip, &Check, &Result};
    for (int i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* st) {
    free(st);
}