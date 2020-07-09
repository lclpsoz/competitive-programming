#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;
const int INF = 1e9;

int n, m;
priority_queue<pii> pq;
int dist[MAXN];
bool vis[MAXN];
int a, b, w;
vector<pii> adj[MAXN];

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		dist[n] = INF;

	while (m--) {
		scanf ("%d %d %d", &a, &b, &w);
		adj[a].pb ({w, b});
		adj[b].pb ({w, a});
	}

	pq.push ({0, 1});
	for (pii p : adj[1])
		if (p.y == 1)
			pq.push ({p.x, 1});
	dist[1] = 0;
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		// printf ("%d %d\n", p.x, p.y);
		for (pii q : adj[p.y]) {
			// printf ("%d\n", dist[p.y]^q.x);
			if (dist[p.y]^q.x <= dist[q.y]) {
				dist[q.y] = dist[p.y]^q.x;
				pq.push ({-dist[q.y], q.y});
			}
		}
	}

	printf ("%d\n", dist[n]);

	return 0;
}
