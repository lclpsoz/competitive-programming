#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;
const int INF = 1e9;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int c, v;
int a, b, d, p;
vector<pii> adj[MAXN];

int djikstra ()
{
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	int dist[MAXN][2];
	for (int i = 0; i <= c; i++)
		dist[i][0] = dist[i][1] = INF;
	dist[1][0] = 0;

	// {DIST, {PARITY, CITY}}
	pq.push ({0, {0, 1}});
	while (!pq.empty ()) {
		piii aux = pq.top();
		d = aux.first;
		p = aux.second.first;
		a = aux.second.second;
		pq.pop();
		if (d > dist[a][p]) continue;

		for (pii x : adj[a]) {
			if ((d+x.first) < dist[x.second][!p]) {
				pq.push ({d+x.first, {!p, x.second}});
				dist[x.second][!p] = d+x.first;
			}
		}
	}

	return dist[c][0] == INF ? -1 : dist[c][0];
}

int main ()
{
	scanf ("%d %d", &c, &v);
	while (v--) {
		scanf ("%d %d %d", &a, &b, &d);
		adj[a].push_back ({d, b});
		adj[b].push_back ({d, a});
	}

	printf ("%d\n", djikstra ());

	return 0;
}
