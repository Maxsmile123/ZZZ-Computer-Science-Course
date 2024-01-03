#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "shared_header.h"

double CelsiusToFahrenheit(int celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

StateName Start(StateMachine* sm) {
    printf("Finite State Machine has started its execution:\n\n");
    if (sm->ch == '-') {
        sm->num_is_neg = true;
        return CELSIUSVALUEFORMING;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return CELSIUSVALUEFORMING;
    } else {
        return SUITABLECHARSEARCH;
    }
}

StateName SuitableCharSearch(StateMachine* sm) {
    if (sm->ch == '-') {
        sm->num_is_neg = true;
        return CELSIUSVALUEFORMING;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return CELSIUSVALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        return SUITABLECHARSEARCH;
    }
}

StateName CelsiusValueForming(StateMachine* sm) {
    if (sm->ch == '*') {
        return CONVERSIONTOFAHRENHEIT;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->num * 10 + (sm->ch - '0');
        return CELSIUSVALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        sm->num_is_neg = false;
        sm->num = 0;
        return SUITABLECHARSEARCH;
    }
}

StateName ConversionToFahrenheit(StateMachine* sm) {
    if (sm->ch == 'C') {
        if (sm->num_is_neg) {
            sm->num *= -1;
        }
        printf("%dC = %gF\n", sm->num, CelsiusToFahrenheit(sm->num));
        return SUITABLECHARSEARCH;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return CELSIUSVALUEFORMING;
    } else if (sm->ch == '-') {
        sm->num_is_neg = true;
        return CELSIUSVALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        sm->num_is_neg = false;
        sm->num = 0;
        return SUITABLECHARSEARCH;
    }
}

// Add StateNames here

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    int i = -1;
    st[i] = State{(StateName)i++, &Start};
    st[i] = State{(StateName)i++, &SuitableCharSearch};
    st[i] = State{(StateName)i++, &CelsiusValueForming};
    st[i] = State{(StateName)i++, &ConversionToFahrenheit};
    // Add initializations for states here
    return st;
}

void DeleteStates(State* st) {
    free(st);
}