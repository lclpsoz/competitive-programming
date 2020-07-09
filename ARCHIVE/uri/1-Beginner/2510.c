#include <stdio.h>
#include <string.h>

int i;
int runs;
char name[26];

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%s", name);

		if (strcmp(name, "Batmain"))
			printf("Y\n");
		else
			printf("N\n");

	}

	return 0;
}
