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


vector<pair<ll, ll>> vec;

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		ll a, b;
		scanf ("%lld %lld", &a, &b);
		vec.push_back ({a - b, b*n - a});
	}
	sort (vec.begin(), vec.end(), greater<pair<ll, ll>>());
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += vec[i-1].x*i + vec[i-1].y;
	printf ("%lld\n", sum);

	return 0;
}
