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
ll adj[N][N];
int link[N], sz[N];
set<pii> bridges;

vector<int> adjV[N]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
	// printf ("%d %d\n", v, p);
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adjV[v]) {
		// printf ("|%d %d\n", v, to);
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
				int x = v, y = to;
				if (x > y) swap (x, y);
				bridges.insert ({x, y});
			}
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			adj[i][j] = INF;
			adj[i][i] = 0;
		}
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		// printf ("|%d %d\n", u, v);
		assert (adj[u][v] == INF);
		adj[u][v] = adj[v][u] = min (adj[v][u], (ll)w);
		adjV[u].push_back (v);
		adjV[v].push_back (u);
	}

	find_bridges ();


	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= n; j++) {
	// 		printf ("%12d%c", adj[i][j], " \n"[j==n]);
	// 	}

	for (pii p : bridges) {
		ll w = adj[p.x][p.y];
		adj[p.x][p.y] = adj[p.y][p.x] = 2*w;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][k] != INF and adj[k][j] != INF)
						adj[i][j] = adj[j][i] = min (adj[i][j], adj[i][k] + adj[k][j]);

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= n; j++) {
	// 		printf ("%d, %d: %12d%c", i, j, adj[i][j], "\n\n"[j==n]);
	// 	}

	int x, y;
	scanf ("%d %d", &x, &y);
	// printf ("x, y = %d %d\n", x, y);

	printf ("%lld\n", adj[x][y]);

	return 0;
}
