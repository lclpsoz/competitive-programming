#include <stdio.h>

int a, b, c, aux;

int main (void){

	scanf("%d %d %d", &a, &b, &c);

	if (a >= b + c || b >= a + c || c >= a + b){

		printf("Invalido\n");
		return 0;

	}

	if (a == b && b == c)
		printf("Valido-Equilatero\n");
	else if (a == b || a == c || b == c)
		printf("Valido-Isoceles\n");
	else
		printf("Valido-Escaleno\n");

	if (a > b){

		aux = a;
		a = b;
		b = aux;

	}
	if (b > c){

		aux = b;
		b = c;
		c = aux;

	}
	if (a > c){

		aux = a;
		a = c;
		c = aux;

	}

	if ((a * a) + (b * b) == (c * c))
		printf("Retangulo: S\n");
	else
		printf("Retangulo: N\n");

	return 0;
}
