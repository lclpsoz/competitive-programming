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

int n, p;

int main () {
	scanf ("%d %d", &n, &p);
	for (int ans = 1; ans < 1e7 + 10; ans++) {
		ll nn = n - (p*1LL*ans);
		if (nn <= 0) {
			printf ("-1\n");
			exit (0);
		} else if (__builtin_popcountll (nn) <= ans and nn >= ans) {
			printf ("%d\n", ans);
			exit (0);
		}
	}

	return 0;
}
