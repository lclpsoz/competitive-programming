#include <stdio.h>

int i, j;
int qnt, qnt_exp, arr[1001], sum;

int main (void){

	while (scanf("%d %d", &qnt, &qnt_exp) != EOF){

		for (i = 0; i < qnt; i++)
			scanf("%d", &arr[i]);

		sum = 0;
		for (i = 1; i <= qnt_exp; i++)
			sum += arr[qnt - i];

		printf("%d\n", sum);

		for (i = 0; i < qnt; i++)
			arr[i] = 0;

	}

	return 0;
}
