#include <stdio.h>
#include <math.h>

int i, j;
int n, mid;

int main (void){

	while (scanf("%d", &n) != EOF){

		mid = n / 2;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++){

				if (j == i)
					printf("2");
				else if (j + i == n - 1)
					printf("3");
				else if ())
					printf("0");


				if (j == n - 1)
					printf("\n");

			}

	}

	return 0;
}
