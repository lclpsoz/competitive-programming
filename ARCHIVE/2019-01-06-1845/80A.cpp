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

const int P = 70;

int n, m;
bool not_prime[P];

int main () {
	for (int i = 2; i*i < P; i++)
		if (!not_prime[i])
			for (int j = i*i; j < P; j+=i)
				not_prime[j] = true;
	scanf ("%d %d", &n, &m);
	int val = n+1;
	while (not_prime[val]) ++val;
	printf ("%s\n", (val == m) ? "YES" : "NO");

	return 0;
}
