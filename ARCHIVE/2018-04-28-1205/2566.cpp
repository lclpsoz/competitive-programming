#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int INF = 1e9;

typedef pair<int, int> pii;

int n, m;
int a, b, t, w;
vector<pii> adj0[MAXN], adj1[MAXN];

int dijkstra (vector<pii> adj[])
{
	priority_queue <pii> pq;
	int dist[n+2];
	bool processed[MAXN];
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		processed[i] = false;
	}
	pq.push ({0, 1});
	dist[1] = 0;
	while (!pq.empty()) {
		int v = pq.top().second;
		// printf ("%d %d\n", w, v);
		pq.pop ();
		if (processed[v]) continue;
		processed[v] = true;
		for (pii x : adj[v]) {
			int w = x.first, b = x.second;
		    if (dist[v]+w < dist[b]) {
		        dist[b] = dist[v]+w;
    			pq.push ({-dist[b], b});
		    }
		}
	}

	return dist[n];
}

int main ()
{
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			adj0[i].clear ();
			adj1[i].clear ();
		}
		while (m--) {
			scanf ("%d %d %d %d", &a, &b, &t, &w);
			if (t)
				adj1[a].push_back({w, b});
			else
				adj0[a].push_back({w, b});
		}
		printf ("%d\n", min (dijkstra (adj0), dijkstra (adj1)));
	}

	return 0;
}
