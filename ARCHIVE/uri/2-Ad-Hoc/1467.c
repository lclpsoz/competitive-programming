#include <stdio.h>

int i;
int val[3], sum;
char players[3] = {'A', 'B', 'C'};

int main (void){

	while (scanf("%d %d %d", &val[0], &val[1], &val[2]) != EOF){

		sum = 0;
		for (i = 0; i < 3; i++)
			sum += val[i];

		if (sum == 2){

			for (i = 0; i < 3; i++)
				if (val[i] == 0)
					printf("%c\n", players[i]);

		}
		else if (sum == 1){

			for (i = 0; i < 3; i++)
				if (val[i] == 1)
					printf("%c\n", players[i]);

		}
		else
			printf("*\n");

	}

	return 0;
}
