#include <stdio.h>

int x;

int main (void){

	scanf("%d", &x);

	if (x % 2 == 0)
		printf("%d\n", x + 2);
	else if (x % 2 == 1)
		printf("%d\n", x + 1);

	return 0;
}
