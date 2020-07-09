#include <bits/stdc++.h>
using namespace std;

const int MAXP = 2e7;
const int MAXN = 1e5+550;

int i, j;
bool not_prime[MAXP];
vector<int> divs[MAXN];
bool in_set[MAXP];

// True if could insert,
// False otherwise
bool func (int x)
{
	bool test = true;
	if (!not_prime[x]) {
		if (in_set[x])
			test = false;
		else
			in_set[x] = true;
	}
	else {
		if (in_set[x])
			test = false;
		else {
			for (int val : divs[x]) {
				if (in_set[val]) {
					test = false;
					break;
				}
			}
		}
		if (test)
			for (int val : divs[x])
				in_set[val] = true;
	}
	return test;
}

int main ()
{
	// Sieve pushing divisors in vectors
	i = 2;
	for (; i*i < MAXP; i++)
		if (!not_prime[i]) {
			for (j = i+i; j < MAXN; j+=i) {
				not_prime[j] = true;
				divs[j].push_back (i);
			}
			for (; j < MAXP; j+=i)
				not_prime[j] = true;
		}
	for (; i+i < MAXN; i++)
		if (!not_prime[i])
			for (j = i+i; j < MAXN; j+=i)
				divs[j].push_back (i);
	// ---------------------------------
	int x, n;
	bool test = true;
	scanf ("%d", &n);
	while (n) {
		// printf ("%d\n", n);
		n--;
		scanf ("%d", &x);
		test = func (x);
		if (!test) break;
		printf ("%d", x);
		if (n)
			putchar (' ');
	}
	while (!test) {
		x++;
		test = func(x);
		if (test) {
			printf ("%d", x);
			if (n) putchar (' ');
		}
	}

	for (i = 2; n && i < MAXP; i++)
		if (!not_prime[i] && !in_set[i]) {
			n--;
			printf ("%d", i);
			if (n) putchar (' ');
		}
	putchar ('\n');


	return 0;
}
