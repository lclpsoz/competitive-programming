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

ll n, m, a, d;
ll arr[10];

ll mdc (ll x, ll y) {
	if (x == 0) return y;
	return mdc (y%x, x);
}

ll mmc (ll x, ll y) { return (x*y)/mdc(x, y); }

ll solve (ll x) {
	ll qnt = 0;
	for (int msk = 1; msk < 1<<5; msk++) {
		ll ax = 1;
		for (int i = 0; i < 5; i++)
			if ((1<<i) & msk)
				ax = mmc (ax, arr[i]);
		if (__builtin_popcount (msk)&1)
			qnt += x/ax;
		else
			qnt -= x/ax;
	}
	
	return x - qnt;
}

int main () {
	int t; scanf ("%d", &t);
	
	while (t--) {
		scanf ("%lld %lld %lld %lld", &n, &m, &a, &d);
		for (int i = 0; i < 5; i++)
			arr[i] = a + i*d;
		printf ("%lld\n", solve (m) - solve (n-1));
	}

	return 0;
}
