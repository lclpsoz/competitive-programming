#include <stdio.h>

int i, j;
int runs, numb, prime = 1;

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%d", &numb);

		for(j = 2; (j <= (numb / 2)) && (prime == 1); j++)
			if (numb % j == 0)
				prime = 0;

		if (prime == 1)
			printf("%d eh primo\n", numb);
		else
			printf("%d nao eh primo\n", numb);

		prime = 1;

	}

	return 0;
}
