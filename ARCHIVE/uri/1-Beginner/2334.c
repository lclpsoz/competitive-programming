#include <stdio.h>

long long unsigned int ducks;

int main (void){

	scanf("%llu", &ducks);

	while (ducks != 18446744073709551615){

		if (ducks == 0)
			printf("0\n");
		else
			printf("%llu\n", ducks - 1);

		scanf("%llu", &ducks);

	}

	return 0;
}
