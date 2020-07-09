#include <stdio.h>

int i;
int runs, h, m, o;

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%d %d %d", &h, &m, &o);

		printf("%02d:%02d - ", h, m);
		if (o == 1)
			printf("A porta abriu!\n");
		else
			printf("A porta fechou!\n");

	}

	return 0;
}
