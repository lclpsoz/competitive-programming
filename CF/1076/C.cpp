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

const ld EPS = 1e-12;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int t, d;

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &d);
		if (d == 1 or d == 2 or d == 3)
			printf ("N\n");
		else {
			int count = 0;
			ld l, r;
			l = 1; r = d/2.0;
			while (count < 1e4) {
				ld md = (l+r)/2;
				if (cmp ((md + (d/md)), d) == -1)
					r = md-EPS;
				else
					l = md;
				++count;
			}
			printf ("Y %.9Lf %.9Lf\n", d/l, l);
		}
	}

	return 0;
}
