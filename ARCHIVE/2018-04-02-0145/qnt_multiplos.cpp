#include <bits/stdc++.h>
using namespace std;

const int MAXN = 46350;

int mdc(int a, int b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}
int mmc (int a, int b) { return (a*b) / mdc(a, b); }

bool not_prime[MAXN];
vector<int> primes;
int factors[15];

int qnt_mult (int x)
{
	int maxi = 0;
	while (factors[maxi]) maxi++;
	maxi = 1 << maxi; // not included!!!
	int p = 1;
	int m;
	int r = 0;
	while (p < maxi) {
		m = 1;
		for (int i = 0; factors[i]; i++)
			if (p & 1<<i)
				m = mmc (factors[i], m);
		if (__builtin_popcount(p) & 1)
			r += x/m;
		else
			r-= x/m;
		p++;
	}

	return r;
}

int main ()
{
	int i;
	for (i = 2; i*i < MAXN; i++)
		if (!not_prime[i]) {
			primes.push_back (i);
			for (int j = i*i; j < MAXN; j+=i)
				not_prime[j] = true;
		}

	for (; i < MAXN; i++)
		if (!not_prime[i])
			primes.push_back (i);

	int n, aux, n1;
	while (scanf ("%d", &n) != EOF) {
		n1 = n;
		int j = 0;
		for (int i = 0; n > 1 && i < primes.size (); i++) {
			aux = 0;
			factors[j] = 0;
			while (n%primes[i] == 0) {
				n /= primes[i];
				aux++;
				factors[j] = primes[i];
			}
			if (factors[j])
				j++;
		}
		if (n > 1)
			factors[j++] = n;
		factors[j] = 0;

		/*printf ("FACTORS OF %d:\n", n1);
		for (int i = 0; factors[i]; i++)
			printf ("%d\n", factors[i]);
		putchar ('\n');

		printf ("Qnt divisors: %d\n", qnt_mult (n1-1)/2);*/
		n1 = (n1-1)/2;
		printf ("%d\n", n1-qnt_mult (n1));

		// printf ("%d\n", (n1/2)-ans+2);

		// BRUTE FORCE:
		// ---------------------------------------------
		/*ans = 1;
		bool test;
		for (int i = 2; i <= (n1-1)/2; i++) {
			test = true;
			// printf ("%d\n", i);
			for (int j = 0; test && factors[j]; j++)
				if (i%factors[j] == 0)
					test = false;
			if (test)
				ans++;
		}
		printf ("%d\n",	ans);*/
		// ---------------------------------------------
		// END OF BRUTE FORCE
	}

	return 0;
}
