#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double n, p, m;

int main (void){

	scanf("%lf", &n);

	p = (n / log(n));
	m = 1.25506 * ((n / log(n)));

	printf("%.1lf %.1lf\n", p, m);

	return 0;
}
