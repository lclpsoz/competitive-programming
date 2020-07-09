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

int n, k;
int a[200];

bool eval (int b) {
	for (int i = 1; i <= n; i++)
		if (abs (b-a[i]) > k) return false;
	return true;
}

int main () {
	int q;
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &n, &k);
		int mn = 1e9, mx = - 1e9;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &a[i]);
			mn = min (a[i], mn);
			mx = max (a[i], mx);
		}
		if (mx-mn > 2*k) {
			printf ("-1\n");
		} else
			printf ("%d\n", mn+k);
		// for (int i = 1; i <= 20; i++)
		// 	printf ("%d: %d\n", i, eval(i));
		// int l = 0, r = 1e9 + 100;
		// while (l < r) {
		// 	int md = (l+r+1)/2;
		// 	if (eval (md))
		// 		l = md;
		// 	else
		// 		r = md-1;
		// }
		// printf ("%d\n", l);
	}

	return 0;
}
