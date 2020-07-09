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

// Finding Connected Components on a undirected graph
// Using DFS

const int MAXN = 1e5+10;

int n, m;
int comp[MAXN];
vector<int> adj[MAXN];
vector<int> components[MAXN];

void dfs (int v, int id) {
	if (comp[v]) return;
	comp[v] = id;
	for (int u : adj[v])
		dfs (u, id);
}

int main () {
	scanf ("%d", &n);
	scanf ("%d", &m);
	while (m--) {
		int u, v;
		scanf ("%d %d", &u, &v);
		adj[u].push_back (v);
		adj[v].push_back (u);
	}
	
	int lstComp = 1;
	for (int i = 1; i <= n; i++)
		if (comp[i] == 0)
			dfs (i, lstComp++);
	printf ("Number of components: %d\n", lstComp-1);
	
	printf ("\nEach component in a arbitrary order (vertices on the same line are on the same component\n");
	for (int i = 1; i <= n; i++)
		components[comp[i]].push_back (i);
	for (int i = 1; i < lstComp; i++)
		for (int j = 0; j < len (components[i]); j++)
			printf ("%d%c", components[i][j], " \n"[j==len (components[i])-1]);

	return 0;
}
