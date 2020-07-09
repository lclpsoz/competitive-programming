#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<long long, long long> pii;

const int MAXN = 1e5+10;
const int MAXL = 20;

int n;
int q, s, t;
pii anc[MAXL][MAXN];
int depth[MAXN];
vector<pii> adj[MAXN];

void dfs (int v, int f, int d, int w) {
	depth[v] = d;
	anc[0][v] = {f, w};
	for (pii u : adj[v])
		if (u.x != f)
			dfs (u.x, v, d+1, u.y);
}

// pai[MAXN] ja havia sido salvo em
// anc[0][v].
void fillAnc () {
	for (int i = 1; i < MAXL-1; i++)
		for (int j = 0; j < n; j++)
			anc[i][j] = {-1, -1};

	for (int i = 1; i < MAXL-1; i++)
		for (int j = 0; j < n; j++)
			if (anc[i-1][j].x != -1) {
				anc[i][j].x = anc[i-1][ anc[i-1][j].x ].x;
				anc[i][j].y = anc[i-1][j].y + anc[i-1][ anc[i-1][j].x ].y;
			}
}

long long lca (int u, int v) {
	long long path = 0;

	if (depth[v] > depth[u]) swap (u, v);

	for (int i = MAXL-1; i >= 0; i--)
		if (depth[u]-(1<<i) >= depth[v]) {
			path += anc[i][u].y;
			u = anc[i][u].x;
		}

	// printf (">>\n");
	if (u == v) return path;
	// printf ("<<\n");

	for (int i = MAXL-1; i >=0; i--)
		if (anc[i][u].x != -1 && anc[i][u].x != anc[i][v].x) {
			path += anc[i][u].y + anc[i][v].y;
			u = anc[i][u].x;
			v = anc[i][v].x;
		}

	path += anc[0][u].y+anc[0][v].y;

	return path;
}

int main ()
{
	while (scanf ("%d", &n), n) {
		for (vector<pii> &vv : adj)
			vv.clear();
		for (int i = 1; i < n; i++) {
			scanf ("%d %d", &s, &t);
			adj[i].pb ({s, t});
			adj[s].pb ({i, t});
		}
		dfs (0, 0, 0, 0);
		/*for (int i = 0; i < 20; i++) {
			for (int j = 0; j < n; j++)
				printf ("[%lld %lld] ", anc[i][j].x, anc[i][j].y);
			putchar ('\n');
		}
		printf ("________________\n");*/
		fillAnc ();
		/*for (int i = 0; i < 20; i++) {
			for (int j = 0; j < n; j++)
				printf ("[%lld %lld] ", anc[i][j].x, anc[i][j].y);
			putchar ('\n');
		}
		printf ("=================\n");*/
		scanf ("%d", &q);
		while (q--) {
			scanf ("%d %d", &s, &t);
			printf ("%lld", lca (s, t));
			if (q)
				putchar (' ');
		}
		putchar ('\n');
	}

	return 0;
}
