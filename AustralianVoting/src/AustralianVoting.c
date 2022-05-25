#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AustralianVoting.h"

int australianVoting() {
    int N;
    char buffer[100];
    /*
     * Use of fgets to avoid end of line problems in scanning.
     */
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer)-1] = '\0';
    sscanf(buffer, "%d", &N);
    for (int i = 0; i < N; i++) {
        getchar();
        int nCadidates;
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer)-1] = '\0';
        sscanf(buffer, "%d", &nCadidates);
        char** candidates =(char**) malloc(nCadidates * sizeof(char*));
        for (int j = 0; j < nCadidates; ++j) {
            candidates[j] =(char*) malloc(81 * sizeof(char));
        }
        /*
         * Get each candidate name.
         */
        for (int j = 0; j < nCadidates; j++) {
            fgets(candidates[j], 81, stdin);
            candidates[j][strlen(candidates[j])-1] = '\0';
        }
        int** ballots =(int**) malloc(1000 * sizeof(int*));
        for(int j = 0; j < 1000; j++) {
            ballots[j] =(int*) malloc(nCadidates * sizeof(int));
        }
        int counter = 0;
        /*
         * Get each ballot value.
         */
        for(int j = 0; j < 1000; j++) {
            fgets(buffer, 100, stdin);
            buffer[strlen(buffer)-1] = '\0';
            /**
            * Check if blank line was found, that means all ballots were collected.
            */
            if(strlen(buffer) == 0) break;
            char *data = buffer;
            int offset;
            for(int k = 0; k < nCadidates; k++) {
                sscanf(data, " %d%n", &ballots[j][k], &offset);
                data += offset;
            }
            counter++;
        }
        /*
         * Put each ballot vote consistent to array counting.
         */
        for (int k = 0; k < counter; ++k) {
            for (int l = 0; l < nCadidates; ++l) {
                ballots[k][l]--;
            }
        }
        int* candidatesVotes =(int*) calloc(nCadidates, sizeof(int));
        int winner = 0;
        /*
         * Evaluate candidates votes.
         */
        for (int j = 0; j < nCadidates && !winner; ++j) {
            /*
             * Count each candidate vote depending on wether the candidate was excluded by rank,
             * ignoring its counting, or the vote of will be recounted since the candidate of the
             * voter was excluded by rank.
             */
            for (int k = 0; k < counter; ++k) {
                if(ballots[k][j] != -1 && candidatesVotes[ballots[k][j]] != -1) {
                    candidatesVotes[ballots[k][j]]++;
                }
            }
            /*
            * Check if there is a winner;
            */
            for (int k = 0; k < nCadidates; ++k) {
                if(candidatesVotes[k] > 0.5 * counter) {
                    printf("%s\n", candidates[k]);
                    winner = 1;
                }
            }
            if(!winner) {
                int min = 1001; // max of 1000 ballots
                /*
                 * Temporarily exclude candidates that have the least amount of votes in order to check for ties.
                 */
                for (int k = 0; k < nCadidates; ++k) {
                    if(candidatesVotes[k] < min && candidatesVotes[k] > -1) {
                        min = candidatesVotes[k];
                    }
                }
                /*
                 * Permanently exclude candidates that were excluded at the last iteration that won't be considered in
                 * tie checking.
                 */
                for (int k = 0; k < nCadidates; ++k) {
                    if(candidatesVotes[k] == min) {
                        candidatesVotes[k] = -1;
                    }
                    else if(candidatesVotes[k] == -1) {
                        candidatesVotes[k] = -2;
                    }
                }
                /*
                 * Check if there was a tie in the courrent rank evaluation and, if there was indeed, restart the couting of the votes with
                 * the next rank, otherwise, consider only the votes from voters whose candidates where excluded by rank.
                 */
                int checkTie = 1;
                for (int k = 0; k < nCadidates; ++k) {
                    if(candidatesVotes[k] != -1 && candidatesVotes[k] != -2) {
                        checkTie = 0;
                    }
                }
                if(checkTie) {
                    for (int k = 0; k < nCadidates; ++k) {
                        if(candidatesVotes[k] != -2) {
                            candidatesVotes[k] = 0;
                        }
                    }
                }
                else{
                    for (int k = 0; k < nCadidates; ++k) {
                        if (candidatesVotes[k] != min && candidatesVotes[k] != -1) {
                            for (int l = 0; l < counter; ++l) {
                                if (ballots[l][j] == k) {
                                    ballots[l][j + 1] = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
        /*
         * Show the candidates that ended up tied, if there were any.
         */
        if(!winner) {
            printf("Tie:\n");
            for (int j = 0; j < nCadidates; ++j) {
                if(candidatesVotes[j] == 0)
                    printf("%s\n", candidates[j]);
            }
        }
    }
    return 0;
}
