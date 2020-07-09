#include <stdio.h>
#include <math.h>

int i;
int amnt, numb, sum, aux;

int main (void){

	while (scanf("%d %d", &amnt, &numb) != EOF){

		for (i = amnt - 1; i >= 0; i--){

			aux = numb / pow(10,i);
			sum += aux;
			numb -= aux * pow(10, i);

		}

		if (sum % 3 == 0)
			printf("%d sim\n", sum);
		else
			printf("%d nao\n", sum);

		sum = 0;

	}

	return 0;
}
