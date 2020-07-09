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

using pp = pair<int, pii>;

const int N = 1e3+10;
const int INF = 1e9;

int n, m, q;
int dist[N][N];
vector<pii> adj[N];

void dijkstra () {
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dist[i][j] = INF;
	dist[1][0] = 0;
	priority_queue<pp, vector<pp>, greater<pp>> pq;
	pq.push ({0, {0, 1}});
	while (!pq.empty()) {
		int cost = pq.top().x;
		int k = pq.top().y.x;
		int u = pq.top().y.y;
		pq.pop();
		if (dist[u][k] < cost)
			continue;
		for (auto e : adj[u]) {
			int v = e.x;
			int w = e.y;
			if (dist[v][k+1] > cost + w) {
				dist[v][k+1] = cost + w;
				pq.push ({dist[v][k+1], {k+1, v}});
			}
		}
	}
}

int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int a, b, cost;
		scanf ("%d %d %d", &a, &b, &cost);
		adj[a].push_back ({b, cost});
	}
	
	dijkstra ();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = min (dist[i][j], dist[i][j-1]);
	
	scanf ("%d", &q);
	while (q--) {
		int d, k;
		scanf ("%d %d", &d, &k);
		k += 1;
		
		if (dist[d][k] == INF)
			printf ("=[\n");
		else
			printf ("=] %d\n", dist[d][k]);
	}

	return 0;
}
