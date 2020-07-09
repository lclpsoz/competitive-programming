#include <stdio.h>
#include <math.h>

int i, j, k, l;
int qnt, mat_size, mat_max[20], mat_col_size[20][20];
unsigned long long int mat[20][20], aux;

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &mat_size);
		for (j = 0; j < mat_size; j++)
			for (k = 0; k < mat_size; k++){

				scanf("%llu", &mat[j][k]);
				mat[j][k] *= mat[j][k];

				aux = mat[j][k];
				l = 0;
				if (aux == 0) l = 1;
				while (aux > 0){

					aux /= 10;
					l++;

				}
				mat_col_size[j][k] = l;

				if (mat_col_size[j][k] > mat_max[k])
					mat_max[k] = mat_col_size[j][k];

			}

		printf("Quadrado da matriz #%d:\n", i + 4);
		for (j = 0; j < mat_size; j++){

			for (k = 0; k < mat_size; k++){

				for (l = 0; l < mat_max[k] - mat_col_size[j][k]; l++)
					printf(" ");

				printf("%llu", mat[j][k]);
				if (k < mat_size - 1)
					printf(" ");

			}

			printf("\n");
		}

		for (j = 0; j < 20; j++)
			mat_max[j] = 0;

		if (i < qnt-1) printf("\n");

	}

	return 0;
}
