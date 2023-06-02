#include<stdio.h>
#include<stdlib.h>
#include"circular.h"

typedef struct
{
    int num;
    char titular[100];
    float saldo;
    Conta *prox;
}Conta;

Conta *inserirCircular(Conta *lista)
{
    Conta *novo = (Conta*)malloc(sizeof(Conta));
    Conta *aux;
    printf("Numero: ");
    scanf("%d", &novo->num);
    pritnf("Nome: ");
    scanf(" %[^\n]s",novo->titular);
    printf("Saldo: ");
    scanf("%f", &novo->saldo);

    if(novo == NULL)
    {
        novo->prox = novo;
    }
    else
    {
        aux = lista;
        while(aux->prox != lista)
        {
            aux = aux->prox;
        }
        aux->prox= novo;
        novo->prox=lista;
    }
    return novo;
}
