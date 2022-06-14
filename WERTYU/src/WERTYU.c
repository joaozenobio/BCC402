#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "WERTYU.h"

int wertyu() {
	char** teclado =(char**) malloc(4*sizeof(char*));
	int i, j;
	for(i = 0; i < 4; i++) {
		teclado[i] =(char*) malloc(10*sizeof(char));
	}
    /*
     * Gera a referência para o teclado correto.
     */
	teclado[0] = "1234567890";
	teclado[1] = "QWERTYUIOP";
	teclado[2] = "ASDFGHJKL;";
	teclado[3] = "ZXCVBNM,./";
	int tam = 1;
	char* frase =(char*) malloc(tam*sizeof(char));
	char c = ' ';
	int encontrou;
	while(c != '\0') {
		encontrou = 0;
		c = getchar();
        /*
         * Encerra o programa quando le o caracter 'q'.
         */
		if(c == 'q') break;
		/*
		 * Verifica se o caracter lido é alfanumerico ou uma pontuação, ou seja, valido para correção.
		 */
        if(isalnum(c) || ispunct(c)) {
            /*
             * Procura pelo caracter lido no teclado de referência.
             */
			for(i = 0; i < 4 && (!encontrou); i++) {
				for(j = 0; j < 10 && (!encontrou); j++) {
					if(c == teclado[i][j]) {
						encontrou = 1;
					}
				}
			}
            /*
             * Aloca apenas a quantidade necessária de caracteres para a frase no vetor.
             */
			frase = (char *) realloc(frase, tam);
            /*
             * Corrige cada caracter fazendo como um shift à esquerda no teclado.
             */
			frase[tam-1] = teclado[i-1][j-2];
			tam++;
		}
        /*
         * Espaços não precisam ser corrigidos.
         */
		else if(isspace(c)) {
			frase = (char *) realloc(frase, tam);
                        frase[tam-1] = ' ';
			tam++;
		}
	}
    /*
     * Adiciona um fim à string da frase.
     */
	frase[tam-2] = '\0';
	printf("%s", frase);
	return 0;
}
