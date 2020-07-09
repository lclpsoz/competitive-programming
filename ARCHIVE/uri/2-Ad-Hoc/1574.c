#include <stdio.h>

int i, j;
int tests, qnt, act, move[100], pos;
char aux[20];

int main (void){

	scanf("%d", &tests);

	for (i = 0; i < tests; i++){

		scanf("%d", &qnt);
		for (j = 0; j < qnt; j++){

			scanf("%s", aux);
			if (aux[0] == 'S'){

				scanf(" AS %d", &act);
				move[j] = move[act - 1];

			}
			else if (aux[0] == 'L')
				move[j] = -1;
			else if (aux[0] == 'R')
				move[j] = 1;

		}

		pos = 0;
		for (j = 0; j < qnt; j++)
			pos += move[j];

		printf("%d\n", pos);

	}

	return 0;
}
