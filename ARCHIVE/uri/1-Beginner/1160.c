#include <stdio.h>
#include <math.h>

int i, j;
int pop_a, pop_b, runs;
double gro_a, gro_b;

int main (void){

	scanf("%d", &runs);

	for (i = 0, j = 0; i < runs; i++){

		scanf("%d %d %lf %lf", &pop_a, &pop_b, &gro_a, &gro_b);
		gro_a = (gro_a/100) + 1;
		gro_b = (gro_b/100) + 1;

		do{
			
			pop_a = pop_a * gro_a;
			pop_b = pop_b * gro_b;

			j++;

		}while (pop_a <= pop_b && j < 101);

		if (j == 101)
			printf("Mais de 1 seculo.\n");
		else
			printf("%d anos.\n", j);

		j = 0;
	}

	return 0;
}
