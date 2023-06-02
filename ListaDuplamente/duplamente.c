#include <stdio.h>
#include <stdlib.h>

#include "duplamente.h"

struct conta{
	float saldo;
	char titular[100];
	int num;
	struct conta *prox, *ant;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta*lista)
{
    Conta *novo = (Conta*) calloc (sizeof(Conta),1);
    novo->num = rand() % 100 + 10;
    printf("Digite o nome: ");
    scanf(" %[^\n]s",novo->titular);
    printf("Digite o Saldo: ");
    scnaf("%d", &novo->saldo);
    novo->ant = NULL;
    novo->prox = lista;
    if(lista)
    {
        lista->ant = novo;
    }
    return novo;
}
Conta *inserirFim(Conta *lista)
{
    Conta *novo = (Conta*) calloc (sizeof(Conta),1);
    Conta *aux = lista;
    novo->num = rand() % 100 + 10;
    printf("Digite o nome: ");
    scanf(" %[^\n]s",novo->titular);
    printf("Digite o Saldo: ");
    scnaf("%d", &novo->saldo);

    novo->ant = NULL;
    novo->prox = NULL;
    
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    novo->ant = aux;
    aux->prox = novo;
    return lista;
}

Conta *inserirOrdenado(Conta *lista)
{
    	Conta *aux = lista, *novo = (Conta*) malloc(sizeof(Conta));
            novo->num = rand() % 100 + 10;
    printf("Digite o nome: ");
    scanf(" %[^\n]s",novo->titular);
    printf("Digite o Saldo: ");
    scnaf("%f", &novo->saldo);

    novo->ant = NULL;
    novo->prox = NULL;

    if(lista == NULL)
    {
        return novo;
    }

    if(novo->num < lista->num)
    {
        novo->ant = NULL;
        novo->prox = lista;
        return novo;
    }

    while (aux->prox!= NULL&& novo->num > aux->prox->num)
    {
    aux = aux->prox;
    }

    novo->ant = aux;
    novo->prox = aux->prox;
    aux->prox = novo;
    return lista;   
}

Conta *remover(Conta *lista, int numero)
{
    Conta *aux2, *aux = lista; 

    if(lista == NULL)
    {
        return NULL;
    }
    if (aux->num == numero)
    {
        if (aux->prox == NULL)
        {
            return NULL;
        }
        aux2 = aux;
        aux = aux->prox;
        aux->ant = NULL;
        free(aux2);
        return aux;
    }
    
    aux = buscar(lista, numero);

    if(aux != NULL)
    {
        aux2 = aux;
        if(aux->prox == NULL)
        {
            aux->ant->prox = aux->prox;
            free(aux2);
        }
        else
        {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux2);
        }
    }
    return lista;
}

Conta *buscar(Conta *lista, int numero){
	Conta *aux = lista;
	if(!listaVazia(lista)) return NULL; // retorna null se a lista estiver vazia
	while(aux != NULL && aux->num != numero){ 
		aux = aux->prox;
	}
	if(aux->num == numero) return aux; // retorna a posicion em que o numero estar
	return NULL;
}

Conta *alterar(Conta *lista, int valor1, int valor2){
	Conta *aux = lista;
	aux = buscar(lista, valor1);

	if(aux){
		aux->num = valor2;
		printf("Digite o novo nome ");
		scanf(" %[^\n]s", aux->titular);
		printf("Digite o saldo da conta: ");
		scanf("%f", &aux->saldo);
	}
	return lista;
}

int listaVazia(Conta *lista){
	if(lista) 
    {
        return 1;
    }
	return 0;
}

void mostrarLista(Conta *lista){
	Conta *aux = lista;
    while(aux){
		printf("Titular: %s\n", aux->titular);
		printf("Numero: %d\n", aux->num);
		printf("Saldo: %.2f\n\n", aux->saldo);
		aux = aux->prox;
	}
}

Conta *liberarLista(Conta *lista){
    Conta *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
	return NULL;
}
