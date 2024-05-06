#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    int T, N, i, j;
    int **M;

    scanf("%d", &T);
    if (T < 1 || T > 100)
    {
        exit(EXIT_FAILURE);
    }

    while (--T)
    {
        scanf("%d", &N);
        if (N < 1 || N > 20)
        {
            exit(EXIT_FAILURE);
        }
        /*Allocating rows memory*/
        M = (int *)malloc(N * sizeof(int));
        for (i = 0; i < N; i++)
        {
            /*Allocating columns memory.*/
            M[i] = (int *)malloc(N * sizeof(int *));
            for (j = 0; j < N; j++)
            {
                scanf("%d", &M[i][j]);
            }
        }
    }
    findInverse(M, N);

    /*Freeing the memory allocated*/
    for (i = 0; i < N; i++)
    {
        free(M[i]);
    }
    free(M);
    return (0);
}

/**
 * getCofactor - calculate the cofactor of a matrix
 * @mat: Matrix
 * @temp: Buffer for the matrix
 * @n: size of square matrix
*/
void getCofactor(int **mat, int **temp, int n)
{
    int i = 0, j = 0;
    int row, col;

    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (row != n && col != n)
            {
                temp[i][j++] = mat[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/**
 * determinant - calculate determinant of matrix
 * @mat: Square matrix
 * @n: Size of square matrix
 * Return: returns determinant of a matrix 
*/
float determinant(int **mat, int n)
{
    int f;
    int **temp;
    int sign = 1;
    float D = 0;

    if (n == 1)
    {
        return mat[0][0];
    }

    for (f = 0; f < n; f++)
    {
        getCofactor(mat, temp, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return (D);
}

/**
 * calculateDeterminant - calculates determinat
 * @mat: Matrix
 * @size: size of square matrix
 * Return: determinant of matrix
*/
float calculateDeterminant(int **matrix, int size)
{
    float det = determinant(matrix, size);
    return (det);
}

/**
 * findInverse - Function to calculate the inverse of the square matrix
 * @matrix: The matrix to find inverse
 * @inverse: The inverse of matrix
 * @size: the size of the matrix (N)
 * Return: Nothing
*/
void findInverse(int **matrix, int size)
{
    int i, j;
    float det = calculateDeterminant(matrix, size);
    float **inverse;
    float **adjugate;

    if (det == 0)
    {
        printf("Inverse does not exist.\n");
        return;
    }

    /*Allocate memory for the adjugate matrix*/
    adjugate = (float **)malloc(size * sizeof(float *));
    for (i = 0; i < size; i++)
    {
        adjugate[i] = (float *)malloc(size * sizeof(float));
    }

    /*Calculate the adjugate matrix (you need to implement this function)*/

    /*Compute the inverse by dividing the adjugate by the determinant*/
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            inverse[i][j] = adjugate[i][j] / det;
        }
    }

    /*Print the inverse matrix*/
    printf("Inverse matrix:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%.2f ", inverse[i][j]);
        }
        printf("\n");
    }

    /* Free memory*/
    for (i = 0; i < size; i++)
    {
        free(adjugate[i]);
    }
    free(adjugate);
}