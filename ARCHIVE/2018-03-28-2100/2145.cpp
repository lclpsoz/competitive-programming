#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4;

int fatores[150], exps[150];
bool not_prime[MAXN];
vector<int> primes, divs;
int aux[40];

int pot (int a, int b)
{
	int r = 1;
	for (int k = 0; k < b; k++)
		r *= a;
	return r;
}

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

int di () {
	for (int i = 0; i < 30; i++)
		aux[i] = 0;
	int l = 1;
	int x;
	int r = 0;
	while (1) {
		x = 1;
		for (l = 0; exps[l]; l++)
			x *= pot (fatores[l], aux[l]);
		r += x;
		/*printf ("%d: ", l++);
		for (int k = 0; exps[k]; k++)
			printf ("%d ", aux[k]);
		putchar ('\n');*/
		if (!expo())
			break;
	}

	return r;
}

int sum_divs (int c) {
	int i, j;
	int x = c;
	for (i = 0; i < 30; i++)
		fatores[i] = exps[i] = 0;
	i = j = 0;
	while (c > 1 && i < primes.size()) {
		if (c%primes[i] == 0) {
			// printf ("%d %d\n", c, primes[i]);
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
	if (c > 1) {
		fatores[j] = c;
		exps[j++] = 1;
	}
	fatores[j] = exps[j] = 0;
	/*printf ("%d: ", x);
	for (i = 0; fatores[i]; i++) {
		printf ("%d^%d", fatores[i], exps[i]);
		if (fatores[i+1])
			printf (" * ");
	}
	putchar ('\n');*/
	return di();
}

int main ()
{
	int i = 0, j = 0;
	int a, b, d_a, d_b;
	for (i = 2; i*i < MAXN; i++)
		if (!not_prime[i]) {
			primes.push_back (i);
			for (j = i*i; j < MAXN; j+=i)
				not_prime[j] = true;
		}

	for (; i < MAXN; i++)
		if (!not_prime[i])
			primes.push_back (i);

	while (scanf ("%d %d", &a, &b), a || b) {
		d_a = sum_divs (a)-a;
		d_b = sum_divs (b)-b;
		// printf ("%d %d\n", a, b);
		// printf ("%d %d\n", d_a, d_b);
		if (a%d_b == 0 && b%d_a == 0)
			printf ("Friends and lovers <3\n");
		else if (d_a == d_b)
			printf ("Almost lovers!\n");
		else if (a%d_b == 0 && b%d_a != 0)
			printf ("%d friendzoned %d!\n", a, b);
		else if (a%d_b != 0 && b%d_a == 0)
			printf ("%d friendzoned %d!\n", b, a);
		else
			printf ("No connection.\n");
	}

	return 0;
}
