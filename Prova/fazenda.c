#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "animal.h"
#include "criador.h"
#include "fazenda.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

struct fazenda
{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas()
{
	return NULL;
}

Fazenda *cadastrarFz(Fazenda *fazendas)
{
	srand(time(NULL));
	Fazenda *fazenda_no = (Fazenda*)malloc(sizeof(Fazenda));
	
	fazenda_no->id_fazenda = rand()%100-10;
	fazenda_no->rebanho = cadastrarAn(fazenda_no->rebanho);


}