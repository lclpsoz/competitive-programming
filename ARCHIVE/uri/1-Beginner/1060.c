#include <stdio.h>

int main(){

	int i, amount;
	double table[6];
	for (i = 0; i < 6; ++i){
		
		scanf("%lf", &table[i]);
		if (table[i] > 0){

			amount++;

		}
	}

	printf("%d valores positivos\n", amount);

	return 0;
}