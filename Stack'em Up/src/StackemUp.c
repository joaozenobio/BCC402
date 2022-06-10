#include <stdio.h>
#include <stdlib.h>

#include "StackemUp.h"

int stackemUp() {
    int cases, n, i, j, k, carta;
    /*
     * Estrutura para guardar o baralho que será reordenado.
     */
    int* b =(int*) malloc(52*sizeof(int));
    fscanf(stdin,"%d", &cases);
    fgetc(stdin);
    /*
     * Estrutura para guardar as trocas conhecidas de cada caso.
     */
    int*** trocasConhecidas =(int***) malloc(cases*sizeof(int**));
    for(i = 0; i < cases; i++) {
        trocasConhecidas[i] =(int**) malloc(100*sizeof(int*));
    }
    for(i = 0; i < cases; i++) {
        for (j = 0; j < 100; j++) {
            trocasConhecidas[i][j] = (int *) malloc(52 * sizeof(int));
        }
    }
    /*
     * Estrutura para guardar a ordem dos tipos de troca para cada caso.
     */
    int** trocas =(int**) malloc(cases*sizeof(int*));
    for(i = 0; i < cases; i++) {
        trocas[i] =(int*) malloc(100*sizeof(int));
    }
    /*
     * Guardar as possíveis trocas da ordem das cartas no baralho e, dado um baralho ordenado, as trocas realizadas pelo
     * dealer, numeradas conforme a ordem das trocas conhecidas. Isto para cada caso.
     */
    for(i = 0; i < cases; i++) {
        fgetc(stdin);
        fscanf(stdin,"%d", &n);
        for(j = 0; j < n; j++) {
            int* aux =(int*) malloc(52*sizeof(int));
            for(k = 0; k < 52; k++) {
                fscanf(stdin,"%d", &carta);
                aux[k] = carta-1;
            }
            trocasConhecidas[i][j] = aux;
        }
        for(j = 0; j < n; j++) {
            fscanf(stdin,"%d", &trocas[i][j]);
        }
    }
    /*
     * Paracada caso, realiza as trocas no baralho ordenado conforme as trocas conhecidas.
     */
    for(i = 0; i < cases; i++) {
        /*
         * Cria um baralho ordenado.
         */
        for(j = 0; j < 52; j++) {
            b[j] = j;
        }
        /*
         * Realiza cada troca no baralho.
         */
        for(j = 0; j < n; j++) {
            int *bAux =(int*) malloc(52*sizeof(int));
            for (k = 0; k < 52; k++) {
                /*
                 * Encontra a posição final de cada carta na posição verificada atualmente e realiza a troca em um
                 * baralho auxiliar para evitar a perda da posição das cartas que ainda serão analisadas.
                 */
                int posicao = trocasConhecidas[i][trocas[i][j]-1][k];
                bAux[k] = b[posicao];
            }
            int* freeB = b;
            b = bAux;
            free(freeB);
        }
        /*
         * Imprime o baralho na ordem final.
         */
        for(j = 0; j < 52; j++) {
            char *cValor = (char *) malloc(5 * sizeof(char));
            char *cNipe = (char *) malloc(8 * sizeof(char));
            valor = (b[j] % 13) + 1;
            switch (valor) {
                case Ace:
                    cValor = "Ace";
                    break;

                case c2:
                    cValor = "2";
                    break;

                case c3:
                    cValor = "3";
                    break;

                case c4:
                    cValor = "4";
                    break;

                case c5:
                    cValor = "5";
                    break;

                case c6:
                    cValor = "6";
                    break;

                case c7:
                    cValor = "7";
                    break;

                case c8:
                    cValor = "8";
                    break;

                case c9:
                    cValor = "9";
                    break;

                case c10:
                    cValor = "10";
                    break;

                case Jack:
                    cValor = "Jack";
                    break;

                case Queen:
                    cValor = "Queen";
                    break;

                case King:
                    cValor = "King";
                    break;

                default:
                    cNipe = "Error";
            }
            nipe = ((b[j] / 13) % 4) + 1;
            switch (nipe) {
                case Clubs:
                    cNipe = "Clubs";
                    break;

                case Diamonds:
                    cNipe = "Diamonds";
                    break;

                case Hearts:
                    cNipe = "Hearts";
                    break;

                case Spades:
                    cNipe = "Spades";
                    break;

                default:
                    cNipe = "Error";
            }
            printf("%s of %s\n", cValor, cNipe);
        }
    }

    return 0;
}
