#include <stdio.h>

int left, right;

int main (void){

	scanf("%d %d", &left, &right);

	while (left){

		printf("%d\n", left + right);
		scanf("%d %d", &left, &right);

	}

	return 0;
}
