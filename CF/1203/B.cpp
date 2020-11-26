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
int n;
int a[500];

int main () {
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &n);
		for (int i = 0; i < 4*n; i++) scanf ("%d", &a[i]);
		sort (a, a + (4*n));
		int area = -1;
		bool ans = true;
		for (int i = 0; i < 2*n; i+=2) {
			if (a[i] != a[i+1] or a[4*n-i-1] != a[4*n-i-2]) {
				ans = false;
				break;
			} else {
				if (area == -1)
					area = a[i] * a[4*n-i-1];
				else if (area != a[i] * a[4*n-i-1]) {
					ans = false;
					break;
				}
			}
		}
		printf ("%s\n", ans ? "YES" : "NO");
	}


	return 0;
}
