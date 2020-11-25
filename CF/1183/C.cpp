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

int main () {
	int q;
	scanf ("%d", &q);
	while (q--) {
		int k, n, a, b;
		scanf ("%d %d %d %d", &k, &n, &a, &b);
		int l = 0, r = n;
		while (l < r) {
			int md = (l+r+1)/2;
			if (a*1LL*md + b*1LL*(n-md) >= k)
				r = md-1;
			else
				l = md;
		}
		if (l == 0 and b*1LL*n >= k)
			printf ("-1\n");
		else
			printf ("%d\n", l);
	}

	return 0;
}
