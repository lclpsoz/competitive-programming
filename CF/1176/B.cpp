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

int a[5];

int main () {
	int t, n;
	scanf ("%d", &t);
	while (t--) {
		memset (a, 0, sizeof a);
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			a[x%3]++;
		}
		a[0] += min (a[1], a[2]);
		int mn = min (a[1], a[2]);
		a[1] -= mn;
		a[2] -= mn;
		a[0] += a[1]/3 + a[2]/3;
		printf ("%d\n", a[0]);
	}

	return 0;
}
