#include <stdio.h>
#include <math.h>

double min, br = 90, al = 90/7.0, br_sc, al_sc;

int main (void){

	scanf("%lf", &min);

	while (min){

		br_sc = floor(min / br);
		al_sc = ceil(min / al);

		printf("Brasil %0.0lf x Alemanha %0.0lf\n", br_sc, al_sc);

		scanf("%lf", &min);

	}

	return 0;
}
