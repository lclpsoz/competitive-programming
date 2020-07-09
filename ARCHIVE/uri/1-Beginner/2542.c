#include <stdio.h>

int i, j;
int qnt_atri, qnt_marc, qnt_leo, card_marc, card_leo, choosen;
int marc[100][100], leo[100][100];

int main (void){

	while (scanf("%d", &qnt_atri) != EOF){

		scanf("%d %d", &qnt_marc, &qnt_leo);

		for (i = 0; i < qnt_marc; i++)
			for (j = 0; j < qnt_atri; j++)
				scanf("%d", &marc[i][j]);

		for (i = 0; i < qnt_leo; i++)
			for (j = 0; j < qnt_atri; j++)
				scanf("%d", &leo[i][j]);

		scanf("%d %d", &card_marc, &card_leo);
		scanf("%d", &choosen);

		if (marc[card_marc - 1][choosen - 1] > leo[card_leo - 1][choosen - 1])
			printf("Marcos\n");
		else if (marc[card_marc - 1][choosen - 1] < leo[card_leo - 1][choosen - 1])
			printf("Leonardo\n");
		else
			printf("Empate\n");

	}

	return 0;
}
