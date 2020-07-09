#include <stdio.h>

int i;
double qnt, val;

int main (void){

	scanf("%lf", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%lf", &val);

		printf("%0.0lf\n", (val / 2) + 0.1);

	}

	return 0;
}
