#include <stdio.h>

int num, res, i, j;
char hexa[6] = {'A', 'B', 'C', 'D', 'E', 'F'}, numb[10],numb_inv[10], aux;

void hex (int n, char* ar){

	if (n < 10){

		ar[i] = n + '0';
		i++;

	}
	else{

		ar[i] = hexa[n - 10];
		i++;

	}
}

int main (void){

	scanf("%d", &num);

	do{

		res = num % 16;
		num = num / 16;

		hex(res, numb);

		if (num > 0 && num < 16)
			hex(num, numb);

	}while (num > 15);

	for (i = 0; i < 10; i++){
		if (numb[9 - i] != '\0'){

			numb_inv[j] = numb[9 - i];
			j++;

		}
	}

	printf("%s\n", numb_inv);

	return 0;
}
