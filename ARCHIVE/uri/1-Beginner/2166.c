#include <stdio.h>

int i;
double n, den;

int main (void){

	scanf("%lf", &n);

	for (i = 0; i < n; i++)
		den = 1 / (2 + den);

	printf("%.10lf\n", den + 1);

	return 0;
}
