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

int t, n, m, c;
bool vis[N];
vector<int> adj[N];

pair<int, bool> dfs (int v) {
	if (vis[v]) return {0, v == c};
	vis[v] = true;
	bool two = false;
	int qnt = 1;
	for (int u : adj[v]) {
		pair<int, bool> now = dfs (u);
		two = two or now.y;
		qnt += now.x;
	}
	
	return {qnt, two};
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &n, &m, &c);
		for (int i = 1; i <= n; i++)
			adj[i].clear(), vis[i] = false;;
		while (m--) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].push_back (v);
			adj[v].push_back (u);
		}
		
		int ans = 0;
		vis[c] = true;
		for (int u : adj[c]) {
			pair<int, bool> now = dfs (u);
			if (!now.y)
				ans = max (now.x, ans);
		}
		printf ("%d\n", ans);
	}

	return 0;
}
