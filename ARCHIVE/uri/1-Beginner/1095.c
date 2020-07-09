#include <stdio.h>

int main(){

	int i = -2, j = 65;

	while (j > 0){
	
		i += 3;
		j -= 5;

		printf("I=%d J=%d\n", i, j);
	
	}

	return 0;
}
