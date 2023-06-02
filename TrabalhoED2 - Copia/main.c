#include <stdio.h>
#include <stdlib.h>


double calculaArea(char operacao, double M[][3]) {
    int i, j;
    double soma = 0, cont = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j > i) {
                soma += M[i][j];
                cont++;
            }
        }
    }

    if (operacao == 'S') {
        return soma;
    } else if (operacao == 'M') {
        return soma / cont;
    } else {
        return 0;
    }
}

int main() {
    char operacao;
    double M[3][3], resultado;

    scanf("%c", &operacao);

    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    resultado = calculaArea(operacao, M);

    printf("%.1lf\n", resultado);

    return 0;
}

