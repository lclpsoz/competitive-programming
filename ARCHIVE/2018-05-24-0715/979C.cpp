#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 3e5+10;

int n, x, y;
vector<int> adj[MAXN];
int subFlow[MAXN]; // Raiz conta
int subBee[MAXN]; // Raiz conta

int dfs (int arr[], int v, int f) {
	arr[v] = 1;
	for (int u : adj[v])
		if (u != f)
			arr[v] += dfs (arr, u, v);
	return arr[v];
}

int main ()
{
	int u, v;
	scanf ("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n-1; i++) {
		scanf ("%d %d", &u, &v);
		adj[u].pb (v);
		adj[v].pb (u);
	}

	long long ans = (1LL*n)*(n-1);

	// From Flowrisa
	subFlow[x] = dfs (subFlow, x, x);
	// From Beetopia
	subBee[y] = dfs (subBee, y, y);

	// printf ("%d %d\n", subFlow[y], subBee[y]);
	long long fl, be, aux;
	fl = subFlow[x]-subFlow[y];
	be = subBee[y]-subBee[x];
	aux = fl+be-n; // Between
	fl -= aux;
	be -= aux;
	// printf ("%lld %lld %lld\n", fl, be, aux);
	ans -= (fl*be);

	printf ("%lld\n", ans);

	return 0;
}
