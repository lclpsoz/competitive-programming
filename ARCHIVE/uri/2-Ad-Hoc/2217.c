#include <stdio.h>

int i;
int qnt, val;

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &val);

		if (val % 2)
			printf("9\n");
		else
			printf("1\n");

	}

	return 0;
}
