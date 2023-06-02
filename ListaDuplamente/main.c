#include <stdio.h>
#include <stdlib.h>

#include "duplamente.h"

int main(int argc, char const *argv[]){
	Conta *lista = NULL;
	int op = -1, v1, v2;

	while (op != 0){
		printf("\n1 - Inserir no inicio\n"
		"2 - Inserir no Fim\n"
		"3 - Inserir ordenado\n"
		"4 - Remover\n"
		"5 - Alterar\n"
		"6 - Mostrar\n"
		"7 - Liberar\n\n"
		"Informe a opcao: "
		);
		scanf("%d",&op);
		switch (op){
			case 1:
				printf("\nInserir no inicio:\n ");
				lista = inserirInicio(lista);
				break;
			case 2:
				printf("\nInserir no fim: \n");
				lista = inserirFim(lista);
				break;
			case 3:
				printf("\nInserir no ordenado:\n ");
				lista = inserirOrdenado(lista);
				break;
			case 4:
				printf("\nRemover: \n"
				"Informe o numero: ");
				scanf("%d", &v1);
				lista = remover(lista, v1);
				break;
			case 5:
				printf("\nRemover: \n"
				"Informe o numero velho: ");
				scanf("%d", &v1);
				printf("Informe o numero novo: ");
				scanf("%d", &v2);
				lista = alterar(lista, v1, v2);
				break;
			case 6:
				printf("\nMostrar: \n");
				mostrarLista(lista);
				break;
			case 7:
				lista = liberarLista(lista);
				break;
			default:
				printf("\nValor invalido\n");
				break;
		}
	}
	return 0;
}