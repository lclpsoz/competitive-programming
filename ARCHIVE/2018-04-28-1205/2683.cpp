// Minimum and maximum spanning trees using Prim's algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;

typedef pair<int,int> pii;

int n;
int u, v, w, st, ans;
vector<pii> adj[MAXN];
bool verif[MAXN];
/*int link[MAXN], size[MAXN];

int find (int x)
{
	while (x != link[x])
		x = link[x];
	return x;
}

bool same (int x, int y)
{
	return find (x) == find (y);
}

void unite (int x, int y)
{
	x = find (x);
	y = find (y);
	if (size[x] > size[y])
		swap (x, y);
	size[y] += size[x];
	link[x] = y;
}*/

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({w, v});
		adj[v].push_back ({w, u});
	}
	st = u;
	//Maximum spanning tree
	priority_queue<pii> maxi;
	maxi.push({0, st});
	verif[st] = true;
	ans = 0;
	while (!maxi.empty ()) {
		u = maxi.top().second;
		w = maxi.top().first;
		maxi.pop();
		ans += w;
		verif[u] = true;
		for (pii x : adj[u])
			maxi.push({x.first, x.second});
		while (!maxi.empty() && verif[maxi.top().second]) maxi.pop();
	}
	printf ("%d\n", ans);
	
	// Minimum spanning tree
	for (int i = 1; i <= 1000; i++) verif[i] = false;
	priority_queue<pii, vector<pii>, greater<pii>> mini;
	mini.push({0, st});
	ans = 0;
	while (!mini.empty ()) {
		u = mini.top().second;
		w = mini.top().first;
		mini.pop();
		ans += w;
		verif[u] = true;
		
		for (pii x : adj[u])
			mini.push({x.first, x.second});
		while (!mini.empty() && verif[mini.top().second]) mini.pop();
	}
	printf ("%d\n", ans);
	
	
	return 0;
}
