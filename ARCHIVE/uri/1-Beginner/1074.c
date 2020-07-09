#include <stdio.h>

int main(){

	int i;
	int qnt, numb;
	scanf("%d", &qnt);
	int values[qnt];

	for (i = 0; i < qnt; i++){

		scanf("%d", &numb);
		values[i] = numb;

	}

	for (i = 0; i < qnt; i++){

		if (values[i] == 0)
			printf("NULL\n");
		else if (values[i] % 2 == 0)
			printf("EVEN ");
		else
			printf("ODD ");

		if (values[i] > 0)
			printf("POSITIVE\n");
		else if (values[i] < 0)
			printf("NEGATIVE\n");

	}

	return 0;
}
