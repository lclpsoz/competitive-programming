#include <stdio.h>

int i;
int train;
double avr, time, dist;

int main (void){

	while (scanf("%d", &train) != EOF){

		for (i = 0; i < train; i++){

			scanf("%lf %lf", &time, &dist);

			if (dist / time > avr){

				printf("%d\n", i + 1);
				avr = dist / time;

			}
		}

		avr = 0;

	}

	return 0;
}





