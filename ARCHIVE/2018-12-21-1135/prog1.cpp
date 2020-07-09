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
	for (int n = 1; n < 100; n++)
		for (int m = 1; m < 100; m++) {
			ll res = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					res += (n-1) + (m-1) + min (i, j) + min (i, m-j-1) +
						min (n-i-1, j) + min (n-i-1, m-j-1);

			printf ("%lld\n", res);
		}

	return 0;
}
