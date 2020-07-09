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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

ll sum;

int invMod (int x) {
	int p = MOD - 2;
	int ret = 1;
	int b = x;
	while (p) {
		if (p&1) ret = mod (ret * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}

	return ret;
}

int main () {
	// for (int i = 1; i <= 20; i++) {
	// 	sum += i*i;
	// 	printf ("%3d\t%6d\t%6lld\t%Lf\t%Lf\n", i, i*i, sum, (ld)sum/i, (ld)sum/(i*i));
	// }

	ll l, r;
	cin >> l >> r;
	ll sqL = sqrt((ld)l-1);
	ll sqR = sqrt((ld)r-1);
	while (sqL*sqL < l)
		sqL++;
	while ((sqR+1)*(sqR+1) <= r)
		sqR++;
	if (sqR < sqL)
		printf ("0\n");
	else {
		ll a = mod (mod (sqR * (sqR+1)) * (2*sqR + 1));
		sqL--;
		// printf ("%lld %lld\n", sqL, sqR);
		ll b = mod (mod (sqL * (sqL+1)) * (2*sqL + 1));
		// printf ("%lld %lld\n", a, b);
		a = mod (a * invMod(6));
		b = mod (b * invMod(6));
		// printf ("%lld %lld\n", a, b);
		ll c = mod (a - b);
		// printf ("c: %lld\n", c);
		printf ("%d\n", mod (c));
	}

	return 0;
}
