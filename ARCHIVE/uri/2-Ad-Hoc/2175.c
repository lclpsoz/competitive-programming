#include <stdio.h>

int i, pos;
double val, min;

int main (void){

	min = 200;
	for (i = 0; i < 3; i++){

		scanf("%lf", &val);

		if (val < min){

			min = val;
			pos = i;

		}
		else if (i > 0 && val == min)
			pos = -1;

	}

	if (pos == -1)
		printf("Empate\n");
	else if (pos == 0)
		printf("Otavio\n");
	else if (pos == 1)
		printf("Bruno\n");
	else if (pos == 2)
		printf("Ian\n");

	return 0;
}
