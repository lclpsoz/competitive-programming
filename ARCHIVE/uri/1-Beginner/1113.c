#include <stdio.h>

int main(){

	int n1, n2;
	scanf("%d %d", &n1, &n2);

	while (n1 != n2){

		if (n1 > n2)
			printf("Decrescente\n");
		else if (n2 > n1)
			printf("Crescente\n");

	scanf("%d %d", &n1, &n2);

	}

	return 0;
}
