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

int t, n, k;
int a[N], d[N];
int bit[N];



int check (int x) {
	for (int i = 1; i <= n; i++) d[i] = abs (a[i] - x);
	sort (d+1, d+n+1);
	return d[k];
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &k);
		++k;
		for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
		int sz = 2e9, p;
		for (int i = 1; i <= n-k+1; i++) {
			if (a[i+k-1] - a[i] < sz) {
				sz = a[i+k-1] - a[i];
				p = i;
			}
		}
		printf ("%d\n", (a[p] + a[p+k-1])/2);
		// for (int i = 1; i <= 10; i++)
		// 	printf ("  f(%d) = %d\n", i, check (i));
	}

	return 0;
}
