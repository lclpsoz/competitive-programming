#include <stdio.h>

int i;
int amnt, numb, min = 21, pos;

int main (void){

	scanf("%d", &amnt);

	for (i = 0; i < amnt; i++){

		scanf("%d", &numb);
		if (numb < min){

			min = numb;
			pos = i + 1;

		}

	}

	printf("%d\n", pos);

	return 0;
}
