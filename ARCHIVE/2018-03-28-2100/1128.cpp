// If the DFS starts at ANY vertice, it needs to form a cycle throught ALL vertices, that way the graph is strong connected
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+10;

char vert[MAXN]; // 'W', 'G', 'B'
vector<int> adj[MAXN];

void dfs (int x)
{
	vert[x] = 'G';
	for (int v : adj[x]) {
		if (vert[v] == 'W')
			dfs(v);
	}
}

int main ()
{
	int n, m;
	int a, b, t;
	while (scanf ("%d %d", &n, &m), n || m) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			vert[i] = 'W';
		}
		while (m--) {
			scanf ("%d %d %d", &a, &b, &t);
			adj[a].push_back(b);
			if (t == 2)
				adj[b].push_back(a);
		}
		dfs (1);
		for (int i = 1; i <= n; i++)
			if (vert[i] != 'G')

	}

	return 0;
}
