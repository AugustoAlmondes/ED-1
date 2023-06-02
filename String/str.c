#include<stdio.h>
#include<stdlib.h>
#include"str.h"
int tamanho(char *str)
{
    int i = 0;
    for(i = 0;;i++)
    {
        if(str[i]=='\0')
        {
            break;
        }
    }
    return i;
}

int comparar(char *str1, char *str2)
{
    for(int i = 0; ;i++)
    {
        if(str1[i] != str2[i])
        {
            return 1;
        }
        if((str1[i] == '\0') && (str2[i] == '\0'))
        {
            break;
        }
    }
    return 0;
}

char concatenar(char *str1, char *str2)
{
    int cont = 0,i = 0;

    while (str1[cont]!='\0')
    {
        cont++;
    }
    str1[cont] = ' ';
    cont+=1;

    for ( i = 0; str2[i]!='\0'; i++)
    {
        str1[cont] = str2[i];
        cont++;
    }

    str1[cont]='\0';
    
}

void liberar(char *str)
{
   free(str);
  
}