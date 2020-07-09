#include <stdio.h>

int main(){
	
	double A, B, C, pi, tri, circle, trap, square, rect;

	scanf("%lf%lf%lf", &A, &B, &C);
	pi = 3.14159;

	tri = (A * C) / 2;
	circle = pi * C * C;
	trap = ((A + B) * C)/2;
	square = B * B;
	rect = A * B;

	printf("TRIANGULO: %.3lf\n", tri);
	printf("CIRCULO: %.3lf\n", circle);
	printf("TRAPEZIO: %.3lf\n", trap);
	printf("QUADRADO: %.3lf\n", square);
	printf("RETANGULO: %.3lf\n", rect);

	return 0;

}