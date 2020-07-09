#include <stdio.h>
#include <math.h>

int i, j, k;
int numb, tab, pw;

int count (int n){

	int x = 0;
	while (n > 0){

		n /= 10;
		x++;

	}
	
	return x;
}

int main (void){

	scanf("%d", &numb);
	pw = pow(2, (numb - 1) * 2);
	tab = count(pw);
	while (numb > 0){

		for (i = 0; i < numb; i++)
			for (j = 0; j < numb; j++){
				
				pw = pow(2, i + j);
				for (k = 1; k < (tab - count(pw) + 1); k++)
					printf(" ");

				printf("%d", pw);

				if (j == numb - 1 && i == numb - 1)
					printf("\n\n");
				else if (j < numb - 1)
					printf(" ");
				else
					printf("\n");

			}

		scanf("%d", &numb);
		pw = pow(2, (numb - 1) * 2);
		tab = count(pw);

	}

	return 0;

}