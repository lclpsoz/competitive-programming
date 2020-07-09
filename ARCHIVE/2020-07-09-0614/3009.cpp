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

const int N = 1010;

int t, n, m;
vector<int> adj[N], inv[N];
bitset<N> vis;

void dfs (int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : adj[v])
		dfs (u);
}

bool check (int v) {
	if (v == -1) return false;
	dfs (v);
	bool ret = true;

	for (int i = 1; i <= n; i++) {
		ret = ret and vis[i];
		vis[i] = 0;
	}

	return ret;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) inv[i].clear(), adj[i].clear(), vis[i] = 0;
		while (m--) {
			int x, y;
			scanf ("%d %d", &x, &y);
			adj[x].push_back (y);
			inv[y].push_back (x);
		}
		for (int i = 1; i <= n; i++) if (len (inv[i]) == 0) choosen = i;
		printf ("%c\n", check (choosen) ? 'S' : 'N');			
	}

	return 0;
}
