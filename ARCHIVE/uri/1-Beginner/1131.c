#include <stdio.h>

int i, g, inter, gremio, tie, test = 1;

int main(void){

	while(test == 1){

		scanf("%d %d", &i, &g);

		if (i > g)
			inter++;
		else if (g > i)
			gremio++;
		else if (gremio == inter)
			tie++;
	
		printf("Novo grenal (1-sim 2-nao)\n");
		scanf("%d", &test);
	
	}

	printf("%d grenais\n", inter + gremio + tie);
	printf("Inter:%d\n", inter);
	printf("Gremio:%d\n", gremio);
	printf("Empates:%d\n", tie);
	if (inter > gremio)
		printf("Inter venceu mais\n");
	else if (gremio > inter)
		printf("Gremio venceu mais\n");
	else if (gremio == inter)
		printf("Nao houve vencedor\n");

	return 0;
} 
