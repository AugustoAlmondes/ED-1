#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct conta
{
    int id;
    char nome[100];
    struct conta *prox;
};

/*struct pilha
{
    Conta *topo;
};

Pilha *criarPilha(Pilha *p)
{
    return NULL;
}*/


Conta *criarPilha(Conta *p)
{
    return NULL;
}
Conta *Inserir(Conta *lista)
{
    Conta *new = (Conta*) malloc (sizeof(Conta));
    printf("Digite Nome: ");
    scanf(" %[^\n]s",new->nome);
    new->id = rand() % 100 + 10;
    
    new->prox = lista;
    return new;
}

Conta *Remover(Conta *lista)
{
    int num;
    num = (Vazio(lista));
    if(num == 1)
    {
        printf("Lista Vazia\n");
    }
    else
    {
    Conta *aux = lista;
    lista = aux->prox; 
    free(aux);
    printf("\nUnidade Removida\n");
    }
    return lista;

}

void Mostrartopo(Conta *lista)
{
    Conta *aux = lista;
    int num;
    num = (Vazio(lista));
    if(num == 1)
    {
        printf("Lista Vazia\n");
    }
    else
    {
        printf("Nome - %s\n",aux->nome);
    }
}

int Vazio(Conta *lista)
{
    if(lista == NULL)
    {
        return 1;
    }
    return 0;
}
Conta *Liberar(Conta *lista)
{
    printf("\nLiberar\n");
    while (lista)
    {
        Remover(lista);
        lista = lista->prox;
    }
    return NULL;
}
void MostrartodaPilha(Conta *lista)
{
    while (lista)
    {
        printf("Nome - %s\n",lista->nome);
        lista = lista->prox;
    }
    
}
