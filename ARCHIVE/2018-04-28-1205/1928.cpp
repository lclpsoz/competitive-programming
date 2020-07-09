#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+10;

vector<int> adj[maxn];
bool verif[maxn];
int par[maxn/2];
int link[maxn], size[maxn];
int prof[maxn];
int ans;

int find (int x)
{
	while (x != link[x]) x = link[x];
	return x;
}

bool same (int a, int b)
{
	return find (a) == find (b);
}

void unite (int x, int y)
{
	x = find (x);
	y = find (y);
	if (size[x] > size[y])
		swap (x, y);
	size[x]+=size[y];
	link[y] = x;
}

void bfs ()
{
	queue<int> now, after;
	after.push (1);
	prof[1] = 1;
	int p = 2, y;
	while (!after.empty()) {
		now = after;
		while (!after.empty()) after.pop ();
		while (!now.empty()) {
			y = now.front();
			now.pop();
			for (int x : adj[y]) {
				if (prof[x] == 0) {
					prof[x] = p;
					after.push (x);
				}
			}
		}
		p++;
	}
}

void dfs (int x, int a)
{
	 printf ("\nx: %d\n", x);
	verif[x] = true;
	for (int y : adj[x]) {
		 printf ("  y: %d (%d)", y, x);
		if (y != a) {
			if (verif[par[y]]) {
				printf ("\n%d %d %d ->", y, par[y],link[par[y]]);
				ans += prof[y] + prof[par[y]] - 2*prof[link[par[y]]];
				printf ("%d\n", ans);
			}
			dfs (y, x);
			if (!same (x, y))
				unite (x, y);
		}
	}
}

int main ()
{
	map<int, int> mp;
	int n, x;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		link[i] = i;
		size[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		if (mp[x] == 0)
			mp[x] = i;
		else {
			par[i] = mp[x];
			par[mp[x]] = i;
		}
	}
	int a, b;
	for (int i = 0; i < n-1; i++) {
		scanf ("%d %d", &a, &b);
		adj[a].push_back (b);
		adj[b].push_back (a);
		//printf ("%d %d\n", a, b);
	}

	bfs();
	//for (int i = 1; i <= n; i++)
		//printf ("%d: %d\n", i, prof[i]);
	dfs(1, 1);

	printf ("%d\n", ans);

	return 0;
}
