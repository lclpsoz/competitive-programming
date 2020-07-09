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

const int N = 1e5 + 10;

int n, c, t;
int a[N];

bool check (int secs) {
	int comp = c-1;
	ll fr = secs*1LL*t;
	// printf ("secs = %d\n", secs);
	for (int i = 0; i < n; i++) {
		if (fr >= a[i]) {
			fr -= a[i];
		} else {
			comp--;
			fr = secs*1LL*t - a[i];
		}
		// if (secs < 10)
		// 	printf ("%d: %d %d\n", i, comp, fr);
		if (comp < 0 or fr < 0)
			return false;
	}

	return true;
}

int main () {
	scanf ("%d %d %d", &n, &c, &t);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	int l = 1, r = 1e9 + 100;
	while (l < r) {
		int md = (l+r)/2;
		if (check (md))
			r = md;
		else
			l = md+1;
	}

	printf ("%d\n", l);

	return 0;
}
