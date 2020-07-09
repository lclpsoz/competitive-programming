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

// Topological Sort (Directed Acyclic Graph - DAG)

const int MAXN = 1e5+100;

int n, m;
vector<int> adj[MAXN], adjInv[MAXN], topo;
bool vis[MAXN];

void dfs (int v) {
	if (vis[v]) return;
	vis[v] = true;
	for (int u : adjInv[v])
		dfs (u);
	topo.push_back (v);
}

int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int u, v;
		scanf ("%d %d", &u, &v);
		adj[u].push_back (v);
		adjInv[v].push_back (u);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs (i);
	
	printf ("Topological sort:\n");
	for (int i = 0; i < n; i++)
		printf ("%d%c", topo[i], " \n"[i==n-1]);

	return 0;
}
