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

int n, l;
ll cost[33];

int main () {
	scanf ("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &cost[i]);
		if (i)
			cost[i] = min (cost[i], cost[i-1]*2);
	}
	for (int i = n; i <= 30; i++)
		cost[i] = 2*cost[i-1];
	
	for (int i = n-2; i >= 0; i--)
		cost[i] = min (cost[i], cost[i+1]);
	
	ll acu = 0;
	ll ans = 1e18;
	int p = 30;
	while (l and p >= 0) {
		if (l - (1<<p) < 0) {
			ans = min (ans, acu+cost[p]);
		} else if (l - (1<<p) == 0) {
			ans = min (ans, acu+cost[p]);
			break;
		} else {
			acu += cost[p];
			l -= 1<<p;
		}
		--p;
	}
	
	printf ("%lld\n", ans);
	
	return 0;
}
