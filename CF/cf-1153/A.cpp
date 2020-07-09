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

int n, t;

int main () {
	scanf ("%d %d", &n, &t);
	int mn = 2e9, ans = -1;
	for (int i = 1; i <= n; i++) {
		int s, d;
		scanf ("%d %d", &s, &d);
		while (s < t)
			s += d;
		// printf ("%d %d\n", i, s-t);
		if ((s-t) < mn) {
			mn = s-t;
			ans = i;
		}
	}
	printf ("%d\n", ans);

	return 0;
}
