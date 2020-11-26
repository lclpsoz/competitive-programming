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
		vector<int> v;
		int pos = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			if (x == 1) pos = i;
			v.push_back (x);
		}
		if (n <= 2) {
			printf ("YES\n");
			continue;
		}
		bool ans = true;
		if (v[(pos+1)%n] == 2) {
			int now = 1;
			for (int i = pos; i < pos+n; i++)
				if (v[i%n] != now++) {
					ans = false;
					break;
				}
		} else if (v[(pos-1+n)%n] == 2) {
			int now = 1;
			for (int i = pos; i > pos-n; i--)
				if (v[(i+n)%n] != now++) {
					ans = false;
					break;
				}
		} else {
			printf ("NO\n");
			continue;
		}
		printf ("%s\n", ans ? "YES" : "NO");
	}

	return 0;
}
