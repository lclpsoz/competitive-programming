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

const int N = 1e5 + 10;

int a[N];

int main () {
	int n, t;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		int k = 0;
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
		bool inter = false;
		bool ans = true;
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			if (x < a[i]) ans = false;
			if (x != a[i]) {
				if (inter)
					ans = false;
				else if (k == 0)
					k = x - a[i];
				else if (k != x - a[i])
					ans = false;
			} else if (k and !inter)
				inter = true;
		}
		printf ("%s\n", ans ? "YES" : "NO");
	}

	return 0;
}
