#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int **preenchermatriz(int col, int lin)
{
    int **mat;
    mat = (int **)malloc(lin * sizeof(int *));

    for (int i = 0; i < lin; i++)
    {
        mat[i] = (int *)malloc(sizeof(int) * col);
    }

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] =  rand() % 10;
        }
    }
    return mat;
}

void mostrarDados(int lin, int col, int **mat)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

float *MaMeMe(int col, int lin, int **mat)
{
    int aux = 0;
    float *val;

    val = (float *) malloc(sizeof(float) * 3);

    val[0] = val[1] = mat[0][0];
    val[2] = 0;

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(val[0] > mat[i][j])
            {
                val[0] = mat[i][j];
            }
            if(val[1] < mat[i][j])
            {
                val[1] = mat[i][j];
            }
            val[2] +=mat[i][j];
            aux++;
        }
    }
    val[2] = val[2]/aux;
    return val;

}
void MoMaMeMe(float *val, int t)
{

    printf("Valor Menor: %.2f\n", val[0]);
    printf("Valor Maior: %.2f\n", val[1]);
    printf("Valor Media: %.2f\n", val[2]);

}
int main()
{
    int **mat;
    int ***c;
    float *val;
    /*c = Cubo(5,10,10);
    mostrarcubo(10,10,5,c);*/
    srand(time(NULL));
    mat = preenchermatriz(3, 3);
    mostrarDados(3, 3, mat);
    val = MaMeMe(3,3,mat);
    MoMaMeMe(val, 3);
}