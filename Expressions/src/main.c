/*
 * Credits to https://github.com/secnot/uva-onlinejudge-solutions/blob/master/10157%20-%20Expressions/main.py
 */

#include <stdio.h>
#include <string.h>

#include "Expressions.h"

int main() {
    int N, D;
    char buffer[100];
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer)-1] = '\0';
    sscanf(buffer, "%d %d", &N, &D);
    while(strlen(buffer) != 0) {
        int result = expressions(N, D);
        printf("%d\n", result);
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer)-1] = '\0';
        sscanf(buffer, "%d %d", &N, &D);
    }
    return 0;
}
