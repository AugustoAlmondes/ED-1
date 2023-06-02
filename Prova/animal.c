#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include"fazenda.h"

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais()
{
	return NULL;
}

Animal *cadastrarAn(Animal *rebanho)
{
	Animal *animal_no = (Animal*)malloc(sizeof(Animal));

	printf("Digite o Sexo do animal: ");
	scanf(" %[^\n]s",animal_no->sexo);
	printf("Digite o Peso do animal: ");
	scanf(" %f",animal_no->peso);
	printf("Digite o Status do animal: ");
	scanf(" %d",animal_no->status);
	
	return animal_no;
}

Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal)
{

}//obervar para atualizar o status do animal na fazenda de destino