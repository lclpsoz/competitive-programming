#include <stdio.h>

int i;
int a, n, sum;

int main (void){

	scanf("%d", &a);
	while (!(n > 0))
		scanf("%d", &n);

	for (i = 0; i < n; i++)
		sum += a + i;

	printf("%d\n", sum);

	return 0;
}
