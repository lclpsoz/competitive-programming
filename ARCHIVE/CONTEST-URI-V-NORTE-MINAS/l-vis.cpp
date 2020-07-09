#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pair<int, pii>> piiii; // DISTANCIA, NULOS, NEGATIVOS, (x, y)

const int INF = 1e9;
const int MAXN = 110;

int n, m, x, y;
int mat[MAXN][MAXN];
int dist[MAXN][MAXN];
bool verif[MAXN][MAXN];
bool vis[MAXN][MAXN];
priority_queue <piiii, vector<piiii>, greater<piiii>> pq;
piiii p;

pii pos (piiii _p)
{
	return _p.second.second;
}

void ins (int i, int j)
{
	if (!vis[i][j]) {
	if (mat[i][j] > 0) {
		if (p.first.first+mat[i][j] < dist[i][j]) {
			pq.push ({{p.first.first+mat[i][j], p.first.second}, {p.second.first, {i, j}}});
			dist[i][j] = p.first.first+mat[i][j];
		}
		// printf ("%d %d %d\n", i, j, dist[i][j]);
	}
	else if (mat[i][j] == 0 && p.first.second < x) {
		if (p.first.first+mat[i][j] < dist[i][j]) {
			pq.push ({{p.first.first+mat[i][j], p.first.second+1}, {p.second.first, {i, j}}});
			dist[i][j] = p.first.first+mat[i][j];
		}
		// printf ("%d %d %d\n", i, j, dist[i][j]);
	}
	else if (mat[i][j] < 0 && p.second.first < y) {
		if (p.first.first+mat[i][j] < dist[i][j]) {
			pq.push ({{p.first.first+mat[i][j], p.first.second}, {p.second.first+1, {i, j}}});
			dist[i][j] = p.first.first+mat[i][j];
		}
		// printf ("%d %d %d\n", i, j, dist[i][j]);
	}
	}
}

int main ()
{
	while (scanf ("%d %d %d %d", &n, &m, &x, &y) != EOF) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf ("%d", &mat[i][j]);
				dist[i][j] = INF;
				vis[i][j] = verif[i][j] = false;
			}

		dist[0][0] = mat[0][0];
		if (mat[0][0] > 0)
			pq.push ({{dist[0][0], 0}, {0, {0, 0}}});
		else if (mat[0][0] == 0 && x > 0)
			pq.push ({{dist[0][0], 1}, {0, {0, 0}}});
		else if (mat[0][0] < 0 && y > 0)
			pq.push ({{dist[0][0], 0}, {1, {0, 0}}});
		else
			dist[0][0] = INF;

		while (!pq.empty ()) {
			p = pq.top(); pq.pop();
			pii p1 = pos(p);
			int i = p1.first;
			int j = p1.second;
			if (verif[i][j]) continue;
			verif[i][j] = true;
			vis[i][j] = true;
			if (i+1 < n)
				ins (i+1, j);
			if (j+1 < m)
				ins (i, j+1);
			if (j-1 >= 0)
				ins (i, j-1);
			printf ("-----\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					printf ("%2d ", dist[i][j]);
				putchar ('\n');
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf ("%2d ", dist[i][j]);
			putchar ('\n');
		}*/

		if (dist[n-1][m-1] == INF)
			printf ("Impossivel\n");
		else
			printf ("%d\n", dist[n-1][m-1]);

	}


	return 0;
}
