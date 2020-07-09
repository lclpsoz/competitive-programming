#include <stdio.h>

int i, j, k;
int qnt, x, y, sum;

int main(void){
	
	scanf("%d", &qnt);
	
	for (i = 0; i < qnt; i++){

		scanf("%d %d", &x, &y);

		k = 0;
		for (j = x;(k < y); j ++){

			if (j % 2 == 1 || j % 2 == -1){
				sum += j;
				k++;
			}
		}
		printf("%d\n", sum);
		sum = 0;

	}

	return 0;
}
