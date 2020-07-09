#include <stdio.h>

int i, j;
int qnt, x;
float a, a2;
double b, b2;
long double c, c2;

int main (){

	printf("%lu %lu %lu\n", sizeof(a), sizeof(b), sizeof(c));

	scanf("%d %d", &qnt, &x);
	for (i = 0; i < qnt; i++){

		scanf("%Le", &c);
		a2 = a = c;
		b2 = b = c;
		c2 = c;
		for (j = 0; j < (x-1); j++){

			printf("%f\n", a2);
			a2 *= a;

		}
		printf("%.20f\n\n", a2);
		for (j = 0; j < (x-1); j++){

			printf("%lf\n", b2);
			b2 *= b;

		}
		printf("%.20lf\n\n", b2);
		for (j = 0; j < (x-1); j++){

			printf("%Le\n", c2);
			c2 *= c;

		}
		printf("%.20Le\n\n", c2);

	}

	return 0;
}
