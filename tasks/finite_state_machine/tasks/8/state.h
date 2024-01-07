#pragma once

#include <ctype.h>

#include "shared_header.h"

StateName Start(StateMachine* sm) {
    sm->counter = 1;
    sm->c = ' ';
    return READ;
}

StateName Read(StateMachine* sm) {
    sm->c = (char)fgetc(sm->in_file);
    if (sm->c == EOF) {
        return END;
    } else if (isalpha(sm->c)) {
        return DECODE;
    } else {
        ++sm->counter;
        return WRITE;
    }
}

StateName Decode(StateMachine* sm) {
    if (islower(sm->c)) {
        sm->c = (char)((sm->c - 'a' - sm->counter) % 26 + 'a');
    } else {
        sm->c = (char)((sm->c - 'A' - sm->counter) % 26 + 'A');
    }
    return WRITE;
}

StateName Write(StateMachine* sm) {
    fprintf(sm->out_file, "%c", sm->c);
    return READ;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * (int)STATECOUNT);
    StateName (*actions[STATECOUNT])(StateMachine*) = {&Start, &Read, &Decode, &Write};
    for (int i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* st) {
    free(st);
}