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

const int N = 1e4+100;

int treeL[N][3], treeR[N][3];

int dfs (int v, int acu, int tree[][3]) {
	if (v == 0) return acu;
	acu = dfs (tree[v][0], acu+1, tree);
	
	return acu;
}

int dfsR (int v, int acu, int tree[][3]) {
	if (v == 0) return acu;
	acu = dfsR (tree[v][0], acu+1, tree);
	acu = max (acu, dfsR (tree[v][1], 0, tree));
	
	return acu;
}

int main () {
	int n, m;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int v, l, c;
		scanf ("%d %d %d", &v, &l, &c);
		treeL[v][0] = c;
		treeL[v][1] = l;
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int v, c, r;
		scanf ("%d %d %d", &v, &c, &r);
		treeR[v][0] = c;
		treeR[v][1] = r;
	}
	
	int mn = max (min (dfsR (1, 0, treeL), dfs (1, 0, treeR)),
				  min (dfs (1, 0, treeL), dfsR (1, 0, treeR)));
	printf ("%d\n", m+n - mn);

	return 0;
}
