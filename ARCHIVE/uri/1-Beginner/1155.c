#include <stdio.h>

double i;
double s;

int main (void){

	for (i = 1; i <= 100; i++)
		s += 1 / i;

	printf("%.2lf\n", s);

	return 0;

}
