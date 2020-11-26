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
		pii p1, p2;
		scanf ("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
		if (p1.x > p2.x)
			printf ("%d %d\n", p1.y, p2.x);
		else
			printf ("%d %d\n", p1.x, p2.y);
	}

	return 0;
}
