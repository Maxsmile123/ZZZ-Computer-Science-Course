#pragma once

#include <ctype.h>

#include "shared_header.h"

StateName Start(StateMachine* sm) {
    sm->char_counter = 0;
    sm->c = ' ';
    return READ;
}

StateName Read(StateMachine* sm) {
    sm->c = (char)fgetc(sm->in_file);
    if (sm->c == EOF) {
        return END;
    } else if (isalpha(sm->c)) {
        ++sm->char_counter;
        return ENCODE;
    } else {
        sm->char_counter = 0;
        return WRITE;
    }
}

StateName Encode(StateMachine* sm) {
    if (islower(sm->c)) {
        sm->c = (char)((sm->c - 'a' + sm->shift + sm->char_counter) % 26 + 'a');
    } else {
        sm->c = (char)((sm->c - 'A' + sm->shift + sm->char_counter) % 26 + 'A');
    }
    return WRITE;
}

StateName Write(StateMachine* sm) {
    fprintf(sm->out_file, "%c", sm->c);
    return READ;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * (int)STATECOUNT);
    /*int i = -1;
    st[i] = State{(StateName)i++, &Start};
    st[i] = State{(StateName)i++, &Read};
    st[i] = State{(StateName)i++, &Encode};
    st[i] = State{(StateName)i++, &Write};*/
    StateName (*actions[STATECOUNT])(StateMachine*) = {&Start, &Read, &Encode, &Write};
    for (int i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* st) {
    free(st);
}