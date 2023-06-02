#include<stdio.h>
#include<stdlib.h>
#include"imagem.h"

int main()
{
    Imagem *img;

    int valor;

    img=criarImagem(15,10);

    preencherImagem(img);

    imprimirImagem(img);

    valor = getPixelValue(img,9,4);

    if(valor == -1)
    {
        printf("Essa posicao nao existe\n");
    }
    else
    {
        printf("O valor na posicao eh: %d\n", valor);
    }

    liberarimagem(img);

    /*1 - Comente o que acontecer com as linhas 15 e 16
    img->pixels[10].valor = 255;
    printf("%d ", img->pixels[10].valor);

    Em tese, o processo acima tem o objetivo de atribuir um valor em um determinado local do pixel, porém
    a atribuição não irá funcionar porque o valor está sendo atribuido na main.

    */
   
   /*2 - Comente o que acontece com as linhas 20 e 21
   setPixelValue(img, 3, 2, 255);
   printf("Valor da posicao 3, 2 %d \n", getPixelValue(img,3,2));

   A operação realizada aqui irá atribuir um valor a uma determinada posição, utilizando a função setPixelValue(), e logo
   em seguida fará a busca, através da função getPixelValue(), para poder exibi-lo. diferente da ultima questão ( questão 1)
   esse processo irá funcionar devido o fato de que a atribuição e busca está sendo feito dentro do arquivo imagem.c.
   */
    return 0;
}