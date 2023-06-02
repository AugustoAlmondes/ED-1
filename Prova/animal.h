typedef struct animal Animal;

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAn(Animal *rebanho);
Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerAn(Fazenda *fazenda, int id_animal);
/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/