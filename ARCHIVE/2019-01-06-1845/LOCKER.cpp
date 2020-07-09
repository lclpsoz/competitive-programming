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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int powMod (int b, ll p) {
	int r = 1;
	while (p) {
		if (p&1) r = mod (r * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}
	
	return r;
}

int main () {
	int t; ll n;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%lld", &n);
		if (n <= 4)
			printf ("%lld\n", n);
		else if (n%3 == 0)
			printf ("%d\n", powMod (3, n/3));
		else if (n%3 == 1)
			printf ("%d\n", mod (powMod (3, (n-4)/3) * 1LL * 4));
		else
			printf ("%d\n", mod (powMod (3, n/3) * 1LL * 2));
	}

	return 0;
}
