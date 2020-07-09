#include <stdio.h>

int n;

int main (void){

	while (scanf("%d", &n) != EOF)
		printf("%d\n", n - 1);

	return 0;
}
