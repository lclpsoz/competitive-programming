#include <stdio.h>

int i, j;
int val, a, b;
char str[15];

int main (void){

	while (scanf("%s", str) != EOF){

		a = 0;
		b = 0;

		//Only allow numbers
		for (i = 0, j = 0; i < 14; i++)
			if (str[i] != '.' && str[i] != '-')
				str[j++] = str[i];

		//Get the verification values
		for (i = 0; i < 9; i++){

			val = str[i] - '0';
			a += val * (i + 1);
			b += val * (9 - i);

		}

		a %= 11;
		b %= 11;
		if (a == 10)
			a = 0;
		if (b == 10)
			b = 0;

		//Test them
		if (a == (str[9] - '0') && b == (str[10] - '0'))
			printf("CPF valido\n");
		else
			printf("CPF invalido\n");

	}

	return 0;
}
