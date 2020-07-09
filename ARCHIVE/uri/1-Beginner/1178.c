#include <stdio.h>

int i;
double array[100];

int main (void){

	scanf("%lf", &array[0]);
	printf("N[0] = %.4lf\n", array[0]);

	for (i = 1; i < 100; i++){

		array[i] = (array[i - 1] / 2);
		printf("N[%d] = %.4lf\n", i, array[i]);

	}

	return 0;
}
