#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 2e5+10;

int n, m;
int a, b;
vector<int> adj[MAXN];
char vert[MAXN];

bool dfs (int bef, int v)
{
	// printf (" %d\n", v);
	if (vert[v] == 'W') {
		bool t;
		if (adj[v].size() == 2)
			t = true;
		else
			t = false;
		vert[v] = 'G';
		// printf ("t: %d\n", t);
		if (bef == -1 && adj[v].size())
			t = min (dfs (v, adj[v][0]), t);
		else if (bef != -1)
			for (int u : adj[v])
				if (u != bef)
					t = min (dfs (v, u), t);
		vert[v] = 'B';
		return t;
	} else if (vert[v] == 'G') {
		// printf ("HERE\n");
		if (adj[bef].size() == 2) {
			// printf ("  HERE\n");
			return true;
		}
	} else {
		// printf ("WHY\n");
		return false;
	}
	// printf ("!!!\n");
}

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) vert[i] = 'W';
	while (m--) {
		scanf ("%d %d", &a, &b);
		adj[a].push_back (b);
		adj[b].push_back (a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// printf ("---%d---\n", i);
		// printf ("%d: %c\n", i, vert[i]);
		ans += dfs (-1, i);
		// printf ("%d %d\n", i, ans);
	}

	printf ("%d\n", ans);

	return 0;
}
