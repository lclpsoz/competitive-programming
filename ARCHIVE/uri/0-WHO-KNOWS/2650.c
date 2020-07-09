#include <stdio.h>
#include <math.h>

int i, j, k, l;
int titans_qnt, wall_h, titans_h[100];
char titans[100][106];

int main (void){

	scanf("%d %d", &titans_qnt, &wall_h);

	for (i = 0; i < titans_qnt; i++)
		scanf(" %[^\n]", titans[i]);

	for (k = 0; k < titans_qnt; k++){

		titans_h[k] = 0;
		for (i = 0; i < 106; i++)
			if (titans[k][i] == '\0'){

				for (j = i - 1, l = 0; j >= 0 && titans[k][j] != ' '; j--, l++)
					titans_h[k] += (titans[k][j] - '0') *(int) pow(10, l);
				titans[k][j] = '\0';
				break;

			}
	}

	/*for (i = 0; i < titans_qnt; i++)
		printf("%d: %d\n", i+1, titans_h[i]);
	printf("\n");*/

	for (i = 0; i < titans_qnt; i++)
		if (titans_h[i] > wall_h)
			printf("%s\n", titans[i]);

	return 0;
}
