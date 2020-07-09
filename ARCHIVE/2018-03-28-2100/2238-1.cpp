#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4;

int i, j;
int a, b, c, d;
int fatores[150], exps[150], aux[150];
bool not_prime[MAXN];
vector<int> primes;
set<int> divs;

bool expo ()
{
	int k = 0;
	aux[k]++;
	while (aux[k] > exps[k] && exps[k]) {
		aux[k] = 0;
		k++;
		aux[k]++;
	}

	return exps[k];
}

int pot (int a, int b)
{
	int r = 1;
	for (int k = 0; k < b; k++)
		r *= a;
	return r;
}

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
			//printf ("%d %d\n", c, primes[i]);
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
	/* for (i = 0; fatores[i]; i++) {
		printf ("%d^%d", fatores[i], exps[i]);
		if (fatores[i+1])
			printf (" * ");
	}
	putchar ('\n');*/

	int l = 1;
	int x;
	while (1) {
		x = 1;
		for (l = 0; exps[l]; l++)
			x *= pot (fatores[l], aux[l]);
		divs.insert (x);
		/*printf ("%d: ", l++);
		for (int k = 0; exps[k]; k++)
			printf ("%d ", aux[k]);
		putchar ('\n');*/
		if (!expo())
			break;
	}
	/*for (int a : divs)
		printf ("%d ", a);
	putchar ('\n');*/

	for (int z : divs) {
		if (z % a != 0)
			divs.erase(z);
		if (z % b == 0)
			divs.erase (z);
		if (d % z == 0)
			divs.erase(z);
	}
	if (divs.empty ())
		printf ("-1\n");
	else
		for (int a : divs) {
			printf ("%d\n", a);
			break;
		}

	return 0;
}
