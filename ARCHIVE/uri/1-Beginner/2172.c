#include <stdio.h>

long long unsigned int x, m;

int main (void){

	scanf("%lld %lld", &x, &m);

	while (x != 0 && m != 0){

		printf("%lld\n", x * m);
		scanf("%lld %lld", &x, &m);

	}

	return 0;
}
