#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010];
bool arr[1010];

int dfs (int spe) {
	int i, ans = 1;
	for (i = 0; i < adj[spe].size(); i++)
		if (!arr[adj[spe][i]]) {
			arr[adj[spe][i]] = true;
			ans += dfs(adj[spe][i]);
		}
	return ans;
}

int main ()
{
	int n, m, x, y, spe, ans;
	int i;
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (i = 0; i < m; i++) {
			scanf ("%d %d", &x, &y);
			adj[x].push_back(y);
		}
		scanf ("%d", &spe);
		ans = 1;
		arr[spe] = true;
		for (i = 0; i < adj[spe].size(); i++)
			if (!arr[adj[spe][i]]) {
				arr[adj[spe][i]] = true;
				ans += dfs(adj[spe][i]);
			}
		printf ("%d\n", ans);
		for (i = 0; i <= n; i++) {
			adj[i].clear();
			arr[i] = false;
		}
	}
	return 0;
}
