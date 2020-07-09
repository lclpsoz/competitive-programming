#include <stdio.h>
#include <string.h>
int i;
int val, epr, ehd, others, qnt;
char str[1000];

int main (void){

	while (scanf("%d", &qnt) != EOF){

		epr = ehd = others = 0;

		for (i = 0; i < qnt; i++){

			scanf("%d %s", &val, str);

			if (!strcmp("EPR", str))
				epr++;
			else if (!strcmp("EHD", str))
				ehd++;
			else
				others++;

		}

		printf("EPR: %d\n", epr);
		printf("EHD: %d\n", ehd);
		printf("INTRUSOS: %d\n", others);

	}

	return 0;
}
