#include <stdio.h>
#include <string.h>

int i, j, k;
int sets[10000][61], runs, sets_amt, set_size, aux[61];
int opr, set1, set2, ans;
int* pos;

int main (void){

	scanf("%d", &runs);
	for (i = 0; i < runs; i++){

		scanf("%d", &sets_amt);
		for (j = 0; j < sets_amt; j++){

			scanf("%d", &set_size);
			sets[j][0] = set_size;
			for (k = 1; k <= set_size; k++)
				scanf("%d", &sets[j][k]);

		}

		scanf("%d", &sets_amt);
		for (j = 0; j < sets_amt; j++){

			scanf("%d %d %d", &opr, &set1, &set2);

			//Vai adicionar 1 na posição referente ao valor existente no array, dessa forma não precisando comparar os arrays diretamente.
			for (k = 1; k <= sets[set1 - 1][0]; k++){

				pos = &aux[sets[set1 - 1][k]];
				if (*pos == 0)
					*pos = 1;
				else if (*pos == 2)
					*pos = 3;	//Intersercção

			}
			for (k = 1; k <= sets[set2 - 1][0]; k++){

				pos = &aux[sets[set2 - 1][k]];
				if (*pos == 0)
					*pos = 2;
				else if (*pos == 1)
					*pos = 3;	//Intersercção

			}

			//Se o valor na posição for 1, tem em algum dos arrays, se for 2 tem nos dois.
			/*printf("---------\n%d %d %d\n", opr, set1, set2);
			for (k = 1; k <= sets[set1 - 1][0]; k++)
				printf("set1: %d\n", sets[set1 - 1][k]);

			for (k = 1; k <= sets[set2 - 1][0]; k++)
				printf("set2: %d\n", sets[set2 - 1][k]);*/

			for (k = 1; k < 61; k++){

				//printf("%d: %d\n", k, aux[k]);
				if (opr == 1 && aux[k] == 3)
					ans++;
				else if (opr == 2 && aux[k] > 0)
					ans++;

				aux[k] = 0;

			}

			printf("%d\n", ans);
			ans = 0;

		}

	}

	return 0;
}
