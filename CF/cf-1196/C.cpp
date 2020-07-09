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

int q;

int main () {
	scanf ("%d", &q);
	while (q--) {
		int n;
		scanf ("%d", &n);
		int xL = -1e5, xR = 1e5;
		int yU, yD;
		yD = xL, yU = xR;
		while (n--) {
			int x, y;
			scanf ("%d %d", &x, &y);
			int opt;
			scanf ("%d", &opt);
			if (opt == 0)
				xL = max (xL, x);
			scanf ("%d", &opt);
			if (opt == 0)
				yU = min (yU, y);
			scanf ("%d", &opt);
			if (opt == 0)
				xR = min (xR, x);
			scanf ("%d", &opt);
			if (opt == 0)
				yD = max (yD, y);
		}
		if (xL > xR or yD > yU)
			printf ("0\n");
		else
			printf ("1 %d %d\n", xL, yD);
	}

	return 0;
}
