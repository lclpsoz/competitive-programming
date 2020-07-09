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

int n, k;

ll eval (ll i, int m) {
	ll x = k*i + m;
	return ((x/k) * m);
}

int main () {
	scanf ("%d %d", &n, &k);
	ll ans = 1e18;
	for (int i = 1; i < k; i++) {
		ll l = 0, r = (ll)(1e9+100);
		while (l < r) {
			ll md = (l+r+1)/2;
			if (eval (md, i) > n)
				r = md - 1;
			else
				l = md;
		}
// 		printf ("%d: %lld | %lld\n", i, l, l*k + i);
		if (eval (l, i) == n)
			ans = min (ans, (ll)(l*k + i));
	}
	printf ("%lld\n", ans);
	
	return 0;
}
