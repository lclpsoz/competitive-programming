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

const int N = 1e5+10;

int n, m;
int a[N];

int main () {
	scanf ("%d", &m);
	int mn = 2e9;
	while (m--) {
		int x;
		scanf ("%d", &x);
		mn = min (mn, x);
	}
	
	ll ans = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		ans += a[i];
	}
	sort (a, a+n, greater<int>());
	for (int i = 0; i < n; i+=mn+2) {
// 		printf ("i: %d\n", i);
		int q = min (2, max (0, n-i-mn));
		int en = min (i+mn+2-1, n-1);
		for (int j = en; j > en-q; j--)
			ans -= a[j];
	}
	printf ("%lld\n", ans);

	return 0;
}
