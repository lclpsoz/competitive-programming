#include <stdio.h>

int i;
int qnt, a, b, a_sc, b_sc;

int main (void){

	scanf("%d", &qnt);

	while (qnt){

		a_sc = 0;
		b_sc = 0;
		for (i = 0; i < qnt; i++){

			scanf("%d %d", &a, &b);

			if (a > b)
				a_sc++;
			else if (b > a)
				b_sc++;

		}

		printf("%d %d\n", a_sc, b_sc);
		scanf("%d", &qnt);

	}

	return 0;
}
