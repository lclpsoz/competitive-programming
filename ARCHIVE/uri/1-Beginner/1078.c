#include <stdio.h>

int main(){

	int i;
	int numb;
	scanf("%d", &numb);

	for (i = 1; i <= 10; i++)
		printf("%d x %d = %d\n", i, numb, i * numb);

	return 0;
}
