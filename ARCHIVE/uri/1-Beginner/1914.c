#include <stdio.h>

int runs;
long long int p1_n, p2_n, sum;
char p1[150], p2[150], p1_c[5], p2_c[5];

int main (void){

	int i;

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%s %s %s %s", p1, p1_c, p2, p2_c);
		scanf("%lld %lld", &p1_n, &p2_n);

		sum = p1_n + p2_n;
		sum %= 2;

		if ((!sum && p1_c[0] == 'P') || (sum && p1_c[0] == 'I'))
			printf("%s\n", p1);
		else
			printf("%s\n", p2);

	}

	return 0;
}
