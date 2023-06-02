#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

struct endereco{
    int cep;
	char cidade[50], estado[2], logradouro[200];
};

struct cliente{
    int id;
    char nome[100];
    Endereco local;
    Produto *produtos;
    struct cliente *prox;
};

struct rota{
    Cliente *clientes;
    Produto *produtos;
    struct rota *prox;
};

struct produto{
    int id;
    char nome[50];
    Produto *prox;
};

struct pilha{
    Cliente *clientes;
    struct pilha *prox;
};

Cliente *criarListaCliente(){
    return NULL;
}

Rota *criarRota(){
    return NULL;
}

struct trans{
    float score;
    Cliente *clientes;
    Rota *rotas, *devolucao;
    Pilha *pilhas;
};

Trans *CriarTrans(){
    Trans *aux = (Trans *) malloc(sizeof(Trans));
    aux->score = 0;
    aux->pilhas = NULL;
    aux->devolucao = NULL;
    return aux;
}

Trans *inserirCliente(Trans *transportadora){
    Cliente *newCliente = (Cliente *) malloc(sizeof(Cliente)), *aux = transportadora->clientes;

    printf("Informe o id: ");
	newCliente->id = rand() % 1000;

     newCliente->produtos = NULL;

	printf("Informe o nome do cliente: ");
	scanf(" %s", newCliente->nome);

    printf("Informe o CEP: ");
	scanf("%d", &newCliente->local.cep);
	printf("Informe o nome da cidade: ");
	scanf(" %s", newCliente->local.cidade);
	printf("Informe o a sigla do estado: ");
	scanf(" %s", newCliente->local.estado);
	printf("Informe o logradouro: ");
	scanf(" %s", newCliente->local.logradouro);

    newCliente->prox = NULL;

	if(!vazio(transportadora->clientes)) {
        transportadora->clientes = newCliente;
        return transportadora;
    } //Verifica se a lista estar vazia, se sim, ele retorna o newCliente
    else if(newCliente->local.cep <= transportadora->clientes->local.cep){ //verifica se a primeira posição é maior que o novo cliente, se for o novo cliente fica no inicio
        newCliente->prox = transportadora->clientes;
        transportadora->clientes = newCliente;
        return transportadora;
    }else{
        while(aux->prox != NULL && aux->prox->local.cep < newCliente->local.cep)aux = aux->prox; // procura a posição em que o novo cliente se encaixa, se encontrar ele para em uma posição para uma posição atras, ou seja, essa posição é menor que o novo cliente e a proxima posição é maio que o novo cliente, ou a proxima é null

        newCliente->prox = aux->prox; // aqui novo cliente recebe a proxima posição é maio que o novo cliente, seja ela, maior que novo cliente ou nula
        aux->prox = newCliente; // e aqui o proximo do anterior se torna o novo
        return transportadora;
    }
}

Cliente *liberarClientes(Cliente *clientes){
    Cliente *temp = clientes;
    while(temp){
        clientes = temp->prox; //clientes é atualizada para o próximo nó na lista, ou seja, temp->prox.
        if(temp->produtos) temp->produtos = liberarProdutos(temp->produtos);
        free(temp); //A memória alocada para o nó atual, representada por temp, é liberada com a função free.
        temp = clientes; //Avariável temp é atualizada para o próximo nó, ou seja, clientes.
    }
    return NULL; //O endereço cliente não aponta para nenhum endereço da memória válido.
}

Cliente *buscarCliente(Cliente *clientes, int id){ // como o nome já diz ele procurar o cliente, se achar o retorna se não retorna null
    Cliente *aux = clientes;
    while(aux->prox){
        if(aux->id == id) return aux;
        aux = aux->prox;
    }
    if(aux->id == id) return aux;
    return NULL;
}

Trans *adiconarProdutos(Trans *transportadora){ //
    Produto *newProduto = (Produto*) malloc(sizeof(Produto));
    Cliente *aux;
    int id;

    printf("Informe o id do cliente: ");
    scanf("%d", &id);
    aux = buscarCliente(transportadora->clientes, id);
    if(aux != NULL){ // se o cliente existir ele faz o cadastro do produto
        newProduto->id = rand() % 100 + 10;
        printf("Informe o nome do produto: ");
        scanf(" %s", &newProduto->nome);
        if(aux->produtos){ // verifica se ja exite algum produto na lista
            newProduto->prox = aux->produtos;
            aux->produtos = newProduto;
        }else{ // esse else é pra caso seja a primeria vez
            newProduto->prox = NULL;
            aux->produtos = newProduto;
            transportadora = inserirRota(transportadora, aux); // ele insere em rota
        }
    }
    return transportadora;
    printf("Aaaaaaa\n\n");
}

void mostrarProduto(Produto *produtos){ // recebe a lista de produtos de um clinte e printa, ainda não estar completa ainda falta o while pra percorre.
    Produto *aux = produtos;
    while(aux){
        printf("Nome do produto: %s\nId do produto: %d\n\n", aux->nome, aux->id);
        aux = aux->prox;
    }
}

int vazio(Cliente *clientes){ // verificação de lista vazia
    if(clientes) return 1;
    return 0;
}

void mostrarTodos(Trans *transportadora){ // mostrar todos os dados dos clientes
    Cliente *aux = transportadora->clientes;
    while(aux != NULL){
        if(aux->id < 1000) mostrarUnico(aux);
        aux = aux->prox;
    }
}

Trans *inserirRota(Trans *transportadora, Cliente *clientes){
    Rota *newRota = (Rota *) malloc(sizeof(Rota)), *aux = transportadora->rotas;
    newRota->clientes = clientes;
    newRota->produtos = clientes->produtos;
    newRota->prox = NULL;

    if(!transportadora->rotas){ //quando não exite rotas
        transportadora->rotas = newRota;
    }else{
        while(aux->prox) aux = aux->prox;
        aux->prox = newRota; // quando existe adiciona no final
    }
    return transportadora;
}

void mostrarRotas(Trans *transportadora){
    Rota *aux = transportadora->rotas;

    if(aux){
        while(aux){
            if(aux->clientes) mostrarUnico(aux->clientes);
            if(aux->prox == NULL) break;
            aux = aux->prox;
        }
    }else{
        printf("Fila vazia\n");
    }
}

void mostrarUnico(Cliente *clientes){
    //Mostrar um unico cliente
    Cliente *aux = clientes;
    printf("Id: %d\nNome: %s\nCidade: %s\nEstado: %c%c\nLogradouro: %s\nCep: %d\n\n", aux->id, aux->nome, aux->local.cidade, aux->local.estado[0], aux->local.estado[1], aux->local.logradouro, aux->local.cep);
    if(aux->produtos) mostrarProduto(aux->produtos);
}

Trans *entregarFila(Trans *transportadora){
    //Rota *aux = rotas;
    int entregou = 0;

    if(transportadora->rotas != NULL){
        printf("Os produtos do cliente %s de id %d foram entregues? \n(1 - sim; 2 - não): ", transportadora->rotas->clientes->nome, transportadora->rotas->clientes->id);
        scanf("%d", &entregou);

        switch (entregou){
            case 1:
                // Se a entrega foi feita será liberado todos os produtos de um cliente
                transportadora = liberarRota(transportadora); //vai liberar a primeira posição da fila, liberar e retornar a segunda posição
                transportadora->score += 5;
                printf("Entrega efetuada!\n");
                return transportadora;
                break;
            case 2:
                transportadora = inserirPilha(transportadora);
                
                printf("Entrega não efetuada!\n");
                return transportadora;
                break;
            default:
                break;
        }
    }else{
        printf("Nenhuma rota cadastrada!\n");
        return transportadora;
    }
}

Pilha *criarPilha(){
    return NULL;
}

Trans *inserirPilha(Trans *transportadora){

    if(!transportadora->pilhas){
        Pilha *pilhas = (Pilha*)malloc(sizeof(Pilha));
        printf("Entrei1\n");
        pilhas->clientes = transportadora->rotas->clientes;
        pilhas->prox = NULL;
        transportadora->pilhas = pilhas;
        transportadora->rotas = transportadora->rotas->prox; 
        return transportadora;

    }else{
        Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
        printf("Entrei2\n");
        aux->clientes = transportadora->rotas->clientes;
        aux->prox = transportadora->pilhas;
        transportadora->pilhas = aux; 
        return transportadora;
    } 
}

void mostrarPilha(Trans *transportadora){
    if(transportadora->pilhas){
        if(transportadora->pilhas->clientes) mostrarTodos(transportadora);
    }else{
        printf("Pilha vazia\n");
    }
}

Trans *entregarPilha(Trans *transportadora){
    if(transportadora->pilhas){
        int entregou, i = 0;
        while(i<3){

             if(i == 2){
                transportadora->score += 0.8;
                transportadora = inserirDevolucao(transportadora);
                return transportadora;
            }
           
            printf("Os produtos do cliente %s de id %d foram entregues? \n(1 - sim; 2 - não): ", transportadora->pilhas->clientes->nome, transportadora->pilhas->clientes->id);
            scanf("%d", &entregou);

            switch (entregou){
                case 1:
                    transportadora = libararPilha(transportadora);
                    if(i == 0){
                        transportadora->score += 3;
                    }else if(i == 1){
                        transportadora->score += 2;
                    }
                    printf("Entrega efetuada!\n");
                    return transportadora;
                    break;
                case 2:
                    printf("Entrega não efetuada!\n");
                    break;
            default:
                printf("Opção não encontrada!\n");
                break;
            i++;
            }
        }
    }else{
        printf("Não existe pilhas\n");
    }
}

Trans *inserirDevolucao(Trans *transportadora){

    if(!transportadora->devolucao){
        Rota *devol = (Rota*)malloc(sizeof(Rota));
        printf("Entrei1\n");
        devol->clientes = transportadora->rotas->clientes;
        devol->prox = NULL;
        transportadora->devolucao = devol;
        transportadora->pilhas = transportadora->pilhas->prox; 
        return transportadora;

    }else{
        Rota *aux = (Rota*)malloc(sizeof(Rota));
        printf("Entrei2\n");
        aux->clientes = transportadora->pilhas->clientes;
        aux->prox = transportadora->devolucao;
        transportadora->pilhas = transportadora->pilhas->prox; 
        return transportadora;
    } 
}

Trans *entregarDevolucao(Trans *transportadora){
    if(transportadora->devolucao){
        Rota *aux = transportadora->devolucao;
        transportadora->devolucao->clientes = liberarClientes(transportadora->devolucao->clientes);
        transportadora->devolucao = transportadora->devolucao->prox;
        free(aux);
        return transportadora;
        //free(rotas);
    }
    return transportadora;
}

void mostrarDevolucao(Trans *transportadora){
    if(transportadora->devolucao) mostrarTodos(transportadora);
    else printf("Devolucao vazia\n");
}

void scoreDaTransportadora(Trans *transportadora){
    printf("Score da Transportadora %.2f\n", transportadora->score);
}

Trans *libararPilha(Trans *transportadora){
    if(transportadora->pilhas){
        Pilha *aux = transportadora->pilhas;
        liberarClientes(transportadora->pilhas->clientes);
        transportadora->pilhas = transportadora->pilhas->prox;
        return transportadora;
        free(aux);
    }
    return transportadora;
}

Trans *liberarRota(Trans *transportadora){
    if(transportadora->rotas){
        Rota *aux = transportadora->rotas;
        liberarClientes(transportadora->rotas->clientes);
        transportadora->rotas = transportadora->rotas->prox;
        return transportadora;
        free(aux);
    }
    return transportadora;
}

Produto *liberarProdutos(Produto *produtos){
    // essa função será usada para liberar todos os produtos de uma pessoa
    Produto *aux = produtos;

    do{
        produtos = aux->prox;
        free(aux);
        aux = produtos;
    }while(aux);
    return NULL;
}