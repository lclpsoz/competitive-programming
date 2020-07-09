#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4;

int i, j;
int a, b, c, d;
int fatores[150], exps[150];
bool not_prime[MAXN];
vector<int> primes, divs;


int main ()
{
	for (i = 2; i*i < MAXN; i++)
		if (!not_prime[i]) {
			primes.push_back (i);
			for (j = i*i; j < MAXN; j+=i)
				not_prime[j] = true;
		}

	for (; i < MAXN; i++)
		if (!not_prime[i])
			primes.push_back (i);

	scanf ("%d %d %d %d", &a, &b, &c, &d);
	i = j = 0;
	while (c > 1 && i < primes.size()) {
		if (c%primes[i] == 0) {
			printf ("%d %d\n", c, primes[i]);
			c /= primes[i];
			fatores[j] = primes[i];
			exps[j] = 1;
		}
		while (c%primes[i] == 0) {
			c /= primes[i];
			exps[j]++;
		}
		if (fatores[j])
			j++;
		i++;
	}
	if (c>1) {
		fatores[j] = c;
		exps[j] = 1;
	}
	for (i = 0; fatores[i]; i++) {
		printf ("%d^%d", fatores[i], exps[i]);
		if (fatores[i+1])
			printf (" * ");
	}
	putchar ('\n');

	return 0;
}
