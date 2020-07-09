#include <stdio.h>

int main(){

	int i;
	int numb, qnt;
	scanf("%d", &numb);
	qnt = 10000 / numb;

	for (i = 0; i <= qnt; i++)
		printf("%d\n", 2 + i * numb);

	return 0;
}
