#include <stdio.h>

int p, p1, p2, r, a;

int main (void){

	scanf("%d %d %d %d %d", &p, &p1, &p2, &r, &a);

	if (r + a == 2)
		printf("Jogador 2 ganha!\n");
	else if (r + a == 1)
		printf("Jogador 1 ganha!\n");
	else if ((p1 + p2) % 2 == p)
		printf("Jogador 2 ganha!\n");
	else
		printf("Jogador 1 ganha!\n");

	return 0;
}
