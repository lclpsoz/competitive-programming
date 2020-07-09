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

const int N = 3e5 + 10;

int n;
int lft[N], rgt[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		if (lft[x] == 0) lft[x] = i+1;
		rgt[x] = max (rgt[x], i+1);
	}
	vector<pii> ax, ax2;
	for (int i = 1; i <= n; i++)
		if (lft[i])
			ax.push_back ({lft[i], i});
	for (int i = 1; i <= n; i++)
		if (rgt[i])
			ax2.push_back ({rgt[i], i});
	sort (ax.begin(), ax.end());
	sort (ax2.begin(), ax2.end(), greater<pii>());
	printf ("%d %d\n", ax[0].y, ax2[0].y);
	if (ax[0].y != ax2[0].y) {
		printf ("%d\n", abs (ax[0].x - ax2[0].x));
	} else {
		printf ("%d\n", max (abs (ax[1].x - ax2[0].x), abs (ax[0].x - ax2[1].x)));
	}

	return 0;
}
