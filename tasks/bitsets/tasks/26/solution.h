#pragma once

#include<stdio.h> 
#include<stdint.h> 


typedef uint32_t BitSet;


int checking_letters(BitSet *letters) {

    *letters = *letters & (31324125u);

    if (*letters == 0) {
        return 0;
    }

    *letters = *letters & (57409403u);

    if (*letters == 0) {
        return 1;
    }

    return 0;

}


void mark_letter(BitSet *letters, char character) {

    if ('a' <= character && character <= 'z') {
        *letters = *letters | (1 << (character - 'a'));
    } else if (('A' <= character && character <= 'Z')) {
        *letters = *letters | (1 << (character - 'A'));
    }
    
}


int Task() {

    BitSet letters = 0;
    char character;

    while(1) {

        character = getchar();

        if (('a' <= character && character <= 'z') || ('A' <= character && character <= 'Z')) {

            mark_letter(&letters, character);

        } else {
            if (checking_letters(&letters)) {
                printf("Есть слово, все согласные которого свистящие.\n");
                return 0;
            } 
            letters = 0;
        }

        if (character == EOF) {
            break;
        }

    }
    
    printf("Нет слова, все согласные которого свистящие.\n");

    return 0; 
}


// c f h s x - свистящие согласные 
