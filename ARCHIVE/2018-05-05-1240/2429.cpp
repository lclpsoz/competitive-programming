#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

vector<int> dir[MAXN];
vector<int> inv[MAXN];
pair<bool,bool> test[MAXN];

void dfs_dir (int v)
{
	test[v].first = true;
	for (int u : dir[v])
		if (!test[u].first)
			dfs_dir (u);
}

void dfs_inv (int v)
{
	test[v].second = true;
	for (int u : inv[v])
		if (!test[u].second)
			dfs_inv (u);
}

int main ()
{
	int n;
	int a, b;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &a, &b);
		dir[a].push_back (b);
		inv[b].push_back (a);
	}

	dfs_dir (1);
	dfs_inv (1);
	bool ans = true;
	for (int i = 1; i <= n; i++)
		if (!test[i].first || !test[i].second) {
			ans = false;
			break;
		}

	printf ("%c\n", ans ? 'S' : 'N');


	return 0;
}
