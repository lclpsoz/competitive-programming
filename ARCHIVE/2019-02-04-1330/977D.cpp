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

const int N = 105;

int n;
vector<int> adj[N];
ll a[N], ans[N];
bool vis[N];

void dfs (int v, int p) {
	if (vis[v]) return;
	vis[v] = true;
	if (p == n-1) {
		ans[p] = a[v];
		for (int j = 0; j < n; j++)
			printf ("%lld%c", ans[j], " \n"[j==n-1]);
		exit (0);
	}
	for (int u : adj[v]) {
		ans[p] = a[v];
		dfs (u, p+1);
	}
	vis[v] = false;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%lld", &a[i]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] == a[j]*3 or a[i]*2 == a[j])
				adj[i].push_back (j);
			
	for (int i = 0; i < n; i++)
		dfs (i, 0);

	return 0;
}
