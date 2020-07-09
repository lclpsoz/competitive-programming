#include <stdio.h>

int i;
int qnt, ent;
double perc, ok;

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &ent);
		if (!ent)
			ok++;

	}

	perc = ok / qnt;

	if (perc > 0.5)
		printf("Y\n");
	else
		printf("N\n");

	return 0;
}
