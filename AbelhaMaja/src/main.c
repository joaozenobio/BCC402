#include <stdio.h>
#include <string.h>

#include "AbelhaMaja.h"

int main() {
    int N;
    char buffer[100];
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer)-1] = '\0';
    sscanf(buffer, "%d", &N);
    while(strlen(buffer) != 0) {
        P p = abelhaMaja(N);
        printf("%d %d\n", p.x, p.y);
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer)-1] = '\0';
        sscanf(buffer, "%d", &N);
    }
    return 0;
}
