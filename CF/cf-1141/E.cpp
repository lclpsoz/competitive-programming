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

const int N = 2e5+10;

ll h;
ll a[N];
int n;

int main () {
	scanf ("%lld", &h);
	scanf ("%d", &n);
	ll sum = 0;
	ll mini = 1e18;
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
		sum += a[i];
		if (-sum >= h) { // DIES ON FIRST ROUND
			printf ("%d\n", i+1);
			exit (0);
		}
		mini = min (mini, sum);
	}
	
	if (sum >= 0)
		printf ("-1\n");
	else {
		ll ans = 0;
		ll q = ((h+mini)/-sum) - 1;
		ans += q*n;
		h += sum*q;
		int d = 0;
		while (h > 0) {
			h += a[d%n];
			d++;
			assert (d < 10'000'000);
		}
		printf ("%lld\n", ans + d);		
	}
	

	return 0;
}
