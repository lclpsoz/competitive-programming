#include <stdio.h>

int i, j;
int runs, numb, sum;

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%d", &numb);

		for (j = 1; j <= (numb / 2); j++)
			if (numb % j == 0)
				sum += j;

		if (sum == numb)
			printf("%d eh perfeito\n", numb);
		else
			printf("%d nao eh perfeito\n", numb);

		sum = 0;	
	}

	return 0;
}
