#include <stdio.h>

int i, j;
int numb;

int main (void){

	while (scanf("%d", &numb) != EOF){

		for (i = 0; i < numb; i++)
			for (j = 0; j < numb; j++){

				if (i + j == numb - 1)
					printf("2");
				else if (i == j)
					printf("1");
				else
					printf("3");

				if (j == numb - 1)
					printf("\n");

			}
	}

	return 0;
}
