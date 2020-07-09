#include <stdio.h>

int i;
int amnt, numb;

int main (void){

	scanf("%d", &amnt);

	for (i = 0; i < amnt; i++){

		scanf("%d", &numb);

		if (numb % 2 == 0)
			printf("0\n");
		else
			printf("1\n");

	}

	return 0;
}
