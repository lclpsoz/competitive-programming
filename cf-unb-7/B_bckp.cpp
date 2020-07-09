#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int INF = 1e9 + 100;
const int N = 505;

int n, m;
int adj[N][N];
int link[N], sz[N];

bool vis[N], tin[N], low[N];
int timer;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
	for (int u = 1; u <= n; u++) {
        if (adj[v][u] == INF or u == p) continue;
		printf ("v = %d u = %d\n", v, u);
        if (vis[u]) {
            low[v] = min(low[v], tin[u]);
        } else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) {
				printf ("YES!\n");
                adj[v][u] = adj[u][v] = adj[u][v]*2;
			}
        }
    }
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			adj[i][j] = INF;
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u][v] = adj[v][u] = w;
	}

	memset (tin, -1, sizeof tin);
	memset (low, -1, sizeof low);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);

	int x, y;
	scanf ("%d %d", &x, &y);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			printf ("%12d%c", adj[i][j], " \n"[j==n]);
		}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][k] and adj[k][j])
						adj[i][j] = adj[j][i] = min (adj[i][j], adj[i][k] + adj[k][j]);

	printf ("%d\n", adj[x][y]);

	return 0;
}
