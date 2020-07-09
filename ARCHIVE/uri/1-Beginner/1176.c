#include <stdio.h>

int runs, numb;
unsigned long long int fib[61];

int main (void){

	int i;

	scanf("%d", &runs);

	fib[0] = 0;
	fib[1] = 1;

	for (i = 2; i < 61; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	for (i = 0; i < runs; i++){

		scanf("%d", &numb);
		printf("Fib(%d) = %lld\n", numb, fib[numb]);

	}

	return 0;
}
