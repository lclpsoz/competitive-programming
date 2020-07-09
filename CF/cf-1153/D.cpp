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
int typ[N];
int parent[N], qntLeaf[N], qntSons[N], subTree[N], zeros[N];
vector<int> adj[N];

int solve (int vv) {
	if (len (adj[vv]) == 0) return zeros[vv] = 0;

	int &q0 = zeros[vv];
	vector<int> vec;
	for (int u : adj[vv]) {
		vec.push_back (u);
		solve (u);
	}
	
	if (typ[vv] == 1) {
		int ax = 0;
		for (int v : vec)
			ax += subTree[v];
		for (int v : vec)
			q0 = max (q0, ax - subTree[v] + zeros[v]);
	} else
		for (int v : vec)
			q0 += zeros[v];

	// printf ("%d: %d\n", vv, q0);

	return q0;
}

int dfs (int v) {
	subTree[v] = len (adj[v]) == 0;
	for (int u : adj[v]) {
		dfs (u);
		subTree[v] += subTree[u];
	}

	return subTree[v];
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &typ[i]);

	parent[1] = 1;
	for (int i = 2; i <= n; i++) {
		scanf ("%d", &parent[i]);
		adj[parent[i]].push_back (i);
	}

	dfs (1);
	// for (int i = 1; i <= n; i++)
	// 	printf ("%d: subTree = %d\n", i, subTree[i]);
	printf ("%d\n", solve (1) + 1);

	return 0;
}
