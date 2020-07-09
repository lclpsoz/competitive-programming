#include <stdio.h>

int seq (int numb){

	if (numb == 0)
		return 1;
	else
		return numb + seq(numb - 1);

}

int i = 1, j, k = 1;
int ar[20101], nb, amnt;

int main (void){

	while (i < 20101){

		for (j = i; j < (i + k) && j < 20101; j++)
			ar[j] = k;
		k++;
		i = j;

	}

	/*for (i = 0; i < 20101; i++)
		printf("%d ", ar[i]);
	printf("\n");

	printf("%d", seq(200));*/

	j = 1;
	while (scanf("%d", &nb) != EOF){

		amnt = seq(nb);
		if (nb == 0)
			printf("Caso %d: 1 numero\n", j);
		else
			printf("Caso %d: %d numeros\n", j, amnt);

		for (i = 0; i < amnt; i++){

			printf("%d", ar[i]);
			if (i != amnt - 1)
				printf(" ");
			else
				printf("\n\n");

		}

		j++;
	}

	return 0;
}
