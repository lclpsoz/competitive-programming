#include <stdio.h>

int i;
int x, y;

int main (void){

	scanf("%d %d", &x, &y);

	for (i = 1; i < y; i++)
		if (i % x == 0)
			printf("%d\n", i);
		else
			printf("%d ", i);
	printf("%d\n", i);

	return 0;
}
