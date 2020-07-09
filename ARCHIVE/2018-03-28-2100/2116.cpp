#include <bits/stdc++.h>

const int MAXP = 1010;

int i, j;
int a, b;
bool not_prime[MAXP];

int main () {
	for (i = 2; i <= MAXP>>1; i++)
		if (!not_prime[i])
			for (j = i*i; j < MAXP; j+=i)
				not_prime[j] = 1;

	/*for (i = 2; i < MAXP; i++)
		if (!not_prime[i])
			printf ("%d\n", i);*/
	scanf ("%d %d", &a, &b);
	while (not_prime[a])
		a--;
	while (not_prime[b])
		b--;

	printf ("%d\n", a*b);

	return 0;
}
