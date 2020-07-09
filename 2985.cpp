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
vector<pii> vec;

int main () {
	scanf ("%d", &n);
	while (n--) {
		int h, d;
		scanf ("%d %d", &h, &d);
		vec.push_back ({h+d, h});
	}
	sort (vec.begin(), vec.end());
	int lst = 0;
	int ans = 0;
	for (pii p : vec) {
		if (lst <= p.y) {
			// printf ("%d %d\n", p.y, p.x);
			ans++;
			lst = p.x;
		}
	}
	printf ("%d\n", ans);

	return 0;
}
