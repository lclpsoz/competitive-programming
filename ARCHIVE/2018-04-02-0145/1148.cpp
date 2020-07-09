#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, e;
int a, b, p;
int m;
int adj[505][505];
bool verif[505];
priority_queue<pii> pq;

int main ()
{
	while (scanf ("%d %d", &n, &e), n || e) {
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				adj[i][j] = INT_MAX;
		while (e--) {
			scanf ("%d %d %d", &a, &b, &p);
			if (adj[b][a] < INT_MAX)
				adj[a][b] = adj[b][a] = 0;
			else
				adj[a][b] = p;
		}
		scanf ("%d", &m);
		while (m--) {
			scanf ("%d %d", &a, &b);
			for (int i = 1; i <= n; i++)
				verif[i] = false;
			pq.push ({0, a});
			while (!pq.empty () && pq.top().second != b) {
				p = pq.top().first; // weight
				a = pq.top().second;// vertice
				if (verif[a]) continue;
				verif[a] = true;
				pq.pop ();
				for (int i = 1; i <= n; i++)
					if (adj[a][i] < INT_MAX)
						pq.push ({p-adj[a][i], i});
			}
			pq.empty () ? printf ("Nao e possivel entregar a carta\n") : printf ("%d\n", -pq.top().first);
			while (!pq.empty())
				pq.pop();
		}
		putchar ('\n');
	}

	return 0;
}
