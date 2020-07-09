#include <stdio.h>

int i;
int qnt, seq[46];

int main (void){

	scanf("%d", &qnt);
	seq[0] = 0;
	seq[1] = 1;
	
	for(i = 0; i < (qnt - 1); i++){

		seq[i + 2] = seq[i] + seq[i + 1];
		printf("%d ", seq[i]);

	}

	printf("%d\n", seq[i]);

	return 0;
}
