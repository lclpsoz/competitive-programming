#include <stdio.h>

int var1, var2;

int main (void){

	scanf("%d %d", &var1, &var2);

	if (var1 && var2)
		printf("A\n");
	else if (var1)
		printf("B\n");
	else
		printf("C\n");

	return 0;
}
