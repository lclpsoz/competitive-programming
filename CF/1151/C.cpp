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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

ll l, r;

int main () {
	scanf ("%lld %lld", &l, &r);
	// ODD
	ll esq = 1;
	ll a, b;
	a = 1, b = 1;
	ll ans = 0;
	while (a <= r) {
		if (b >= l) {
			ll lNow = max (l, a);
			ll rNow = min (r, b);
			ll lVal = esq + 2*(lNow - a);
			ll rVal = esq + 2*(b-a) - 2*(b - rNow);
			ll val = mod ((lVal + rVal) / 2);
			ll qnt = mod (rNow - lNow + 1);
			ans = mod (ans + mod (val * 1LL * qnt));
		}
		esq = esq + 2*(b-a+1);
		a *= 4;
		b = a*2 - 1;
	}
	
	// EVEN
	esq = 2;
	a = 2, b = 3;
	while (a <= r) {
		if (b >= l) {
			ll lNow = max (l, a);
			ll rNow = min (r, b);
			ll lVal = esq + 2*(lNow - a);
			ll rVal = esq + 2*(b-a) - 2*(b - rNow);
			ll val = mod ((lVal + rVal) / 2);
			ll qnt = mod (rNow - lNow + 1);
			ans = mod (ans + mod (val * 1LL * qnt));
		}
		esq = esq + 2*(b-a+1);
		a *= 4;
		b = a*2 - 1;
	}
	printf ("%lld\n", ans);
	
	
	return 0;
}
