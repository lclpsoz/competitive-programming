#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, m;
int u, v, w;
int adj[101][101][101];

int main ()
{
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++)
				for (int k = 0; k < 101; k++)
					adj[i][j][k] = 1e9;
			adj[i][i][0] = 0;
		}
		while (m--) {
			scanf ("%d %d %d", &u, &v, &w);
			adj[u][v][0] = adj[v][u][0] = min (w, adj[u][v][0]);
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					adj[i][j][k] = min (adj[i][j][k-1],
										adj[i][k][k-1]+adj[k][j][k-1]);

		scanf ("%d", &m);
		while (m--) {
			scanf ("%d %d %d", &u, &v, &w);
			printf ("%d\n", adj[u][v][w] == 1e9 ? -1 : adj[u][v][w]);
		}
	}

	return 0;
}
