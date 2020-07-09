#include <stdio.h>
#include <math.h>

int i;
int qnt;

int main(void){

	scanf("%d", &qnt);

	for (i = 1; i <= qnt; i++)
		printf("%d %.0f %.0f\n", i, pow(i, 2), pow(i, 3));

	return 0;
}
