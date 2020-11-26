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
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	vector<pii> vec;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back ({x, i});
	}
	sort (vec.begin(), vec.end(), greater<pii>());
	vector<int> pos;
	ll ans = 0;
	for (int i = 0; i < m*k; i++) {
		ans += vec[i].x;
		pos.push_back (vec[i].y);
	}
	
	sort (pos.begin(), pos.end());
	printf ("%lld\n", ans);
	for (int i = 0; i < m*(k-1); i++)
		if ((i+1)%m == 0)
			printf ("%d%c", pos[i], " \n"[i==(m*k-1)]);

	return 0;
}
