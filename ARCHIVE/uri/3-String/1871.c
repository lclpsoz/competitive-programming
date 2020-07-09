#include <stdio.h>

int i, j;
int a, b, sum, aux;
char num[11], resp[11];

int main (void){

	scanf("%d %d", &a, &b);

	while (a || b){

		sum = a + b;

		i = 0;
		aux = sum;
		while (aux > 0){

			if (aux % 10)
				num[i++] = (aux % 10) + '0';

			aux /= 10;

		}

		j = 0;
		while (i > 0)
			resp[j++] = num[--i];


		printf("%s\n", resp);

		for (i = 0; i < 11; i++){

			num[i] = '\0';
			resp[i] = '\0';

		}

		scanf("%d %d", &a, &b);

	}

	return 0;
}
