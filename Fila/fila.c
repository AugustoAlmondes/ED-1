#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

struct fila
{
    char nome[100];
    struct fila *prox; 
};

Fila* fila_cria ()
{
    return NULL;
}

Fila *fila_insere (Fila* f)
{
    Fila *aux, *novo = (Fila*)malloc(sizeof(Fila));
    printf("Digite o nome: ");
    scanf(" %s[^\n]s",novo->nome);
    novo->prox = NULL;
    
    if(f == NULL)
    {
        return novo;
    }
    else
    {
        aux = f;
        while (aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        return f;
    }
}

Fila *fila_retira (Fila* f)
{
    Fila *aux = f;

    if((fila_vazia(f))==0)
    {
        if(aux->prox == NULL)
        {
            free(aux);
            return NULL;
        }
        f = aux->prox;
        free(aux);
        printf("\num usuario foi retirado\n");
        return f;
    }
    else
    {
        printf("\nFILA VAZIA\n");
    }
}

int fila_vazia (Fila* f)
{
    if (f)
    {
        return 0;
    }
    return 1;
    
}

void mostrar_todos_elementos_fila(Fila *f)
{
    printf("\nMOSTRAR TODOS DA FILA\n");
    if((fila_vazia(f))==0)
    {
        Fila *aux = f;
        while (aux != NULL)
        {
            printf("Nome: %s\n",aux->nome);
            aux = aux->prox;
        }
    }
    else
    {
        printf("\nFILA VAZIA\n");
    }
    
}

Fila *fila_libera (Fila* f)
{
     if((fila_vazia(f))==0)
    {
        Fila *aux = f;
        while (aux->prox!= NULL)
        {   
            aux = fila_retira(aux);
            aux = aux->prox;
        }
            printf("\nFila removida\n");
            return NULL;

    }
    else
    {
        printf("\nFILA VAZIA\n");
    }
    
}

void mostrar_inicio(Fila *f)
{
    printf("\nPrimeiro da Fila: %s\n",f->nome);
}
void mostrar_fim(Fila *f)
{
    Fila *aux = f;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    printf("\nUltimo do fila: %s\n", aux->nome);
}