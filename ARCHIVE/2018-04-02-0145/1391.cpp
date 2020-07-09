#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int, pair<int, vector<piii>>> piiv;

const int MAXN = 505;
const int INF = 1e9;

int n, m;
int st, en;
int a, b, w;
list<pii> adj[MAXN];
int d_short;

int dijkstra ()
{
	int dist[n];
	pii path[n];
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	int v = st;
	pq.push ({0, v});
	while (!pq.empty () && dist[en] == INF) {
		w = pq.top().first;
		v = pq.top().second;
		// printf ("%d [%d]\n", v, w);
		pq.pop ();
		if (dist[v] < INF) continue;
		dist[v] = w;
		if (v == en)
			break;
		for (pii x : adj[v]) {
			if (dist[v]+x.first < dist[x.second]) {
				path[x.second] = {x.first, v}; // weight, origin vertice
				pq.push ({w+x.first, x.second});
			}
		}
	}

	if (dist[en] != INF) {
		int i = en;
		while (i != st) {
			pii aux = path[i];
			adj[aux.second].remove ({aux.first, i});
			i = aux.second;
		}
	}
	return dist[en] == INF ? -1 : dist[en];
}

int main ()
{
	while (scanf ("%d %d", &n, &m), n || m) {
		scanf ("%d %d", &st, &en);
		while (m--) {
			scanf ("%d %d %d", &a, &b, &w);
			adj[a].push_back ({w, b});
		}

		// printf ("__________________________________________________\n");
		// printf ("%d\n", dijkstra ());
		int d;
		d = d_short = dijkstra ();
		while (d == d_short && d != -1)
			d = dijkstra ();
		printf ("%d\n", d);
		// printf ("__________________________________________________\n");
		for (int i = 0; i < n; i++)
			adj[i].clear ();
	}

	return 0;
}
