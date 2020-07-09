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

const int MOD = 10'000'007;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int powMod (int b, int p) {
	int r = 1;
	while (p) {
		if (p&1) r = mod (r * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}
	
	return r;
}

int solve (int n, int k) {
	return mod (2*powMod (n-1, k) + powMod (n, k) + 2*powMod (n-1, n-1) + powMod (n, n));
}

int main () {
	int n, k;
	while (scanf ("%d %d", &n, &k), n)
		printf ("%d\n", solve (n, k));

	return 0;
}
