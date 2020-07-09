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

int n, m;
bitset<N> typ, vis;
vector<int> adj[N];

int dfs (int v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	int ret = typ[v] == 0;
	for (int u : adj[v])
		ret += dfs (u);
	return ret;
}

int main () {
	while (scanf ("%d %d", &n, &m) != EOF) {
		char c;
		for (int i = 1; i <= n; i++) {
			scanf (" %c", &c);
			typ[i] = c == 'A';
			adj[i].clear();
			vis[i] = 0;
		}
		while (m--) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].push_back (v);
			adj[v].push_back (u);
		}
		bool ans = true;
		for (int i = 1; i <= n and ans; i++)
			if (!vis[i])
				ans = ans and (dfs (i)%2 == 0);
		printf ("%s\n", ans ? "Y" : "N");
	}

	return 0;
}
