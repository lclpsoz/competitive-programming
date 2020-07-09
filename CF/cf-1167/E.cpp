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

const int N = 1e6 + 10;

int n, maxiVal;
int a[N];
int biggerLeft[N], smallerRight[N], biggerLeftVal[N];
bool imp[N], smallerRightVal[N];

bool check (int x) {
	int bef = -1;
	for (int i = 1; i <= n; i++)
		if (a[i] > x) {
			if (bef > a[i]) return false;
			bef = a[i];
		}

	return true;
}

int main () {
	scanf ("%d %d", &n, &maxiVal);
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		if (a[i] < mx) biggerLeft[i] = mx, biggerLeftVal[a[i]] = max (mx, biggerLeftVal[a[i]]);
		mx = max (mx, a[i]);
	}
	int mn = 1e9;
	int biggerImp = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] > mn) {
			smallerRight[i] = mn, smallerRightVal[a[i]] = true;
			if (biggerLeft[i]) {
				imp[a[i]] = true;
				biggerImp = max (biggerImp, a[i]);
			}
		}
		if (imp[a[i]]) a[i] = -1;
		else mn = min (mn, a[i]);
	}
	// for (int i = 1; i <= maxiVal; i++)
		// printf ("%d: biggerLeftVal = %d,  smallerRightVal = %d\n", i, biggerLeftVal[i], smallerRightVal[i]);

	int l = biggerImp, r = maxiVal;
	while (l < r) {
		int md = (l + r)/2;
		if (check (md))
			r = md;
		else
			l = md+1;
	}
	if (l == 0)
		printf ("%lld\n", ((ll)maxiVal*(maxiVal+1))/2);
	else {
		l = 1;
		ll ans = 0;
		for (; l <= maxiVal; l++) {
			// printf ("l = %d\n", l);
			if (imp[l-1] or smallerRightVal[l-1]) break;
			r = max (max(l, r), biggerLeftVal[l-1]);
			ans += maxiVal - r + 1;
			// printf ("(%d, %d) -> %lld\n", l, r, ans);
		}
		printf ("%lld\n", ans);
	}


	return 0;
}
