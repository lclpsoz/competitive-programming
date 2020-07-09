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

const int N = 1e5+10, K = 20;

int n, m;
vector<int> vals;
int sparse[N][K];

void build () {
	for (int i = 0; i < n-1; i++)
		sparse[i][0] = vals[i+1]-vals[i];
	for (int i = 1; (1<<i) <= n-1; i++)
		for (int j = 0; j <= (n-1-(1<<(i-1))); j++)
			sparse[j][i] = max (sparse[j][i-1],
								sparse[j+(1<<(i-1))][i-1]);
}

int query (int l, int r) {
	int k = 31 - __builtin_clz (r-l+1);
	return max (sparse[l][k], sparse[l+(r-l+1-(1<<k))][k]);
}

int bs (int l, int r, int d) {
	while (l < r) {
		int md = (l+r)/2;
		if (query (md, r) > d)
			l = md+1;
		else
			r = md;
	}
	
	if (r < l or query (l, r) > d)
		return r+1;
	return l;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vals.push_back (x);
	}
	build ();
	
	scanf ("%d", &m);
	while (m--) {
		int t, d;
		scanf ("%d %d", &t, &d);
		auto it = upper_bound (vals.begin(), vals.end(), t);
		printf ("%d\n", bs (0, (int)(it-vals.begin()-2), d)+1);
	}

	return 0;
}
