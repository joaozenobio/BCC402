#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AbelhaMaja.h"

P abelhaMaja(int n) {
    n--;
    P p = {0, 0};
    int counter = 1;
    int counterTemp;
    while(n != 0) {
        (p.y)++;
        n--;
        counterTemp = counter - 1;
        while(counterTemp > 0 && n != 0) {
            (p.x)--;
            (p.y)++;
            counterTemp--;
            n--;
        }
        counterTemp = counter;
        while(counterTemp > 0 && n != 0) {
            (p.x)--;
            counterTemp--;
            n--;
        }
        counterTemp = counter;
        while(counterTemp > 0 && n != 0) {
            (p.y)--;
            counterTemp--;
            n--;
        }
        counterTemp = counter;
        while(counterTemp > 0 && n != 0) {
            (p.x)++;
            (p.y)--;
            counterTemp--;
            n--;
        }
        counterTemp = counter;
        while(counterTemp > 0 && n != 0) {
            (p.x)++;
            counterTemp--;
            n--;
        }
        counterTemp = counter;
        while(counterTemp > 0 && n != 0) {
            (p.y)++;
            counterTemp--;
            n--;
        }
        counter++;
    }
    return p;
}