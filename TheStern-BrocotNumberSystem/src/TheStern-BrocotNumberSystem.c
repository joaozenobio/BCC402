#include <stdio.h>
#include <string.h>

#include "TheStern-BrocotNumberSystem.h"

/*
 * Finds the path through the tree
 */
void findFraction(Fraction x) {
    Fraction fraction1 = {0, 1};
    Fraction fraction2 = {1, 0};
    Fraction fractionResult = {1, 1};
    /*
     * while the target fraction is still missing, continue looking...
     */
    while((x.a != fractionResult.a) && (x.b != fractionResult.b)) {
        fractionResult.a = fraction1.a + fraction2.a;
        fractionResult.b = fraction1.b + fraction2.b;
        /*
         * Finds common multiple between fractions and compare, if x is bigger, than it is placed on the
         * right subtree of the result, otherwise, on the left.
         */
        if((fractionResult.a * x.b) > (x.a * fractionResult.b)) {
            fraction2.a = fractionResult.a;
            fraction2.b = fractionResult.b;
            printf("L");
        }
        else if((fractionResult.a * x.b) < (x.a * fractionResult.b)) {
            fraction1.a = fractionResult.a;
            fraction1.b = fractionResult.b;
            printf("R");
        }
    }
    printf("\n");
}

int TheSternBrocotNumberSystem() {
    int a, b;
    char buffer[100];
    /*
     * Use of fgets to avoid end of line problems in scanning.
     */
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer)-1] = '\0';
    Fraction x;
    sscanf(buffer, "%d %d", &(x.a), &(x.b));
    /*
     * Continue finding paths throughout the tree until the fraction is 1/1
     */
    while(!(x.a == 1 && x.b == 1)) {
        findFraction(x);
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer)-1] = '\0';
        sscanf(buffer, "%d %d", &(x.a), &(x.b));
    }
    return 0;
}
