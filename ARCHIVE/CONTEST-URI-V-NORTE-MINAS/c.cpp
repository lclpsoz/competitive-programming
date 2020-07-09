#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
const int INF = 1e9;
typedef pair<int, int> pii;

int n;
int e1, e2, x1, x2, w;
vector<pii> adj[MAXN];
priority_queue <pii, vector<pii>, greater<pii>> pq;
int dist[MAXN];
bool verif[MAXN];
int vert[MAXN];

int main ()
{
	while (scanf ("%d", &n) != EOF) {

		for (int i = 0; i <= n+n+10; i++) {
			adj[i].clear();
			dist[i] = INF;
			verif[i] = false;
			vert[i] = 0;
		}


		scanf ("%d %d", &e1, &e2);
		// Esteira SUPERIOR
		for (int i = 1; i <= n; i++)
			scanf ("%d", &vert[i]);

		adj[0].push_back ({e1+vert[1], 1});
		for (int i = 1; i < n; i++)
			adj[i].push_back ({vert[i+1], i+1});

		// Esteira INFERIOR
		for (int i = n+1; i <= n+n; i++)
			scanf ("%d", &vert[i]);

		adj[0].push_back ({e1+vert[n+1], n+1});
		for (int i = n+1; i < n+n; i++)
			adj[i].push_back ({vert[i+1], i+1});

		// Esteira SUPERIOR pra INFERIOR
		for (int i = 1; i < n; i++) {
			scanf ("%d", &w);
			adj[i].push_back ({w+vert[n+1+i], n+1+i});
		}

		// Esteira INF -> SUP
		for (int i = n+1; i < n+n; i++) {
			scanf ("%d", &w);
			adj[i].push_back ({w+vert[n+1+i], i-n});
		}


		scanf ("%d %d", &x1, &x2);
		adj[n].push_back ({x1, n+n+1});
		adj[n+n].push_back ({x2, n+n+1});
		/*for (int i = 0; i <= n+n; i++) {
			printf ("%d: ", i);
			for (auto z : adj[i])
				printf ("%d [%d] ", z.second, z.first);
			putchar ('\n');
		}*/

		dist[0] = 0;
		pq.push ({0, 0});
		while (!pq.empty()) {
			int a = pq.top().second; pq.pop();
			if (verif[a]) continue;
			verif[a] = true;
			for (auto u : adj[a]) {
				int b = u.second, w = u.first;
				if (dist[a]+w < dist[b]) {
					dist[b] = dist[a]+w;
					pq.push ({dist[b], b});
				}
			}
		}
		/*printf ("%d\n", dist[0]);
		for (int i = 1; i <= n+1; i++)
			printf ("%d ", dist[i]);
		putchar ('\n');
		for (int i = n+2; i <= n+n+2; i++)
			printf ("%d ", dist[i]);
		putchar ('\n');*/
		printf ("%d\n", dist[n+n+1]);

	}

	return 0;
}
