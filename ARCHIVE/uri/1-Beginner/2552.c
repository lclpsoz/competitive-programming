#include <stdio.h>

int i, j;
int line, col, mat[100][100], res[100][100];

int main (void){

	while (scanf("%d %d", &line, &col) != EOF){

		for (i = 0; i < line; i++)
			for (j = 0; j < col; j++){

				scanf("%d", &mat[i][j]);

				if (mat[i][j] == 1){

					res[i][j] = 9;
					if (i > 0 && res[i - 1][j] != 9)
						res[i - 1][j]++;
					if (j < col - 1 && res[i][j + 1] != 9)
						res[i][j + 1]++;
					if (i < line - 1 && res[i + 1][j] != 9)
						res[i + 1][j]++;
					if (j > 0 && res[i][j - 1] != 9)
						res[i][j - 1]++;

				}
			}

		for (i = 0; i < line; i++){

			for (j = 0; j < col; j++){

				printf("%d", res[i][j]);
				res[i][j] = 0;

			}

			printf("\n");

		}
	}

	return 0;
}

