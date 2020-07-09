#include <stdio.h>

int i;
double qnt, a, b;
int area;

int main (void){

	scanf("%lf", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%lf %lf", &a, &b);

		area = (a * b) / 2;
		printf("%d cm2\n", area);

	}

	return 0;
}
