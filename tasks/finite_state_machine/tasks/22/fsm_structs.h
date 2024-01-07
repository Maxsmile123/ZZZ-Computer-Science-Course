#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определим состояния нашей машины

typedef enum { SCAN, CHECK, LAST_CHECK, OUTPUT, END } State;

// Зададим структуру нашей машины, которая будет содержать только текущее ее состояние

typedef struct {
    State current_state;
} Machine;
