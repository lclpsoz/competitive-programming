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

int q, n;
int a[110];

int main () {
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
		int p = 1;
		while (p < n) {
			int now = 0;
			int mn = 1e9;
			for (int i = p; i <= n; i++) {
				if (a[i] < mn) {
					now = i;
					mn = a[i];
				}
			}
			for (int i = now-1; i >= p; i--)
				swap (a[i], a[i+1]);
			if (p == now)
				++p;
			else
				p = now;
		}
		for (int i = 1; i <= n; i++) printf ("%d ", a[i]);
		putchar ('\n');
	}

	return 0;
}
