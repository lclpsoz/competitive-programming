#include <stdio.h>

int a, b, q, r;

int main (void){

	scanf("%d %d", &a, &b);

	q = a / b;
	r = a - (b * q);

	if (r < 0){

		q -= 1;
		r = a - (b * q);

		if (r < 0){

			q += 2;
			r = a - (b * q);

		}
	}

	printf("%d %d\n", q, r);

	return 0;
}
