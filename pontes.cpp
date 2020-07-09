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

const int N = 1010, INF = 1e9 + 10;

set<pii> est;
vector<pii> adj[N];
int dist[N];
bitset<N> vis;

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i <= n+1; i++) dist[i] = INF;
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({v, w});
		// adj[v].push_back ({u, w});
	}

	est.insert ({0, 0});
	dist[0] = 0;
	while (!est.empty()) {
		int w = est.begin()->x, v = est.begin()->y;
		est.erase (est.begin());
		// printf ("%d %d\n", v, w);
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto e : adj[v]) {
			w = e.y; int u = e.x;
			if (dist[u] > dist[v] + w) {
				dist[u] = dist[v] + w;
				est.insert ({dist[u], u});
			}
		}
	}

	printf ("%d\n", dist[n+1]);

	return 0;
}
