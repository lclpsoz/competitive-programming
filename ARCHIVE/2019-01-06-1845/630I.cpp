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

llu powll (int b, int p) {
	if (p <= 0 or p > 30)
		return 1;
	llu r = 1;
	while (p-- > 0)
		r *= b;
	
	return r;
}

llu solve (int n) {
	return 4 * (2*3*powll (4, n-3) + (n-3)*3*3*powll (4, n-4));
}

int main () {
	int n;
	scanf ("%d", &n);
	printf ("%llu\n", solve (n));

	return 0;
}
