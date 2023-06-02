#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"teste.h"

struct conta
{
    float saldo;
    int num_cont;
    char titular[100];
};

Conta *criarlistaEstatica(int tamanho)
{
    Conta *conta;
    conta = (Conta*)calloc(tamanho,sizeof(Conta));
    return conta;

}

Conta *inserirElementos(Conta *listacontas, int posi, int tamanho)
{
    srand(time(NULL));
    if((posi >= 0) && (posi< tamanho))
    {
        int opcao = 0;
        if(listacontas[posi].num_cont != 0)
        {
            printf("Essa posicao ja esta preenchida\nDeseja altera-la?\n1 - SIM\n2 - NAO\nOpcao: ");
            scanf("%d",&opcao);
            if(opcao == 1)
            {
                printf("Posicao existe\n");
                listacontas[posi].num_cont = 1 + rand()%1000;
                printf("Digite o nome: ");
                scanf(" %s",listacontas[posi].titular);

                printf("Digite o saldo: ");
                scanf(" %f",&listacontas[posi].saldo);
            }
            else
            {
                return listacontas;
            }
        }
        else
        {
            printf("Posicao existe\n");
            listacontas[posi].num_cont = 1 + rand()%1000;
            printf("Digite o nome: ");
            scanf(" %s",listacontas[posi].titular);

            printf("Digite o saldo: ");
            scanf(" %f",&listacontas[posi].saldo);
        }

    }
    else
    {
        printf("Essa posicao nao existe\n");
    }
     return listacontas;
}
void removerElemento(Conta *listacontas, int tamanho)
{
    int numero;
    int aux;
    printf("Digite o numero da conta: ");
    scanf("%i",&numero);

    if(numero == 0)
    {
        printf("Essa conta nao esta preenchida\n");
    }
    else
    {
        int i = buscarElemento(listacontas,tamanho,numero);
        if(i == -1)
        {
            printf("Numero de conta inexistente\n");
        }
        else
        {
            listacontas[i].num_cont = 0;
            free(listacontas[i].titular);
            listacontas[i].saldo = 0.0;
            printf("Conta de numero %i removida.\n", numero);
        }
    }
} //remover pelo numero da conta

int buscarElemento(Conta *listacontas, int tamanho, int numero)
{
    for (int i = 0; i < tamanho; i++)
    {
        if(numero == listacontas[i].num_cont)
        {
            return i;
        }
    }
    return -1;
}

void mostarElemento(Conta elemento)
{
    printf("\n");
    printf("Numero da conta: %d \n",elemento.num_cont);
    printf("Titular: %s \n",elemento.titular);
    printf("Saldo da conta: %.2f \n",elemento.saldo);
}

void mostarTodos(Conta *listacontas, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(listacontas[i].num_cont != 0)
        {
            printf("Conta %d\n",i);
            mostarElemento(listacontas[i]);
            printf("\n");
        }
    }
}
void liberar(Conta *listacontas)
{
    free(listacontas);
}

void mostrarsaldo(Conta *listacontas, int tamanho, int numero)
{
    int i = buscarElemento(listacontas,tamanho,numero);

    if(i == -1)
    {
        printf("Essa conta nao existe\n");
    }
    else
    {
        if(listacontas[i].num_cont != 0)
        {
            printf("Saldo da conta: %.2f\n",listacontas[i].saldo);
        }
        else
        {
            printf("\nEssa conta nao esta preenchida\n");
        }
    }
}