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

ll n, d, a, b;
vector<pair<ll, int>> vec;

int main () {
	scanf ("%lld %lld", &n, &d);
	scanf ("%lld %lld", &a, &b);
	for (int i = 1; i <= n; i++) {
		ll x, y;
		scanf ("%lld %lld", &x, &y);
		vec.push_back ({a*x + b*y, i});
	}
	sort (vec.begin(), vec.end());
	vector<int> ans;
	for (int i = 0; i < len (vec); i++) {
		if (vec[i].x <= d) {
			ans.push_back (vec[i].y);
			d -= vec[i].x;
		} else
			break;
	}
	
	printf ("%d\n", len (ans));
	for (int i = 0; i < len (ans); i++)
		printf ("%d%c", ans[i], " \n"[i==len(ans)-1]);

	return 0;
}
