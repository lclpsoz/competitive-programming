#include <stdio.h>

int i;
int val;

int main (void){

	int fact = 1;
	scanf("%d", &val);

	for (i = 1; i <= val; i++)
		fact *= i;

	printf("%d\n", fact);

	return 0;
}
