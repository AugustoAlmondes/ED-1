#include<stdio.h>
#include<stdlib.h>
#include"fila.h"


int main()
{
    Fila *p;

    p = fila_cria();
    
    p = fila_retira(p);

    mostrar_todos_elementos_fila(p);

    p = fila_insere(p);

    p = fila_insere(p);

    p = fila_insere(p);

    p = fila_insere(p);

    printf("\n____________________\n");
    mostrar_inicio(p);
    mostrar_fim(p);
    printf("\n____________________\n");

    mostrar_todos_elementos_fila(p);

    printf("\n____________________\n");

    printf("\nREMOVER USUARIO\n");
    p = fila_retira(p);

    mostrar_todos_elementos_fila(p);

    printf("\n____________________\n");

    printf("\nLIBERAR FILA \n"); 
    p = fila_libera(p);
    
    printf("\n____________________\n");
    mostrar_todos_elementos_fila(p);
}