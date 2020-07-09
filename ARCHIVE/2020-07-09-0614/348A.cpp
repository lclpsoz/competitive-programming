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

const int N = 1e5 + 100;

int n;
int a[N];

bool check (ll rounds) {
	ll total = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > rounds) return false;
		if (total + rounds - a[i] < 1e18)
			total += rounds-a[i];
	}
	for (int i = 0; i < n; i++)
		if (total - (rounds-a[i]) < a[i]) return false;
	return true;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);

	ll l = 1, r = 1e18;
	while (l < r) {
		ll md = (l+r)/2;
		if (check (md))
			r = md;
		else
			l = md+1;
	}
	printf ("%lld\n", l);

	return 0;
}
