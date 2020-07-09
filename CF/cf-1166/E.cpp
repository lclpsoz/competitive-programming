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

int m, n, s;
vector<int> days[60];

int main () {
	scanf ("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		int s;
		scanf ("%d", &s);
		set<int> now;
		while(s--) {
			int x;
			scanf ("%d", &x);
			days[i].push_back (x);
			now.insert (x);
		}
		for (int j = 0; j < i; j++) {
			int q = 0;
			for (int x : days[j]) {
				// printf ("  x = %d\n", x);
				q += now.count (x);
			}
			// printf ("%d %d: %d\n", i, j, q);
			if (q == 0) {
				printf ("impossible\n");
				exit (0);
			}
		}
	}
	printf ("possible\n");

	return 0;
}
