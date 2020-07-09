#include <stdio.h>

int main(){

	int amount, code, qnt, x;
	double value;
	scanf("%d", &amount);

	for(x = 0; x < amount; x++){

		scanf("%d%d", &code, &qnt);
		value += (code - 999.5) * qnt;

	}

	printf("%.02lf\n", value);

	return 0;
}