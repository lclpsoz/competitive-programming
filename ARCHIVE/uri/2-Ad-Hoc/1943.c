#include <stdio.h>

int num;

int main (void){

	scanf("%d", &num);

	if (num == 1)
		printf("Top 1\n");
	else if (num <= 3)
		printf("Top 3\n");
	else if (num <= 5)
		printf("Top 5\n");
	else if (num <= 10)
		printf("Top 10\n");
	else if (num <= 25)
		printf("Top 25\n");
	else if (num <= 50)
		printf("Top 50\n");
	else
		printf("Top 100\n");

	return 0;
}
