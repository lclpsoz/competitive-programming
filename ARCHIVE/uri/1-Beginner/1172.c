#include <stdio.h>

int i;
int numb, array[10];

int main (void){

	for (i = 0; i < 10; i++){

		scanf("%d", &numb);
		if (numb > 0)
			array[i] = numb;
		else
			array[i] = 1;

	}

	for (i = 0; i < 10; i++)
		printf("X[%d] = %d\n", i,array[i]);

	return 0;
}
