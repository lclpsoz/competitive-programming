#include <stdio.h>

int i, j;
int qnt, qnt_letters, wrong;
char letter;

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &qnt_letters);

		wrong = 0;
		for (j = 0; j < qnt_letters; j++){

			scanf(" %c", &letter);

			if ((letter - 'A') != j)
				wrong++;

		}

		if (wrong <= 2)
			printf("There are the chance.\n");
		else
			printf("There aren't the chance.\n");

	}

	return 0;
}
