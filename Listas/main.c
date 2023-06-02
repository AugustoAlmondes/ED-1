#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"teste.h"


int main()
{
    Conta *conta;

    int opcao = 0;
    int tamanho = 0;
    int posicao = 0;
    int numero = 0;
    int aux = 0;
    while(opcao != 6)
    {
        printf("\n");
        printf(
        "1 - criar lista\n"
        "2 - inserir elemento\n"
        "3 - remover elemento\n"
        "4 - mostrar todos\n"
        "5 - mostrar saldo\n"
        "6 - Sair\n"
        "Digite a opcao: "
        );
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 1:
        
        if(aux == 0)
        {
            printf("\nDigite o tamanho da lista: ");
            scanf("%d", &tamanho);
            conta = criarlistaEstatica(tamanho);
            aux = 1;
        }
        else
        {
            printf("Lista ja foi criada\n");
            printf("Deseja criar uma nova lista?\n 0 - SIM\n 1 - NAO\n");
            scanf("%d",&aux);
            
        }
        break;
        case 2:

            printf("Digite a posicao: ");
            scanf("%d",&posicao);
            conta = inserirElementos(conta,posicao,tamanho);
            break;

        case 3:

            removerElemento(conta, tamanho);
            break;
        
        case 4:
            mostarTodos(conta, tamanho);
            break;

        case 5:
            printf("Digite a conta que deseja ver o numero: ");
            scanf("%d", &numero);

            mostrarsaldo(conta,tamanho,numero);
            break;

        default:
        printf("Essa opcao nao existe");
            break;
        }
    }
}