#include <stdio.h>

int i;
float array[100];

int main (void){

	for (i = 0; i < 100; i++){

		scanf("%f", &array[i]);

		if (array[i] <= 10)
			printf("A[%d] = %.1f\n", i, array[i]);

	}

		return 0;
}
