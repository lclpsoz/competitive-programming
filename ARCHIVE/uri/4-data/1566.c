#include <stdio.h>

int i, j;
int qnt_cities, qnt_peop, height, frst;
int heights[250];

int main (){

	scanf("%d", &qnt_cities);
	for (i = 0; i < qnt_cities; i++){

		scanf("%d", &qnt_peop);
		for (j = 0; j < qnt_peop; j++){

			scanf("%d", &height);
			heights[height]++;

		}

		j = 20;
		while (!heights[j]) j++;

		printf("%d", j);
		heights[j]--;

		for (j = frst; j <= 230; j++)
			while (heights[j]){

				printf(" %d", j);
				heights[j]--;

			}

		printf("\n");

	}

	return 0;
}
