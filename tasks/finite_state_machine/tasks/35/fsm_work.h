#pragma once

#include <stdio.h>

#include "shared_header.h"

void FsmWork(struct Machine* machine, FILE* file) {

    const char* french_num[61] = {
        "dix-sept",         "dix-huit",        "dix-neuf",          "vingt",           "vingt et un",
        "vingt-deux",       "vingt-trois",     "vingt-quatre",      "vingt-cinq",      "vingt-six",
        "vingt-sept",       "vingt-huit",      "vingt-neuf",        "trente",          "trente et un",
        "trente-deux",      "trente-trois",    "trente-quatre",     "trente-cinq",     "trente-six",
        "trente-sept",      "trente-huit",     "trente-neuf",       "quarante",        "quarante et un",
        "quarante-deux",    "quarante-trois",  "quarante-quatre",   "quarante-cinq",   "quarante-six",
        "quarante-sept",    "quarante-huit",   "quarante-neuf",     "cinquante",       "cinquante et un",
        "cinquante-deux",   "cinquante-trois", "cinquante-quatre",  "cinquante-cinq",  "cinquante-six",
        "cinquante-sept",   "cinquante-huit",  "cinquante-neuf",    "soixante",        "soixante et un",
        "soixante-deux",    "soixante-trois",  "soixante-quatre",   "soixante-cinq",   "soixante-six",
        "soixante-sept",    "soixante-huit",   "soixante-neuf",     "soixante-dix",    "soixante et onze",
        "soixante-douze",   "soixante-treize", "soixante-quatorze", "soixante-quinze", "soixante-seize",
        "soixante-dix-sept"};

    char symbol = '0';

    while (symbol != EOF) {
        symbol = (char)fgetc(file);

        switch (machine->current_state) {

            case CHECK_FIRST_CHAR:

                if (symbol >= '1' && symbol <= '6') {
                    machine->data = (symbol - '0') * 10;
                    machine->current_state = CHECK_NUMBER17_69;
                } else if (symbol == '7') {
                    machine->data = 70;
                    machine->current_state = CHECK_NUMBER70_77;
                }

                break;

            case CHECK_NUMBER17_69:

                if (symbol >= '1' && symbol <= '9') {
                    machine->data += symbol - '0';
                    printf("%s\n", french_num[machine->data - 17]);
                    machine->current_state = CHECK_FIRST_CHAR;
                    machine->data = 0;
                } else {
                    machine->current_state = CHECK_FIRST_CHAR;
                    machine->data = 0;
                }

                break;

            case CHECK_NUMBER70_77:

                if (symbol >= '1' && symbol <= '7') {
                    machine->data += symbol - '0';
                    printf("%s\n", french_num[machine->data - 17]);
                    machine->current_state = CHECK_FIRST_CHAR;
                    machine->data = 0;
                } else {
                    machine->current_state = CHECK_FIRST_CHAR;
                    machine->data = 0;
                }

                break;
        }
    }
}

void Start(struct Machine* machine, FILE* file) {

    machine->current_state = CHECK_FIRST_CHAR;
    machine->data = 0;

    FsmWork(machine, file);
}