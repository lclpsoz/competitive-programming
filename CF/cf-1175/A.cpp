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

int main () {
	int t;
	scanf ("%d", &t);
	while (t--) {
		ll n, k;
		scanf ("%lld %lld", &n, &k);
		
		ll ans = 0;
		while (n > 0) {
			if (n%k == 0) n/=k, ++ans;
			else {
				ans += n%k;
				n-= n%k;
			}
		}
		printf ("%lld\n", ans);
	}
	
	return 0;
}
