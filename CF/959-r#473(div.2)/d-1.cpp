#include <bits/stdc++.h>
using namespace std;

const int MAXP = 2e7;
const int MAXN = 1e5+550;

int i, j;
bool not_prime[MAXP];
vector<int> divs[MAXN];
set<int> stash;

void print_stash ()
{
	putchar ('|');
	for (int xx : stash)
		printf (" %d ", xx);
	putchar ('|');
	putchar ('\n');
}

// True if could insert,
// False otherwise
bool func (int x)
{
	// printf ("\n[[[%d]]]\n", x);
	bool test = true;
	i = -1;
	if (stash.insert (x).second == 0)
		test = false;
	if (test) {
		i = 0;
		for (;i < divs[x].size(); i++) {
			if (!stash.insert (divs[x][i]).second) {
				test = false;
				break;
			}
		}
	}

	if (!test) {
		if (i >= 0)
			stash.erase (x);
		for (j = 0; j < i; j++)
			stash.erase (divs[x][j]);
	}
	return test;
}

int main ()
{
	// Sieve pushing divisors in vectors
	i = 2;
	for (; i*i < MAXN; i++)
		if (!not_prime[i]) {
			for (j = i+i; j < MAXN; j+=i) {
				not_prime[j] = true;
				divs[j].push_back (i);
			}
			for (; j < MAXP; j+=i)
				not_prime[j] = true;
		}
	for (; i*i < MAXP; i++)
		if (!not_prime[i])
			for (j = i*i; j < MAXP; j+=i)
				not_prime[j] = true;
	// ---------------------------------
	int x, n;
	bool test = true;
	scanf ("%d", &n);
	while (n) {
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
		if (!not_prime[i] && stash.count(i) == 0) {
			n--;
			printf ("%d", i);
			if (n) putchar (' ');
		}
	putchar ('\n');


	return 0;
}
