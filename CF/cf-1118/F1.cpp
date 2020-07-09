#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 3e5+10;

int n;
int a[N];
int red[N];
int blue[N];
vector<int> adj[N];
int ans = 0;

void proc (int v, int p) {
	if (a[v] == 1) ++red[v];
	else if (a[v] == 2) ++blue[v];
	for (int u : adj[v])
		if (u != p) {
			proc (u, v);
			red[v] += red[u];
			blue[v] += blue[u];
		}
}

void dfs (int v, int p) {
	for (int u : adj[v])
		if (u != p) {
			dfs (u, v);
// 			printf ("v: %d, u: %d, red[u]: %d, blue[u]: %d\n", v, u, red[u], blue[u]);
			if ((blue[u] == 0 or red[u] == 0) and (blue[1]-blue[u] == 0 or red[1]-red[u] == 0)) {
// 				printf ("Y\n");
				++ans;
			}
		}
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (int i = 0; i < n-1; i++) {
		int u, v;
		scanf ("%d %d", &u, &v);
		adj[u].push_back (v);
		adj[v].push_back (u);
	}
	
	proc (1, 1);
	dfs (1, 1);
	
	printf ("%d\n", ans);

	return 0;
}
