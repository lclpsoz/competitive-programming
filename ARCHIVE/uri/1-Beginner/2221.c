#include <stdio.h>

int i;
int runs, dab, gua, att, def, lvl, bon;

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%d", &bon);
		scanf("%d %d %d", &att, &def, &lvl);

		dab = (att + def) / 2;
		if (lvl % 2 == 0)
			dab += bon;

		scanf("%d %d %d", &att, &def, &lvl);

		gua = (att + def) / 2;
		if (lvl % 2 == 0)
			gua += bon;

		if (dab == gua)
			printf("Empate\n");
		else if (dab > gua)
			printf("Dabriel\n");
		else
			printf("Guarte\n");

	}

	return 0;
}


