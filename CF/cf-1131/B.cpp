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
	pii lst = {0, 0};
	int ans = 1;
	while (n--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		pii p = {x, y};
		if (p.x == lst.x and p.y == lst.y) continue;
		ans += max (0, min (p.x, p.y) - max (lst.x, lst.y) + (lst.x != lst.y));
		// printf ("%d\n", ans);
		lst = p;
	}

	printf ("%d\n", ans);
	return 0;
}
