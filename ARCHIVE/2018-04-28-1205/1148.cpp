#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 510;
const int INF = 1e9;

int n, e;
int k;
vector<pii> adj[MAXN];
int dist[MAXN];
priority_queue<pii> pq;
bool verif[MAXN];

void dijkstra (int st)
{
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		verif[i] = false;
	}
	pq.push ({0, st});
	int a, b, w;
	bool bic = false;
	// printf ("______________\n");
	// printf ("FROM %d:\n", st);
	dist[st] = 0;
	while (!pq.empty ()) {
		a = pq.top().second;
		w = pq.top().first;
		pq.pop();
		// printf ("TRY! %d %d\n", a, w);
		if (verif[a]) continue;
		verif[a] = true;
		// printf ("OK! %d %d\n", a, w);
		for (pii x : adj[a]) {
			b = x.second;
			w = x.first;
			if (dist[a]+w < dist[b]) {
				dist[b] = dist[a]+w;
				pq.push ({-dist[b], b});
			}
		}
	}
	// printf ("______________\n");
}

int main ()
{
	int a, b, w;
	while (scanf ("%d %d", &n, &e), n || e) {
		for (int i = 1; i <= n; i++)
			adj[i].clear ();
		bool bic = false;
		while (e--) {
			scanf ("%d %d %d", &a, &b, &w);
			for (int i = 0; i < adj[b].size(); i++)
				if (adj[b][i].second == a) {
					bic = true;
					adj[b][i].first = 0;
					break;
				}
			if (bic) w = 0;
			bic = false;
			adj[a].push_back ({w, b});
		}
		vector<pii> vec;
		scanf ("%d", &e);
		while (e--) {
			scanf ("%d %d", &a, &b);
			vec.push_back ({a, b});
		}
		// sort (vec.begin(), vec.end());
		int bef = 0;
		for (pii p : vec) {
			// printf ("-----|%d %d|-----\n", p.first, p.second);
			if (p.first != bef) {
				bef = p.first;
				dijkstra (bef);
			}
			dist[p.second] == INF ? printf ("Nao e possivel entregar a carta\n") : printf ("%d\n", dist[p.second]);
		}
		putchar ('\n');
	}

	return 0;
}
