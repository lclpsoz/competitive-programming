#include <stdio.h>
#include <math.h>

int i;
int qnt, tab, lim, card, alice, bob;

int main (void){

	scanf("%d %d %d", &qnt, &tab, &lim);

	for (i = 0; i < qnt - 1; i++){

		scanf("%d", &card);

		if (fabs(tab - card) <= lim){

			if (i % 2 == 0)
				alice += fabs(tab - card);
			else
				bob += fabs(tab - card);

			tab = card;

		}
	}

	printf("%d %d\n", alice, bob);

	return 0;
}
