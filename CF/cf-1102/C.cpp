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

int a[110];

int main () {
	int n, x, y;
	scanf ("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	sort (a, a+n);
	if (x > y)
		printf ("%d\n", n);
	else if (x <= y) {
		int ans = 0, bef = 0;
		do {
			bef = ans;
			for (int i = n-1; i >= 0; i--)
				if (a[i] and a[i] <= x) {
					a[i] = 0;
					++ans;
					break;
				}

			// Second phase
			for (int i = n-1; i >= 0; i--)
				if (a[i] <= x and a[i]) {
					a[i] += y;
					break;
				}
		} while (bef < ans);
		printf ("%d\n", ans);
	}

	return 0;
}
