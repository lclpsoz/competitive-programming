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

const int INF = 1e9;
const int N = 1e5+10, K = 20;

int n;
int sparseMax[N][K], sparseMin[N][K];

void build () {
	for (int i = 1; (1<<i) <= n; i++)
		for (int j = 0; j <= n-(1<<(i-1)); j++)
			sparseMax[j][i] = max (sparseMax[j][i-1], sparseMax[j+(1<<(i-1))][i-1]);
		
	for (int i = 1; (1<<i) <= n; i++)
		for (int j = 0; j <= n-(1<<(i-1)); j++)
			sparseMin[j][i] = min (sparseMin[j][i-1], sparseMin[j+(1<<(i-1))][i-1]);
}

int queryMin (int l, int r){
	if (l > r) return INF;
	int k = 31-__builtin_clz (r-l+1);
	return min (sparseMin[l][k], sparseMin[r+1-(1<<k)][k]);
}

int queryMax (int l, int r){
	if (l > r) return -INF;
	int k = 31-__builtin_clz (r-l+1);
	return max (sparseMax[l][k], sparseMax[r+1-(1<<k)][k]);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &sparseMax[i][0]);
		sparseMin[i][0] = sparseMax[i][0];
	}
	build ();
	
	int q; scanf ("%d", &q);
	while (q--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		int mn = queryMin (l, r);
		int mxIn = queryMax (l, r);
		int mxOut = max (queryMax (0, l-1), queryMax (r+1, n-1));
		printf ("%.1Lf\n", max ((ld)(mn+mxIn)/2, (ld)(mn+mxOut)));
	}
	
	return 0;
}
