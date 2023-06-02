#include<stdio.h>
#include<stdlib.h>
#include"str.h"

//criar ".o" = gcc -c 
//linkar os .o == gcc -o

int main()
{
    char nome[] = {"Augusto"};
    char nome2[] = {"Almondes"};

    char *prt = ler();
//tamanho
    char nome_junto;
    int valor = 0;
    valor = tamanho(nome);
    printf("%d\n", valor);

//Verificar
    int verificar = 0;
    verificar = comparar(nome, nome2);

    if (verificar == 1)
    {
        printf("Nomes sao diferentes\n");
    }
    else
    {
        printf("Nomes sao iguas\n");
    }

//Concatenar
    concatenar(nome,nome2);
    printf("%s ", nome);

//Liberar
    liberar(nome);
}
