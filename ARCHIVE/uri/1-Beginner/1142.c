#include <stdio.h>

int i;
int qnt;

int main(void){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++)
		printf("%d %d %d PUM\n", (i * 4) + 1, (i * 4) + 2, (i * 4) + 3);

	return 0;
}
