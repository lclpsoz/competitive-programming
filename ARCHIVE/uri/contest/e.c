#include <stdio.h>

long long int bef, now, print;

int main (void){

	print = 1;
	while (scanf("%lld", &now) != EOF){

		if (print && bef && now < bef){

			printf("%lld\n", bef + 1);
			print = 0;

		}

		bef = now;

	}
	if (print){

		printf("%lld\n", bef + 1);
		print = 0;

	}

	return 0;
}
