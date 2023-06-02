#include <stdio.h>
#include <stdlib.h>

#include "listaDinamicaDupla.h"

struct conta{
	float saldo;
	char titular[100];
	int num;
	struct conta *prox, *ant;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta *lista){
	Conta *new = (Conta*) calloc(sizeof(Conta),1);
	new->num = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->ant = NULL;
	new->prox = lista;
	if (lista)
		lista->ant = new;
	return new;
}

Conta *inserirFim(Conta *lista){
	Conta *new = (Conta*) calloc(sizeof(Conta),1), *aux = lista;
	new->num = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->ant = NULL;
	new->prox = NULL;
	if (!lista)
		return new;

	while(aux->prox != NULL){
		aux = aux->prox;
	}

	new->ant = aux;
	aux->prox = new;
	return lista;
}

Conta *inserirOrdenado(Conta *lista){
	Conta *aux = lista, *new = (Conta*) malloc(sizeof(Conta));
	//srand(time(NULL));
	//new->num = rand() % 100 + 10;
	printf("Digite o numero: ");
	scanf("%d", &new->num);
	printf("Nome - ");
	scanf(" %s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	printf("\n");
	new->ant = NULL;
	new->prox = NULL;

	if(!(lista)){
		return new;
	} 
	if(new->num < lista->num){
		new->ant = NULL;
		new->prox = lista;
		return new;
	}
	while(aux->prox != NULL && new->num > aux->prox->num){
		aux = aux->prox; 
	}
	new->ant = aux;
	new->prox = aux->prox; // new recebe a proxima posição 
	aux->prox = new; // aux que é menor que new recebe new
	return lista;
}

Conta *remover(Conta *lista, int valor){
	Conta *aux = lista, *auxFree = NULL;
	if(!listaVazia(lista)) return NULL;
	else if(aux->num == valor){
		if(aux->prox == NULL) return NULL; // se prox é null, isso significa que só tem uma posicion
		auxFree = aux; // primeria posicion é atribuida a variavel de remoção
		aux = aux->prox; // aux recebe a segunda posicion, ou seja, a segunda posicion vira a primeira
		aux->ant = NULL; // agora deixa null o ant da primeira posicion
		free(auxFree);
		return aux; 
	}

	aux = buscar(lista, valor);

	if(aux){
		auxFree = aux;		
		if(aux->prox == NULL){
			aux->ant->prox = aux->prox; // prox é null, se ele é null ele não tem ponteiro para o anterior
			free(auxFree);
		}else{		
			aux->ant->prox = aux->prox; // o proximo do anterior do valor a ser removido recebe o proximo do valor a ser removido
			aux->prox->ant = aux->ant;
			free(auxFree);
		}
	}
	return lista;
}

Conta *buscar(Conta *lista, int valor){
	Conta *aux = lista;
	if(!listaVazia(lista)) return NULL; // retorna null se a lista estiver vazia
	while(aux != NULL && aux->num != valor){ 
		aux = aux->prox;
	}
	if(aux->num == valor) return aux; // retorna a posicion em que o valor estar
	return NULL;
}

Conta *alterar(Conta *lista, int oldValue, int newValue){
	Conta *aux = lista;
	aux = buscar(lista, oldValue);

	if(aux){
		aux->num = newValue;
		printf("Informe o nome: ");
		scanf("%s", aux->titular);
		printf("Informe o saldo: ");
		scanf("%f", &aux->saldo);
	}
	return lista;
}

int listaVazia(Conta *lista){
	if(lista) return 1;
	return 0;
}

void mostrarLista(Conta *lista){
	Conta *aux = lista;
    while(aux){
		printf("Titular: %s\n", aux->titular);
		printf("Numero: %d\n", aux->num);
		printf("Saldo: %.2f\n\n", aux->saldo);
		// if(!aux->prox) break;
		aux = aux->prox;
	}
}

Conta *liberarLista(Conta *lista){
    Conta *auxFree;
    while (lista != NULL) {
        auxFree = lista;
        lista = lista->prox;
        free(auxFree);
    }
	return NULL;
}