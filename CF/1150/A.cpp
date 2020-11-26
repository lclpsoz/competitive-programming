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
	int n, m, r;
	scanf ("%d %d %d", &n, &m, &r);
	int mn = 1e9, mx = -1;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		mn = min (x, mn);
	}
	int rr = r;
	int q = r/mn;
	r -= q*mn;
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x);
		mx = max (x, mx);
	}
	r += q*mx;
	printf ("%d\n", max (r, rr));

	return 0;
}
