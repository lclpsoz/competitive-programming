#include <stdio.h>

int i;
int qnt, mary, john, coin;

int main (void){

	scanf("%d", &qnt);

	while (qnt){

		john = 0;
		mary = 0;
		for (i = 0; i < qnt; i++){

			scanf("%d", &coin);

			if (coin)
				john++;
			else
				mary++;

		}

		printf("Mary won %d times and John won %d times\n", mary, john);

		scanf("%d", &qnt);
	}

	return 0;
}
