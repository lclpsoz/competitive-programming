#include <bits/stdc++.h>
using namespace std;

int t, n, v, e, a, b, ans;
vector <int> adj[100];
bool aux[70];

void dfs (int vert)
{
	// printf ("\t%d\n", vert);
	aux[vert] = true;
	for (int i : adj[vert]) {
		if (!aux[i]) {
			ans++;
			dfs (i);
		}
	}

}

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d %d %d", &n, &v, &e);
		for (int j = 0; j < e; j++) {
			scanf ("%d %d", &a, &b);
			adj[a].push_back (b);
			adj[b].push_back (a);
		}
		dfs (n);
		printf ("%d\n", ans<<1);
		for (int j = 0; j <= v; j++) {
			aux[j] = false;
			adj[j].clear ();
		}
		ans = 0;
	}

	return 0;
}
