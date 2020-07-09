#include <stdio.h>

int main(){

	float i, j;

	for (i = 0; i < 2.1; i += 0.2)
		for (j = 1; j < 4; j++){
			
			if ((int)(i*10 - (int) i*10) != 0)
				printf("I=%0.1f J=%0.1f\n", i, j + i);
			else
				printf("I=%0.0f J=%0.0f\n", i, j + i);
				
		}

	return 0;
}
