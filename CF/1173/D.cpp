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

const int MOD = 998244353;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

int n;
int sz[N];
ll ans = 1;
vector<int> adj[N];

int dfs (int v, int p) {
	int &ret = sz[v];
	ret ++;
	for (int u : adj[v])
		if (u != p)
			ret += dfs (u, v);
	return ret;
}

int fact (int x) {
	int ret = 1;
	while (x > 1) {
		ret = (ret * 1LL * x)%MOD;
		x--;
	}
	return ret;
}

void solve (int v, int p) {
	if (sz[v] == 1) return;
	int total = sz[v] - (p == v);
	for (int u : adj[v]) {
		if (u != p) {
			solve (u, v);
			total -= sz[u]-1;
		}
	}
	// printf ("%d: %d\n", v, total);
	ans = (ans *1LL* fact (total))%MOD;
	// printf (" v = %d, ans = %d\n", v, ans);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int u, v;
		scanf ("%d %d", &u, &v);
		adj[u].push_back (v);
		adj[v].push_back (u);
	}

	int root = 1;
	// for (int root = 1; root <= n; root++) {
		memset (sz, 0, sizeof sz);
		dfs (root, root);
		// for (int i = 1; i <= n; i++)
		// 	printf ("%d: %d\n", i, sz[i]);
		ans = 1;
		solve (root, root);
		printf ("%lld\n", (n*1LL*ans)%MOD);
	// }

	return 0;
}
