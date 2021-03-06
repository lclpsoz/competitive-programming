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

const int N = 3e5 + 10;

ll x[N], p;

ll mdc (ll a, ll b) {
	if (a == 0) return b;
	return mdc (b%a, a);	
}

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	ll md = -1;
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &x[i]);
		if (i == 1)
			md = x[1] - x[0];
		else if (i)
			md = mdc (md, x[i] - x[i-1]);
	}
	for (int i = 0; i < m; i++) {
		scanf ("%lld", &p);
		if (md%p == 0) {
			printf ("YES\n");
			printf ("%lld %d\n", x[0], i+1);
			return 0;
		}
	}
	printf ("NO\n");
	
	return 0;
}
