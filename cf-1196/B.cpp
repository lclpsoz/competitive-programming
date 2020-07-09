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

const int N = 2e5 + 10;

int a[N];

int main () {
	int q;
	scanf ("%d", &q);
	while (q--) {
		int n, k;
		scanf ("%d %d", &n, &k);
		int qOdd = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf ("%d", &x);
			a[i] = x%2;
			qOdd += a[i] == 1;
		}
		if (qOdd == 0 or qOdd%2 != k%2 or qOdd < k)
			printf ("NO\n");
		else {
			printf ("YES\n");
			for (int i = 1; i <= n and k > 1; i++)
				if (a[i] == 1) {
					printf ("%d ", i);
					k--;
				}
			printf ("%d\n", n);
		}
	}

	return 0;
}
