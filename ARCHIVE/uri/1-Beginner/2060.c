#include <stdio.h>

int i, j;
int runs, nb, mult[4];

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%d", &nb);
		for (j = 0; j < 4; j++)
			if (nb % (j + 2) == 0)
				mult[j]++;

	}

	for (i = 2; i < 6; i++)
		printf("%d Multiplo(s) de %d\n", mult[i - 2], i);

	return 0;
}
