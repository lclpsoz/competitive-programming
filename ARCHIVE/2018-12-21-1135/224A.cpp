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

int mdc (int a, int b) {
	if (a == 0) return b;
	return mdc (b%a, a);
}

int main () {
	int a, b, c;
	scanf ("%d %d %d", &a, &b, &c);
// 	printf ("%d\n", mdc (a, b));
	int x, y, z;
	x = mdc (a, b);
	for (int i = 1; i <= x; i++) {
		if (x%i != 0)
			continue;
		y = a/i;
		z = b/i;
		if (z*y == c) {
// 			printf ("%d %d %d\n", i, y, z);
			printf ("%d\n", 4*(i + y + z));
			return 0;
		}
	}

	return 0;
}

