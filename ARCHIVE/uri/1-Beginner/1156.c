#include <stdio.h>

int i;
double div = 1, S;

int main(){

	for (i = 1; i < 40; i+=2){

		S += i/div;
		div *= 2;
 
	}

	printf("%.2lf\n", S);

	return 0;
}
