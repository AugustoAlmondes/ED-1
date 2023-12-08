#include <stdio.h>
#include <stdlib.h>

/*Crie uma função recursiva que calcule a exponenciação de
um valor b por um expoente p sem usar o operador de
exponenciação.*/
int exp(int b, int p)
{
    if (p == 0)
    {
        return 1;
    }
    return b * exp(b, p - 1);
}

/*Escreva uma função recursiva que escreva na tela todos os
números inteiros positivos desde um valor K informado pelo
usuário até 0.*/
void esc(int K)
{
    if (K < 0)
    {
        return 1;
    }
    printf("%d ", K);
    return esc(K - 1);
}

/*Escreva um algoritmo recursivo que escreva na tela a soma
de todos os números inteiros positivos de K até 0.*/
void soma(int K, int aux)
{
    if (K == 0)
    {
        return 1;
    }
    aux = aux + K;
    printf("%d ", aux);
    return soma(K - 1, aux);
}

/*Escreva uma função recursiva que calcule a soma de todos
os números compreendidos entre os valores A e B passados
por parâmetro.*/
int soment(int A, int B)
{
    if (A == B)
    {
        return 0;
    }
    return A + soment(A + 1, B);
}

/*Escreva uma função recursiva que calcule os juros
compostos de um valor. Para isso o programa deverá ler um
valor inicial, o número de meses e a taxa de juros ao mês, e
passar estes valores à função como parâmetros.*/
float caljur(float v, int m, float j)
{
    if (m == 0)
    {
        return v;
    }
    return (1 + j) * caljur(v, m - 1, j);
}

/*Escreva uma função que faça a procura sequencial de um
valor passado por parâmetro num vetor também passado por
parâmetro.*/
int procurar(int v, int p, int t)
{
    if (p == v)
    {
        return t + 1;
    }
    return procurar(v, p += 1, t += 1);
}

int main()
{
    int b = 5;
    int p = 3;
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    printf("1 - Exponeciacao de %d elevado a %d: %d \n", b, p, exp(b, p));
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    system("PAUSE");
    system("cls");
    printf("-----------------------------------------------------------------------\n");
    printf("2 - Numeros positivos ate K: \n");
    int K = 10;
    printf("Valor de K: %d\n", K);
    esc(K);
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    system("PAUSE");
    system("cls");
    printf("-----------------------------------------------------------------------\n");
    printf("3 - Soma de numero inteiros ate K: \n");
    printf("Valor de K: %d\n", K);
    int aux = 0;
    soma(K, aux);
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    system("PAUSE");
    system("cls");
    printf("-----------------------------------------------------------------------\n");
    int A = 0;
    int B = 10;
    printf("4 - Soma dos numeros entre A(%d) e B(%d): %d", A, B, soment(A, B));
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    system("PAUSE");
    system("cls");
    printf("-----------------------------------------------------------------------\n");
    float valor;
    int tempo;
    float juros;
    float montante = 0.0;
    printf("5 - Calcular juros \n");
    printf("Valor Inicial: ");
    scanf("%f", &valor);
    printf("Quantidade de Meses: ");
    scanf("%d", &tempo);
    printf("Valor Juros (decimal): ");
    scanf("%f", &juros);
    printf("Valor do Juros Composto: %.2f", caljur(valor, tempo, juros));
    int valor2 = 0;
    int tamanho = 0;
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    system("PAUSE");
    system("cls");
    printf("-----------------------------------------------------------------------\n");
    printf("6 - Procurar numero em vetor\n");
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
    }
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    int *pont = vetor;
    printf("VETOR PREENCHIDO DE 0 a %d", tamanho - 1);
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("digite o valor que deseja procurar dentro do intervalo: ");
    scanf("%d", &valor2);
    printf("\n");
    if ((valor2 > tamanho - 1) || (valor2 < 0))
    {
        printf("-----------------------------------------------------------------------\n");
        printf("\n");
        printf("Valor nao encontrado\n");
        printf("-----------------------------------------------------------------------\n");
    }
    else
    {
        tamanho = 0;
        printf("-----------------------------------------------------------------------\n");
        printf("O valor porcurado esta na posicao: %d", procurar(valor2, *pont, tamanho));
        printf("\n");
        printf("-----------------------------------------------------------------------\n");
    }
}

