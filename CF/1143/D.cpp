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
int a, b;

ll mdc (ll x, ll y) {
	if (x == 0) return y;
	return mdc (y%x, x);
}

ll mmc (ll x, ll y) {
	return (x*y)/mdc (x, y);
}

int main () {
	scanf ("%d %d", &n, &k);
	scanf ("%d %d", &a, &b);
	ll total = n*1LL*k;
	ll st1 = a, st2 = (total-a)%total;

	ll frst, l, now;
	ll mn = 1e18, mx = - 1e18;
	for (ll i = 0; i < total; i+=k) {
		frst = i-b;
		if (frst < 0) frst += total;

		l = abs (frst - st1);
		if (l == 0) l = total;
		now = total/mdc (total, l);
		mn = min (now, mn);
		mx = max (now, mx);

		l = abs (frst - st2);
		if (l == 0) l = total;
		now = total/mdc (total, l);
		mn = min (now, mn);
		mx = max (now, mx);
		// printf ("i = %lld, l = %lld, now = %lld\n", i, l, now);
	
		frst = i+b;

		l = abs (frst - st1);
		if (l == 0) l = total;
		now = total/mdc (total, l);
		mn = min (now, mn);
		mx = max (now, mx);
		
		l = abs (frst - st2);
		if (l == 0) l = total;
		now = total/mdc (total, l);
		mn = min (now, mn);
		mx = max (now, mx);
		// printf ("i = %lld, l = %d, now = %lld\n", i, l, now);
	}
	printf ("%lld %lld\n", mn, mx);

	return 0;
}
