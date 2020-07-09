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

int n, budget, h, w;

int main () {
	while (scanf ("%d", &n) != EOF) {
		scanf ("%d %d %d", &budget, &h, &w);
// 		printf ("%d %d %d %d\n", n, budget, h, w);
		int ans = budget + 1;
		while (h--) {
			int x; scanf ("%d", &x);
			ll price = 1LL*x*n;
			for (int i = 0; i < w; i++) {
				scanf ("%d", &x);
				if (x >= n and price < ans)
					ans = price;
			}
		}
		
		if (ans > budget)
			printf ("stay home\n");
		else
			printf ("%d\n", ans);
	}

	return 0;
}
