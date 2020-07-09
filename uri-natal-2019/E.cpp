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

int n;

int main () {
	while (scanf ("%d", &n), n) {
		int ans = 0;
		int bef = 1;
		while (n--) {
			int a[3];
			for (int i = 0; i < 3; i++)
				scanf ("%d", &a[i]);
			if (a[0] or a[1]) {
				for (int i = 0; i < 3; i++) {
					if (a[i] == 0) {
						ans += abs (i - bef);
						bef = i;
					}
				}
			}
		}
		printf ("%d\n", ans);
	}

	return 0;
}
