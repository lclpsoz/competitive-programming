#include <stdio.h>

int i;
int n;

int main (void){

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		if (i == n - 1)
			printf("Ho!\n");
		else
			printf("Ho ");

	return 0;
}
