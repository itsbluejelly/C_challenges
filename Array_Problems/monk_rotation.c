#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int i, j;
	int T, N, K, pos;
	int *A, *A_new;

	scanf("%d", &T);
	if (T >= 1 && T <= 20)
	{
		j = 1;
		while (j <= T)
		{
			scanf("%d %d", &N, &K);
			if (N < 1 || N > 100000 || K < 0 || K > 1000000)
			{
				fprintf(stderr, "Error: Invalid array size (N) or rotation steps (K)\n");	
				break;
			}
			A = (int *)malloc(N * sizeof(int));

			if (A == NULL)
			{
				fprintf(stderr, "Memory allocation failed for array A\n");
				exit(EXIT_FAILURE);
			}

			A_new = (int *)malloc(N * sizeof(int));
			if (A_new == NULL)
			{
				fprintf(stderr, "Memory allocation failed for array A_new\n");
				free(A);
				exit(EXIT_FAILURE);
			}

			/* Taking all inputs for the array A.*/
			for (i = 0; i < N; i++)
			{
				scanf("%d", &A[i]);
				if (A[i] < 0 || A[i] > 1000000)
				{
					fprintf(stderr, "Error: Invalid element in array A\n");
					free(A);
					free(A_new);
					exit(EXIT_FAILURE);
				}
			}

			/*Calculating new positions after rotation.*/
			for (i = 0; i < N; i++)
			{
				pos = (i + K) % N;
				if (pos < 0)
				{
					pos += N;
				}
				A_new[pos] = A[i];
			}

			for (i = 0; i < N; i++)
			{
				printf("%d ", A_new[i]);
			}
			free(A);
			free(A_new);
			j++;
		}
	}
	return (0);
}
