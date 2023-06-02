#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Conta *p = NULL;
    p = criarPilha(p);
    printf("\n_________________\n");
    printf("Topo\n");
    Mostrartopo(p);
    printf("_________________\n");
    p = Inserir(p);
    p = Inserir(p);
    p = Inserir(p);
    p = Inserir(p);
    printf("\n_________________\n");
    printf("Topo\n");
    Mostrartopo(p);
    printf("_________________\n");
    printf("Mostrar\n");
    MostrartodaPilha(p);
    printf("_________________\n");
    p = Remover(p);
    printf("_________________\n");
    printf("Mostrar\n");
    MostrartodaPilha(p);
    printf("_________________\n");

    Liberar(p);
    printf("\n_________________\n");
    printf("Topo\n");
    Mostrartopo(p);
    printf("_________________\n");
}