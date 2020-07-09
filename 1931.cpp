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

const int INF = 1e9 + 10;
const int N = 1e4 + 100;

int n, m;
vector<pii> adj[N];
set<pair<int, pii>> st;
bool vis[N][2];
int dist[N][2];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		dist[i][0] = dist[i][1] = INF;
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({v, w});
		adj[v].push_back ({u, w});
	}
	dist[1][0] = 0;
	st.insert ({0, {1, 0}});
	while (!st.empty()) {
		int v = st.begin()->y.x;
		int p = st.begin()->y.y;
		st.erase (st.begin());
		if (vis[v][p]) continue;
		for (auto pp : adj[v]) {
			int u = pp.x;
			int w = pp.y;
			if (dist[u][!p] > dist[v][p] + w) {
				dist[u][!p] = dist[v][p] + w;
				st.insert ({dist[u][!p], {u, !p}});
			}
		}
	}
	if (dist[n][0] == INF) printf ("-1\n");
	else printf ("%d\n", dist[n][0]);

	return 0;
}
