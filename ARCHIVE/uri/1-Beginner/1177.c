#include <stdio.h>

int i;
int numb, array[1000];

int main (void){

	scanf("%d", &numb);

	for (i = 0; i < 1000; i++){

		array[i] = i % numb;
		printf("N[%d] = %d\n", i, array[i]);
	
	}

	return 0;
}

		
