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

int h, u, d, f;

int main () {
	while (scanf ("%d %d %d %d", &h, &u, &d, &f), h) {
		h *= 100;
		u *= 100;
		d *= 100;
		f = (u/100) * f;
		int now	= 0;
		for (int i = 1;; i++) {
// 			printf ("%d: now = %d, up = %d\n", i, now, u);
			now += u;
			u = max (0, u - f); // Update UP
			if (now > h) {
				printf ("success on day %d\n", i);
				break;
			}
			
// 			if (now == 0) {
// 				printf ("failure on day %d\n", i);
// 				break;
// 			}
			
			now = now - d;
			if (now < 0) {
				printf ("failure on day %d\n", i);
				break;
			}
		}
	}

	return 0;
}
