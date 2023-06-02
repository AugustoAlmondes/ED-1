#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main(){
    Trans *transportadora = CriarTrans();
    int op = 1;
    while(op != 0) {
        printf("0 - Sair\n1 - Inserir Cliente\n"
        "2 - Adicionar Produto\n"
        "3 - Entregar Produto Primeira Vez\n"
        "4 - Entregar Produto (Últimas tentativas)\n"
        "5 - Reembolso\n"
        "6 - Mostrar Todos\n"
        "7 - Mostrar Rotas\n"
        "8 - Mostrar Produtos Não Entregues\n"
        "9 - Mostrar Devolução\n"
        "10 - Mostrar Score");
        scanf("%d", &op);
        switch(op) {
            case 1:
                transportadora = inserirCliente(transportadora);
                break;
            case 2:
                transportadora = adiconarProdutos(transportadora);
                break;
            case 3:
                transportadora = entregarFila(transportadora);
                break;
            case 4:
                transportadora = entregarPilha(transportadora);
                break;
            case 5:
                transportadora = entregarDevolucao(transportadora);
                break;
            case 6:
                mostrarTodos(transportadora);
                break;
            case 7:
                mostrarRotas(transportadora);
                break;
            case 8:
                mostrarPilha(transportadora);
                break;
            case 9:
                mostrarDevolucao(transportadora);
                break;
            case 10:
                scoreDaTransportadora(transportadora);
                break;
            
            default:
                printf("Valor incorreto!\n");
                break;
        }   
    }
}