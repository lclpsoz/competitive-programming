#include <stdio.h>
#include <math.h>

int i, j;
char ar[11], ar_inv[11];

int main(void){

	int digt;
	long long int userInput, userInputInv = 0;
	scanf("%s", ar);

	for (i = 0; i < 11; i++)
		if (ar[10 - i] != '\0'){

			ar_inv[j] = ar[10 - i];
			j++;

		}

	printf("%s\n", ar_inv);

	return 0;
}
