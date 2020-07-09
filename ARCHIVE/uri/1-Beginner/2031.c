#include <stdio.h>

char pl_1[6], pl_2[6];
int amnt;

int main (void){

	int i;
	scanf("%d", &amnt);

	for (i = 0; i < amnt; i++){
		scanf("%s %s", pl_1, pl_2);

		if (pl_1[1] == pl_2[1]){

			if (pl_1[1] == 't')
				printf("Aniquilacao mutua\n");
			else if (pl_1[1] == 'e')
				printf("Sem ganhador\n");
			else if(pl_1[1] == 'a')
				printf("Ambos venceram\n");

		}
		else if (pl_1[1] == 't')
			printf("Jogador 1 venceu\n");
		else if (pl_2[1] == 't')
			printf("Jogador 2 venceu\n");
		else if (pl_1[1] == 'e')
			printf("Jogador 1 venceu\n");
		else if (pl_2[1] == 'e')
			printf("Jogador 2 venceu\n");

	}

	return 0;
}
