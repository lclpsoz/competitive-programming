#include <stdio.h>

double old, new, perc;

int main (void){

	scanf("%lf %lf", &old, &new);

	perc = (new - old) / old;

	printf("%.2lf%%\n", perc * 100);

	return 0;
}
