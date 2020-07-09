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

const int N = 2e5+10;

int n, m;
vector<int> adj[N];
bool vis[N];

bool dfs (int v, int p) {
	if (vis[v]) return true;
	vis[v] = true;
	bool ret = true;
	if (len (adj[v]) != 2) ret = false;
	for (int u : adj[v])
		if (u != p)
			ret = min (ret, dfs (u, v));
	return ret;
}

int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			ans += dfs (i, i);
	printf ("%d\n", ans);
	
	return 0;
}
