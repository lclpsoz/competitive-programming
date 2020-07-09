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

int n;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		ll s;
		scanf ("%lld", &s);
		int l = 0, r = 2e9+100;
		while (l < r) {
			int md = ((ll)l+r+1)/2;
			if (((md*1LL*(md+1))/2LL) <= s)
				l = md;
			else
				r = md-1;
		}
		
		printf ("%d\n", l);
	}

	return 0;
}
