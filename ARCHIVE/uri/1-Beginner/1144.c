#include <stdio.h>
#include <math.h>

int i;
int qnt;

int main (void){

	scanf("%d", &qnt);
	for (i = 1; i <= qnt; i++)
		printf("%d %0.f %0.f\n%d %0.f %0.f\n", i, pow(i, 2), pow(i, 3), i, pow(i, 2) + 1, pow(i, 3) + 1);

	return 0;
}
