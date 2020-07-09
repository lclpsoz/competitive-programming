#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, e;
int a, b, p;
int m;
int adj[505][505];
bool verif[505];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main ()
{
	while (scanf ("%d %d", &n, &e), n || e) {
		for (int i = 0; i <= n; i++) {
			verif[i] = false;
			for (int j = 0; j <= n; j++)
				adj[i][j] = 0;
		}
		while (e--) {
			scanf ("%d %d %d", &a, &b, &p);
			adj[a][b] = p;
		}
		scanf ("%d", &m);
		while (m--) {
			scanf ("%d %d", &a, &b);
			pq.push ({0, a});
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (adj[i][j] < 0)
						adj[i][j] *= -1;
			while (!pq.empty () && pq.top().second != b) {
				pii x = pq.top();
				pq.pop ();
				for (int i = 1; i <= n; i++) {
					// printf ("bef: %d %d: %d\n", x.second, i, adj[x.second][i]);
					if (adj[x.second][i] > 0) {
						if (adj[i][x.second])
							pq.push ({x.first, i});
						else
							pq.push ({(x.first + adj[x.second][i]), i});
						adj[x.second][i] *= -1;
					}
					// printf ("aft: %d %d: %d\n", x.second, i, adj[x.second][i]);
				}
			}
			pq.empty () ? printf ("Nao e possivel entregar a carta\n") : printf ("%d\n", pq.top().first);
			while (!pq.empty())
				pq.pop();
		}
		putchar ('\n');
	}

	return 0;
}
