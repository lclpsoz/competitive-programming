#include <stdio.h>

int main(){

	int i;
	int qnt, x, y;
	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d %d", &x, &y);

		if (y == 0)
			printf("divisao impossivel\n");
		else
			printf("%0.1f\n", (float) x / (float) y);

	}

	return 0;
}
