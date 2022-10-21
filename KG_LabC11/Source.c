
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	double** mat;
	int n, i, j, e;
	clock_t firstTime, secondTime;
	FILE* fp;
	char name[] = "laba_1.txt";
	if ((fp = fopen(name, "a")) == NULL)
	{
		printf("Failed to open file!");
		return 0;
	}

	for (n = 10; n < 2000; n += 50)
	{
		mat = (double**)malloc(n * sizeof(double*));
		for (i = 0; i < n; i++)
		{
			mat[i] = (double*)malloc(n * sizeof(double));
		}
		if (!mat) {
			printf("\nMemory is not allocated!\n");
			exit(1);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				mat[i][j] = (float)(rand() % 50 + 1);
			}
		}
		firstTime = clock();
		for (e = 0; e < n; e++)
		{
			for (i = e + 1; i < n; i++)
			{
				double k = mat[i][e] / mat[e][e];

				for (j = e; j < n; j++)
				{
					mat[i][j] = mat[i][j] - mat[e][j] * k;

				}
			}
		}
		float opr = 1;
		for (i = 0; i < n; i++)
			opr *= mat[i][i];
		secondTime = clock();
		fprintf(fp, "%d %f\n", n,
			(secondTime - firstTime) * 1.0 / CLOCKS_PER_SEC);
		for (i = 0; i < n; i++)
		{
			free(mat[i]);
		}

		free(mat);
	}
	fclose(fp);

	return 0;
}
