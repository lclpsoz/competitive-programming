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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

ll mdc(ll a, ll b){
	if(b == 0) return a;
	return mdc(b, a%b);
}

int main () {
	ll a, b, x, y;
	scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
	ll md = mdc(x, y);
	x /= md;
	y /= md;
	printf("%lld\n", min(a/x, b/y));

	return 0;
}
