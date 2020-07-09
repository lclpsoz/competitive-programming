#include <stdio.h>

int i;
int x;

int main (void){

	scanf("%d", &x);

	while (x != 0){

		for (i = 1; i < x; i++)
			printf("%d ", i);
		printf("%d\n", i);

		scanf("%d", &x);

	}

	return 0;
}
