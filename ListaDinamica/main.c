#include <stdio.h>
#include <stdlib.h>

#include "listadinamicasimples.h"

int main(int argc, char const *argv[]){
	Conta *lista, *numero;
	int verifica = 0, valor = 0, busca = 0, valorRemove = 0;

	lista = criarLista();
	
	lista = inserirFim(lista);
	lista = inserirInicio(lista);
	
	lista = inserirOrdenado(lista);
	lista = inserirOrdenado(lista);

	mostrarLista(lista);

	/*printf("Informe a posicao onde o elemento que sera removido: ");
	scanf("%d", &valorRemove);
	lista = remover(lista, valorRemove);

	mostrarLista(lista); 
	
	printf("Digite o numera da conta que voce deseja buscar: ");
	scanf("%d", &busca);
	numero = buscar(lista, busca);
	if (numero == NULL){
		printf("O elemento nao foi encontrado na lista!\n");
	} else {
		printf("Ponteiro do no da lista que representa o elemento: %d\n", numero);
	} */
	
	verifica = listaVazia(lista);
	if (verifica == 0){
		printf("\nA lista nao esta vazia!");
	} else {
		printf("\nA lista esta vazia!");
	}
	liberarLista(lista);
	return 0;
}