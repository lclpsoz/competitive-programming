#include <stdio.h>
#include <math.h>

int i, j;
int num, aux;
char rm[3][3] = {{'C', 'D', 'M'}, {'X', 'L', 'C'}, {'I', 'V', 'X'}};

int main (void){

	scanf("%d", &num);
	aux = num;

	if (num > 99)
		i = 0;
	else if (num > 9)
		i = 1;
	else
		i = 2;

	for (i = i; i < 3; i++){

		aux = num / pow(10, 2 - i);
		aux %= 10;

		if (aux == 9){

			printf("%c%c", rm[i][0], rm[i][2]);
			aux -= 9;

		}
		else if (aux == 4){

			printf("%c%c", rm[i][0], rm[i][1]);
			aux -= 4;

		}
		else if (aux >= 5){

			printf("%c", rm[i][1]);
			aux -= 5;

		}
		for (j = 0; j < aux; j++)
			printf("%c", rm[i][0]);

	}

	printf("\n");

	return 0;
}
