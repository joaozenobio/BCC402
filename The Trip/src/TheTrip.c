#include <stdio.h>
#include <stdlib.h>

#include "TheTrip.h"

int theTrip() {
	
	/*
	 * Coleta dos gastos de cada estudante no total.
    */
	int n = -1;
	int i;
    int counter = 1;
    double* movimentacao =(double*) malloc(counter*sizeof(double));
    while(n != 0) {
        scanf("%d", &n);
        double *student = (double *) malloc(n * sizeof(double));
        double total = 0;
        for (i = 0; i < n; i++) {
            scanf("%lf", &student[i]);
            total += student[i];
        }
        /*
         * Quantidade que cada um deveria pagar se a repartição fosse feita (média).
         */
        total /= n;

        /*
         * Cálculo do somatório da diferença em relação à repartição ideal e o quanto cada um realmente pagou de acordo com
         * àqueles que pagaram a mais e a menos.
         * Se a diferença entre o que o estudante pagou e o ideal é positiva, o estudante pagou a mais, caso contrário,
         * pagou a menos, guardando essas diferenças.
         */
        double positivo = 0;
        for (i = 0; i < n; i++) {
            student[i] -= total;
            if (student[i] > 0) {
                positivo += student[i]; // Inverte o sinal para avaliar o módulo do que falta receber.
            }
        }

        /*
         * Cálculo da movimentacao mínima necessária de dinheiro que é calculada de forma a movimentar o dinheiro
         * excedente total dos alunos que pagaram menos para o faltante total dos que pagaram mais.
        */
        movimentacao[counter-1] = positivo;
        counter++;
        movimentacao =(double*) realloc(movimentacao, counter*sizeof(double));
    }
    for(int j = 0; j < counter-2; ++j) {
        printf("%lf\n", movimentacao[j]);
    }
	
	return 0;
}
