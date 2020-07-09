#include <stdio.h>

int main(){

	int i, j;

	for (i = 1; i < 10; i += 2)
		for (j = 6; j > 3; j--)
			printf("I=%d J=%d\n", i, j + i);
	
	return 0;
}
