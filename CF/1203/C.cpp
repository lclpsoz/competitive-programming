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

int n;

ll gcd (ll a, ll b){
	if (a == 0) return b;
	return gcd (b%a, a);
}

int main () {
	scanf ("%d", &n);
	ll big = -1;
	while (n--) {
		ll x;
		scanf ("%lld", &x);
		if (big == -1) big = x;
		big = gcd (big, x);
	}
	if (big == 1) {
		printf ("1\n");
		exit (0);
	}
	int ans = 0;
	for (ll i = 1; i*i <= big; i++) {
		if (i*i == big) {
			++ans;
		} else {
			ans += 2*(big%i == 0);
		}
	}
	printf ("%d\n", ans);

	return 0;
}
