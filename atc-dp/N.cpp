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

const int N = 410;

int n;
ll a[N];

int minP () {
	ll now = a[1] + a[2];
	int p = 1;
	for (int i = 2; i < n; i++)
		if (a[i] + a[i+1] < now) {
			now = a[i] + a[i+1];
			p = i;
		}
		
	return p;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	ll ans = 0;
	
	while (n > 1) {
		int p = minP ();
		ans += a[p] + a[p+1];
		for (int i = p+1; i <= n; i++) {
			a[i-1] += a[i];
			a[i] = 0;
		}
		--n;
	}
	
	printf ("%lld\n", ans);


	return 0;
}
