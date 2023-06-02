#include <stdio.h>
#include<stdlib.h>
#include "cliente.h"

struct cliente
{
    int id;
    /*char nome[100];
    int CEP;*/
    struct cliente *prox;
};

struct rota
{
    Cliente *cliente;
    struct rota *prox;
};

Cliente *criarlista()
{
    return NULL;
}

Cliente *inserir(Cliente *cliente)
{
    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    printf("Digite o id: ");
    scanf("%d",&novo->id);

    novo->prox = cliente;
    return novo;
}

void MostrarTodos(Cliente *cliente)
{
    Cliente *aux;
    while (aux)
    {
        printf("Id - %d\n",aux->id);
        aux = aux->prox;
    }
}

Cliente *organizar(Cliente *cliente)
{

}
