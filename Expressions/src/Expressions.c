#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Expressions.h"

/*
 * Executes a dynamic programing solution to calculate the Calculates Catalan Number with depth 0 to n.
 * The Catalan Number corresponds to the number of possible expressions with matching parenthesis given a number
 * of pairs.
 */
int expressionsRec(int pairs, int depth, int** mem) {
    if(mem[pairs][depth] != -1) return mem[pairs][depth];
    if(pairs == 0 || depth == 1) {
        mem[pairs][depth] = 1;
        return 1;
    }

    int total = 0;
    for(int i = 0; i < pairs; i++) {
        total += expressionsRec(i, depth - 1, mem) * expressionsRec(pairs - 1 - i, depth, mem);
    }
    mem[pairs][depth] = total;
    return total;
}

int expressions(int pairs, int depth) {
    /*
     * Creates matrix for memoization.
     */
    if(pairs % 2 != 0) return 0;
    int** mem =(int**) malloc(pairs*sizeof(int*));
    for (int i = 0; i < pairs; ++i) {
        mem[i] =(int*) malloc(pairs*sizeof(int));
        for (int j = 0; j < pairs; ++j) {
            mem[i][j] = -1;
        }
    }
    /*
     * Calculates the difference of the Catalan Number for n to 0 depth and n-1 to 0 depth. The result is
     * the number of possible expressions with parenthesis matching given a depth n.
     */
    int result = expressionsRec(pairs/2, depth, mem) - expressionsRec(pairs/2, depth-1, mem);
    return result;
}