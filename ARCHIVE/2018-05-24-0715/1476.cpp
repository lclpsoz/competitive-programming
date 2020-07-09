#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN = 2e4+10;
const int MAXL = 19;
const int INF = 1e9;

int n, m, q;
priority_queue<piii> pq;
vector<pii> adj[MAXN];
vector<pii> tree[MAXN];
bool vis[MAXN];

pii anc[MAXN][MAXL]; // {ANCESTOR, MAX. WEIGHT}
int dep[MAXN];

void prim () {
	for (pii p : adj[1])
		pq.push ({p, 1});
	vis[1] = true;
	while (!pq.empty()) {
		piii p = pq.top();
		pq.pop();
		if (vis[p.x.y]) continue;
		vis[p.x.y] = true;

		int w = p.x.x;
		int v = p.x.y;
		int f = p.y;
		tree[v].pb ({w, f});
		tree[f].pb ({w, v});

		for (pii q : adj[v])
			pq.push ({q, v});
	}
}

void dfs (int v, int f, int d, int w) {
	dep[v] = d;
	anc[v][0] = {f, w};
	for (pii p : tree[v])
		if (p.y != f)
			dfs (p.y, v, d+1, p.x);
}

void stAnc () {

	for (int i = 0; i < n; i++)
		for (int j = 1; j < MAXL; j++)
			anc[i][j] = {-1, -1};

	for (int j = 1; j < MAXL; j++)
		for (int i = 1; i <= n; i++)
			if (anc[i][j-1].x != -1) {
				anc[i][j].x = anc[anc[i][j-1].x][j-1].x;
				anc[i][j].y = min (anc[i][j-1].y, anc[anc[i][j-1].x][j-1].y); // To only consider the one bottleneck
			}
}

int lca (int u, int v) {
	int mini = INF;
	if (dep[v] > dep[u]) swap (u, v);

	for (int i = MAXL-1; i >= 0; i--)
		if (dep[u] - (1<<i) >= dep[v]) {
			mini = min (mini, anc[u][i].y);
			u = anc[u][i].x;
		}

	if (u == v) return mini;

	for (int i = MAXL-1; i >= 0; i--)
		if (anc[u][i].x != -1 && anc[u][i].x != anc[v][i].x) {
			mini = min (mini, min (anc[v][i].y, anc[u][i].y));
			u = anc[u][i].x;
			v = anc[v][i].x;
		}

	mini = min (mini, min (anc[v][0].y, anc[u][0].y));
	u = anc[u][0].x;
	v = anc[v][0].x;
	return mini;
}

int main ()
{
	int u, v, w;
	while (scanf ("%d %d %d", &n, &m, &q) != EOF) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			tree[i].clear();
			vis[i] = false;
		}

		for (int i = 0; i < m; i++) {
			scanf ("%d %d %d", &u, &v, &w);
			adj[u].pb ({w, v});
			adj[v].pb ({w, u});
		}

		prim ();
		dfs (1, 1, 0, INF);
		stAnc();
		for (int i = 0; i < q; i++) {
			scanf ("%d %d", &u, &v);
			if (u == v)
				printf ("-1\n");
			else
				printf ("%d\n", lca (u, v));
		}
	}

	return 0;
}
