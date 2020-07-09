#include <stdio.h>

int i, j, k;
int ar[4], sum;
int test;

int main (void){

	for (i = 0; i < 4; i++)
		scanf("%d", &ar[i]);

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				if (i != j && k != i && k != j)
					if (ar[i] + ar[j] > ar[k] && ar[i] + ar[k] > ar[j] && ar[k] + ar[j] > ar[i])
						test = 1;

	if (test)
		printf("S\n");
	else
		printf("N\n");

	return 0;
}
