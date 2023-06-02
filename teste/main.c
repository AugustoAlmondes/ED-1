#include<stdio.h>
#include<stdlib.h>
#include"operacoes.h"
//criar ".o" = gcc -c 
//linkar os .o == gcc -o

int main()
{
    float x = 87, y = 65;    
    printf("Soma: %.2f\n", soma(x,y));
    printf("subtracao: %.2f\n", subtracao(x,y));
    printf("multiplicar: %.2f\n", multiplicar(x,y));
    printf("dividir: %.2f\n", dividir(x,y));

}