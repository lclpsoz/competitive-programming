#include <stdio.h>

int i, j;
int runs, sum, tabl[101][101];

int main (void){

	scanf("%d", &runs);

	for (i = 0; i <= runs; i++)
		for (j = 0; j  <= runs; j++)
			scanf("%d", &tabl[i][j]);

	for (i = 0; i < runs; i++){

		for (j = 0; j  < runs; j++){

			sum = tabl[i][j] + tabl[i + 1][j] + tabl[i][j + 1] + tabl[i + 1][j + 1];

			if (sum > 1)
				printf("S");
			else
				printf("U");

		}

		printf("\n");

	}

	return 0;
}
