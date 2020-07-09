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

int a, x, y;

void no () {
	printf ("-1\n");
	exit (0);
}

int main () {
	cin >> a >> x >> y;
	if (x > a or x < -a)
		no ();
	else {
		if (y > 0 and y < a) {
			if (cmp (abs (x), a/2.0) == -1) {
				printf ("1\n");
				exit (0);
			}
			else
				no();
		}
		else if (y%a) {
			int now = 2;
			int y1 = a, y2 = 2*a;
			for (int i = 2; i <= 5e6; i++) {
				if (i%2 == 0) {
					if (y > y1 and y < y2 and cmp (abs(x), a/2.0) == -1) {
						printf ("%d\n", now);
						exit (0);
					}
				} else {
					if (y > y1 and y < y2 and x > -a and x < 0) {
						printf ("%d\n", now);
						exit (0);
					}
					++now;
					if (y > y1 and y < y2 and x > 0 and x < a) {
						printf ("%d\n", now);
						exit (0);
					}
				}
				++now;
				y1 += a, y2 += a;
			}
		}
	}
	no();

	return 0;
}
