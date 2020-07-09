#include <stdio.h>

double dist, sum, qnt;
char str[10000];

int main (void){

	while (scanf(" %[^\n]", str) != EOF){

		scanf("%lf", &dist);
		sum += dist;
		qnt++;

	}

	printf("%.1lf\n", sum / qnt);

	return 0;
}
