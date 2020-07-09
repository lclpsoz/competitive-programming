#include <stdio.h>

int i;
int sum, num;

int main (void){

	for (i = 0; i < 4; i++){

		scanf("%d", &num);
		sum += num;

	}

	printf("%d\n", sum - 3);

	return 0;
}
