#include <stdio.h>
#include <math.h>

int i, j;
int size, qnt;
long long unsigned int sum;

int main (void){

	scanf("%d", &qnt);

	for (j = 0; j < qnt; j++){

		scanf("%d", &size);

		sum = 0;
		for (i = 0; i < size - 2; i++)
			sum += pow(2, i);

		sum /= 3000;

		printf("%llu kg\n", sum);

	}

	return 0;
}
