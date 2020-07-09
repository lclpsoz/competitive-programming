#include <stdio.h>

int i;
int runs;
long long unsigned int r1, r2;

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%lld %lld", &r1, &r2);
		printf("%lld\n", r1 + r2);

	}

	return 0;
}
