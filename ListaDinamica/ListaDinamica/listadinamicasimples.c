#include <stdio.h>
#include <stdlib.h>

#include "listadinamicasimples.h"


struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta *lista){
	Conta *new = (Conta*) malloc (sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = lista;
	return new;
}

Conta *inserirFim(Conta *lista){
	Conta *aux, *new = (Conta*) malloc (sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = NULL;
	if (!lista){
		return new;
	} else {
		aux = lista;
		while (aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = new;
		return lista;
	}
	
}

Conta *inserirOrdenado(Conta *lista){
	Conta *aux, *new = (Conta*) malloc (sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	if (lista == NULL){
		new->prox = lista;
		return new;
	} else {
		aux = lista;
		while (aux->prox && new->num_conta > aux->prox->num_conta){
            aux = aux->prox;
        }
		new->prox = aux->prox;
		aux->prox = new;
		return lista;	
		}

}

void mostrarLista(Conta *lista){
	//Crie uma função recursiva para mostrar todos as contas da Lista.
	Conta *aux = lista; 
	if (aux != NULL){
		printf("\nContas: \n");
		printf("Nome: %s\nSaldo: %.2f\nNum conta %d\n", aux->titular, aux->saldo, aux->num_conta);
		printf("\n");
		mostrarLista(aux->prox); //A função mostrarLista verifica se o ponteiro para o nó atual não é NULL, se não for, imprime o seu dado e chama a si mesma para o próximo nó na lista encadeada.
	}
}

/*
Conta *remover(Conta *lista, int valor){
	Conta *ant = NULL;
	Conta *p = lista;
	for (int i = 0; i < p; i++){
		if (i == valor && p != NULL){
			ant = p;
			p = p->prox;
		}
	}
	if (p == NULL){
		return p;
	} else if (ant == NULL){
		p = p->prox;
	} else {
		ant->prox = p->prox;
	}
	free(p);
	return lista;
	
} */


Conta *buscar(Conta *lista, int valor){
	int busca = 0;
	for (busca = lista; busca != NULL; busca = lista->prox){
		if (lista->num_conta == valor){
			return busca;
		}
	}
	return NULL;
}
/*
Conta *alterar(Conta *lista, int oldValue, int newValue){

}
*/
int listaVazia(Conta *lista){
	return(lista == NULL);
}

void liberarLista(Conta *lista){
	Conta *p = lista;	
	while (p != NULL) {
		Conta *t = p->prox; 
		free(p); 
		p = t;
	}

}

