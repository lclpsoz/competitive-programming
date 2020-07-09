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

vector<ll> lucky;

int main () {
	for (int l = 1; l <= 10; l++) {
		string str = "";
		for (int i = 0; i <= l; i++) {
			str = "";
			for (int j = 0; j < l-i; j++)
				str += '4';
			for (int j = 0; j < i; j++)
				str += '7';
			
			do {
				lucky.push_back (stoll (str));
			} while (next_permutation (str.begin(), str.end()));
		}
	}
	sort (lucky.begin(), lucky.end());
	ll l, r;
	scanf ("%lld %lld", &l, &r);
	ll nextNow = (*lower_bound (lucky.begin(), lucky.end(), l));
	ll ans = 0;
	while (l <= r) {
		if (nextNow >= r) {
			ans += (r-l+1) * 1LL * nextNow;
			break;
		}
		ans += (nextNow - l + 1) * 1LL * nextNow;
		l = nextNow + 1;
		nextNow = (*lower_bound (lucky.begin(), lucky.end(), l));
	}
	printf ("%lld\n", ans);

	return 0;
}
