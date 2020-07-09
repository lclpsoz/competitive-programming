#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 2010;

bool check[MAXN];
int n, m;

void dfs (int v, vector<int> *adj) {
	check[v] = true;
	for (int u : adj[v])
		if (!check[u])
			dfs (u, adj);
}

int main ()
{
	vector<int> adj[MAXN];
	vector<int> adj_r[MAXN];
	int a, b, t;
	while (scanf ("%d %d", &n, &m), n || m) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			adj_r[i].clear();
		}
		while (m--) {
			scanf ("%d %d %d", &a, &b, &t);
			adj[a].pb (b);
			adj_r[b].pb (a);
			if (t == 2) {
				adj[b].pb (a);
				adj_r[a].pb (b);
			}
		}

		bool ans = true;
		dfs (1, adj);
		for (int i = 1; i <= n; i++) {
			if (!check[i])
				ans = false;
			check[i] = false;
		}
		if (ans) {
			dfs (1, adj_r);
			for (int i = 1; i <= n; i++) {
				if (!check[i])
					ans = false;
				check[i] = false;
			}
			if (ans)
				printf ("1\n");
			else
				printf ("0\n");
		} else
			printf ("0\n");
	}

	return 0;
}
