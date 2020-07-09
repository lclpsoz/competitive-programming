#include <stdio.h>

int i;
int array[20];

int main (void){

	for (i = 19; i >= 0; i--)
		scanf("%d", &array[i]);

	for (i = 0; i < 20; i++)
		printf("N[%d] = %d\n", i, array[i]);

	return 0;
}
