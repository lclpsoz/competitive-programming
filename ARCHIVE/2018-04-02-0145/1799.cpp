#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int v, a;
int x1, x2;
char arr1[110], arr2[110];
string str;
unordered_map<string, int> mp;
vector<int> adj[4010];
int dist[4010];

int bfs (int st, int en)
{
	for (int i = 1; i <= v; i++)
		dist[i] = 0;
	queue<pii> q;
	int ans = 0;
	// {distance, vertice}
	q.push ({0, st});
	// printf ("-----\n");
	while (!q.empty ()) {
		int d = q.front().first;
		int vert = q.front().second;
		// printf ("%3d %3d\n", vert, d);
		q.pop ();
		if (dist[vert]) continue;
		dist[vert] = d;
		for (int x : adj[vert]) {
			if (!dist[x]) {
				// printf ("    %d -> %d\n", vert, x);
				q.push ({d+1, x});
			}
		}
	}

	return dist[en];
}

int main ()
{
	scanf ("%d %d", &v, &a);
	str = "Entrada";
	mp[str] = 1;
	str = "Saida";
	mp[str] = v;
	int i = 2;
	while (a--) {
		scanf ("%s %s", arr1, arr2);
		str = arr1;
		if (!mp[str])
			mp[str] = i++;
		x1 = mp[str];
		str = arr2;
		if (!mp[str])
			mp[str] = i++;
		x2 = mp[str];
		adj[x1].push_back (x2);
		adj[x2].push_back (x1);
		// printf ("%2d %2d\n", x1, x2);
	}

	// printf ("----\n");
	str = "*";
	printf ("%d\n", bfs (1, mp[str])+bfs (mp[str], v));

	return 0;
}
