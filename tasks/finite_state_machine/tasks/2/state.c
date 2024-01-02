#pragma once

#include "shared_header.c"

StateName FindFirstSymComStart(StateMachine* sm, char ch) {
    sm->last_sym = ' ';
    printf(" Programm started and finding  symbol - / - this is start comment\n");
    if (ch == '/') {
        printf(" I am finding / symbol in start of comment\n");
        return FINDSECONDSYMSTARTCOMM;
    }
    return FINDFIRSTSYMSTARTCOMM;
}

StateName FindSecondSymComStart(StateMachine* sm, char ch) {
    sm->last_sym = ' ';
    if (ch == '*') {
        printf(" I am finding * symbol in start of comment\n");
        return COMMENTDETECTED;
    } else {
        printf(" I dont find second symbol - * - because i go to first state\n");
        return FINDFIRSTSYMSTARTCOMM;
    }
}

StateName CommentDetected(StateMachine* sm, char ch) {
    if (ch == '/' && sm->last_sym == '*') {
        printf("Last symbol was - * and now symbol - / - comment finished \n");
        ++sm->count_words;
        return END;
    }
    if (ch == '\n' && sm->last_sym != ' ') {
        ++sm->count_words;
    }
    if (ch == ' ' && sm->last_sym != ' ' && sm->last_sym != '\n') {
        ++sm->count_words;
    } else if (ch == '*') {
        printf("Find * and go to check future symbol\n");
        return FINDFIRSTSYMFINISHCOM;
    }
    sm->last_sym = ch;
    return COMMENTDETECTED;
}

StateName FindSecondSymComFin(StateMachine* sm, char ch) {
    if (ch == '/') {
        printf("Last symbol was - * and now symbol - / - comment finished \n");
        if (sm->last_sym == '\n') {
            return END;
        }
        if (sm->last_sym != ' ') {
            ++sm->count_words;
        }
        return END;
    } else {
        printf("Last symbol was - * - but now symbol is not - / - comment continue \n");
        if (ch == ' ') {
            ++sm->count_words;
        }
        sm->last_sym = ch;
        return COMMENTDETECTED;
    }
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    int i = 0;
    st[i].name = (StateName)i;
    st[i].action = &FindFirstSymComStart;
    ++i;
    st[i].name = (StateName)i;
    st[i].action = &FindSecondSymComStart;
    ++i;
    st[i].name = (StateName)i;
    st[i].action = &CommentDetected;
    ++i;
    st[i].name = (StateName)i;
    st[i].action = &FindSecondSymComFin;
    return st;
}

void DeleteStates(State* st) {
    free(st);
}
