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

const int N = 1e3 + 10, INF = 1e9 + 10;

vector<pair<int, int>> adj[N]; // {PESO, VERTICE ADJANCE}
bitset<N> vis;
int dist[N];
set<pair<int, int>> esq; // {PESO, VERTICE ATUAL}

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({w, v});
		adj[v].push_back ({w, u});
	}

	for (int i = 0; i <= n+1; i++)
		dist[i] = INF;

	esq.insert ({0, 0});
	dist[0] = 0;
	while (!esq.empty()) {
		int v = esq.begin()->second;
		int w = esq.begin()->first;
		esq.erase (esq.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (pii e : adj[v]) {
			w = e.first;
			int u = e.second;
			if (dist[u] > dist[v] + w) {
				dist[u] = dist[v] + w;
				esq.insert ({dist[u], u});
			}
		}
	}
	printf ("%d\n", dist[n+1]);

	return 0;
}
