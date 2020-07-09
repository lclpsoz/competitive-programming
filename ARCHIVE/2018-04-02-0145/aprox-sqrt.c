#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double aprox (double n)
{
	int st, en;
	st = 1;
	en = 1e4;
	int i = (st+en)/2;
	while (i*i != n && st < en) {
		if (i*i < n) {
			st = i+1;
			i = (st+en)/2;
		}
		else {
			en = i-1;
			i = (st+en)/2;
		}
		//printf ("%d %d\n", st, en);
	}
	if (abs((i-1)*(i-1)-n) < abs((i*i)-n))
		i--;
	return i;
}

int main (void)
{
	double x;
	printf ("Valor para ser aproximada a raiz (min 1, max 1e8): ");
	scanf ("%lf", &x);
	double n = aprox (x);
	double dif;
	printf ("Aproximacao 0: %lf\n", n);
	for (int i = 1; i <= 5; i++) {
		dif = x-(n*n);
		//printf ("dif: %lf\n", dif);
		n += (dif/2.0)/n;
		printf ("Aproximacao %d: %.20lf\t[%.20lf]\n", i, n, x-(n*n));
	}

	printf ("%lf %lf\n", 1e3, 10e3);
}
