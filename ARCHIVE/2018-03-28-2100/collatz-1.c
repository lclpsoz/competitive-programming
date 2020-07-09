#include <stdio.h>

typedef long long unsigned llu;
const llu MAXV = 1e19;

llu base = 1, val = 1;

int main (void)
{
	while (base <= MAXV) {
		val = base;
		while (val > 1) {
			if (val & 1) {
				val = 3*val + 1;
				val >>= 1;
			}
			else
				val >>= 1;
		}
		printf("%llu\t", base);
		base++;
	}

	return 0;
}
