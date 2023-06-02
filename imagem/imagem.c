#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "imagem.h"

/*a imagem é composta de pixel, cada pixel tem sua coordenada (x e y) e seu valor 
alem dos valores a imagem tambem tem a altura e largura*/

struct pixel
{
    int valor, x ,y;
};

struct imagem
{
    Pixel *pixels;
    int largura, altura;
};

Imagem *criarImagem(int largura, int altura)
{
    Imagem *img;
    img = (Imagem*)malloc(sizeof(Imagem));
    img->altura = altura;
    img->largura = largura;
    img->pixels = (Pixel*)malloc(largura*altura * sizeof(Pixel));
    return img;
}

void preencherImagem(Imagem *img)
{
    srand(time(NULL));
    for (int i = 0; i < img->altura; i++)
    {
        for(int j = 0; j < img->largura;j++)
        {
            setPixelValue(img, i, j,/*rand()%1000*/ 1);
        }
    }
}
    
void setPixelValue(Imagem *img, int i, int j, int valor)
{

    int k;

    k = i * img->largura+j;
    img->pixels[k].valor = valor;
    img->pixels[k].x = j;
    img->pixels[k].y = i;

}

void imprimirImagem(Imagem *img)
{
    int k = 0;
        for (int i = 0; i < img->altura; i++)
    {
        for(int j = 0; j < img->largura;j++)
        {
            k = i * img->largura+j;
            printf("%d ",img->pixels[k].valor);
        }
        printf("\n");
    }
}

void liberarimagem(Imagem *img)
{
free(img->pixels);
free(img);
}

int getPixelValue(Imagem *img, int y, int x)
{
    int k;
    if((y >= 0)&&(x >= 0)&&(y < img->altura)&&(x < img->largura))
    {
        k = y * img->largura+x;
        return img->pixels[k].valor;
    }
    else
    {
        return -1;
    }
}