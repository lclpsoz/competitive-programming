#include <stdio.h>

int i;
int runs, numb;

int main (void){

	scanf("%d", &runs);

	while (runs != 0){

		for (i = 0; i < runs; i ++){

			scanf("%d", &numb);
			if (numb % 2 == 1)
				printf("%d\n", (numb * 2) - 1);
			else
				printf("%d\n", (numb * 2) - 2);

		}

		scanf("%d", &runs);

	}

	return 0;
}
