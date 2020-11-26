#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Loroot down for solution. ////////////////
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

const int N = 3e5 + 10;

int t, n;
vector<int> adj[N];
int dp[N][2];

int solve (int v, int p, bool root) {
	// printf ("  v = %d, p = %d\n", v, p);
	int &ret = dp[v][root];
	if (ret != -1) return ret;
	if (len (adj[v]) == 1 and adj[v][0] == p) return ret = 0;
	// printf ("  here!\n");
	ret = 0;
	if (root) {
		for (int u : adj[v])
			if (u != p)
				solve (u, v, false);
			
		sort (adj[v].begin(), adj[v].end(), [&](int x, int y) {
			if (p == x) return false;
			if (p == y) return true;
			return dp[x][0] > dp[y][0];
		});
		ret += len (adj[v]);
		ret += dp[adj[v][0]][0];
		if (len (adj[v]) > 1 and adj[v][1] != p)
			ret += dp[adj[v][1]][0];

		// Pass "root"
		int pass = 0;
		for (int u : adj[v])
			if (u != p)
				solve (u, v, true);
			
		sort (adj[v].begin(), adj[v].end(), [&](int x, int y) {
			if (p == x) return false;
			if (p == y) return true;
			return dp[x][1] > dp[y][1];
		});
		pass = dp[adj[v][0]][1];
		// printf ("v = %d, root = %d, ret = %d, take1 =  %d\n", v, root, ret, pass);

		ret = max (ret, pass);
	}
	else {
		for (int u : adj[v])
			if (u != p)
				solve (u, v, false);
		sort (adj[v].begin(), adj[v].end(), [&](int x, int y) {
			if (p == x) return false;
			if (p == y) return true;
			return dp[x][0] > dp[y][0];
		});
		ret += dp[adj[v][0]][0] + len(adj[v]) - 1;
	}

	return ret;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			dp[i][0] = dp[i][1] = -1;
		}
		for (int i = 0; i < n-1; i++) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].push_back (v);
			adj[v].push_back (u);
		}

		int mx = 0, st = 1;
		for (int i = 1; i <= n; i++)
			if (len (adj[i]) > mx) mx = len (adj[i]), st = i;

		int ans = solve (mx, -1, true) + 1;

		// for (int i = 1; i <= n; i++)
		// 	printf ("dp[%d] = {%d, %d}\n", i, dp[i][0], dp[i][1]);
		
		// for (int i = 1; i <= n; i++) {
		// 	if (len (adj[i]) == 1) continue;
		// 	// memset (dp, -1, sizeof dp);
		// 	for (int j = 1; j <= n; j++) dp[j][0] = dp[j][1] = -1;
		// 	int now = solve (i, -1, true) + 1;
		// 	// printf ("%d: %d\n", i, now);
		// 	assert (ans == now);
		// }
		printf ("%d\n", ans);
	}

	return 0;
}
