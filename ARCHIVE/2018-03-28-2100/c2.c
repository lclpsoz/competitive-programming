//cos(n*pi)/raiz(n);
//a1 = 1;
//a(n+1) = an + 2/(3^n+1)
#include <stdio.h>
#include <math.h>

const double PI = 3.1415;

int main (void)
{
	double a = 1;
	for (int i = 2; i < 20; i++)
		a += 2/pow (3, i);
	printf ("1.b.\n");
	printf ("%.10lf\n", a);
	printf ("%.10lf\n", 4/3.0);
	printf ("1.b.\n");
	int n;
	for (int i = 1; i < 1e9; i++) {
		a = cos (i*PI) / sqrt(i);
		if (!(i % 1000000))
			printf ("%lf\n", fabs(a));
	}

	return 0;
}
