#include <stdio.h>

int a, b;

int main (void){

	scanf("%d %d", &a, &b);

	if (b < 3)
		printf("nova\n");
	else if (b > 96)
		printf("cheia\n");
	else if (a > b)
		printf("minguante\n");
	else if (b > a)
		printf("crescente\n");

	return 0;
}
