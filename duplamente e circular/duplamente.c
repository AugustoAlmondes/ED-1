#include<stdlib.h>
#include<stdio.h>
typedef struct
{
    float saldo;
    int num;
    char nome[100];
    Conta *prox;
    Conta *ante;
}Conta;

Conta *inserirDuplamente(Conta *lista)
{
    Conta *novo = (Conta*)malloc(sizeof(Conta));

    scanf("%d",&novo->num);
    scanf(" %s",novo->nome);
    scnaf("%f",&novo->saldo);

    novo->prox=lista;
    novo->ante=NULL;

    if(lista != NULL)
    {
        lista->ante = novo;
    } 
    return novo;
}
