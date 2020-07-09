// Minimum spanning tree by Prim's [ADAPTED TO MINIMUM VISIBLE PATHS]
#include <bits/stdc++.h>
using namespace std;

int t;
int n, v;
int a, b;
bool verif[105];
int adj[105][105];
priority_queue <pair<int, int>> pq;

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &v);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				adj[i][j] = false;
			verif[i] = false;
		}
		while (v--) {
			scanf ("%d %d", &a, &b);
			// printf ("||%d %d\n", a, b);
			adj[a][b] = true;
			adj[b][a] = true;
		}
		// Choose a vertice (0) and put
		// all edges in the priority_queue
		verif[0] = true;
		for (int i = 1; i < n; i++) {
			pq.push ({!adj[0][i], i});
			// printf (">>%d %d\n", !adj[0][i], i);
		}
		int ans = 0;
		while (!pq.empty()) {
			a = pq.top().second;
			int state = !pq.top().first;
			pq.pop();
			if (verif[a]) continue;
			// printf ("%d %d\n", state, a);

			if (state) ans++;
			verif[a] = true;
			for (int i = 0; i < n; i++)
				if (!verif[i])
					pq.push ({!adj[a][i], i});
		}
		printf ("%d\n", ans);
	}

	return 0;
}
