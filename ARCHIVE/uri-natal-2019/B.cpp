#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e8 + 100;

bitset<N> not_prime;

int main () {
	for (int i = 2; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = 1;
	//for (int i=  2; i < 100; i++)
	//	if (!not_prime[i]) printf ("%d\n", i);
	int n;
	scanf ("%d", &n);
	while (n--) {
		int x;
		scanf ("%d", &x);
		++x;
		if (x%2 == 1 and x%7 == 0 and !not_prime[x+2])
			printf ("Yes\n");
		else
			printf ("No\n");
	}

	return 0;
}
