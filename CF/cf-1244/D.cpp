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

const ll INF = 1e18;
const int N = 1e5 + 10;

ll dp[N][4][4];
ll mat[N][5];
vector<int> adj[N];
int ans[N];

ll solve (int v, int bef1, int bef2, int p) {
	ll &ret = dp[v][bef1][bef2];
	if (ret != -1) return ret;
	if (adj[v][0] == p and len (adj[v]) == 1) {
		if (bef1 != 1 and bef2 != 1)
			ret = mat[v][1];
		if (bef1 != 2 and bef2 != 2)
			ret = mat[v][2];
		if (bef1 != 3 and bef2 != 3)
			ret = mat[v][3];
		return ret;
	}
	if (adj[v][0] == p) swap (adj[v][0], adj[v][1]);
	ret = INF;
	if (bef1 != 1 and bef2 != 1)
		ret = min (ret, solve (adj[v][0], bef2, 1, v) + mat[v][1]);
	if (bef1 != 2 and bef2 != 2)
		ret = min (ret, solve (adj[v][0], bef2, 2, v) + mat[v][2]);
	if (bef1 != 3 and bef2 != 3)
		ret = min (ret, solve (adj[v][0], bef2, 3, v) + mat[v][3]);

	// printf (" v = %d, bef1 = %d, bef2 = %d\n", v, bef1, bef2);

	return ret;
}

void recu (int v, int bef1, int bef2, int p) {
	ll &ret = dp[v][bef1][bef2];
	// printf ("%d %d %d\n", v, bef1, bef2);
	if (adj[v][0] == p and len (adj[v]) == 1) {
		if (bef1 != 1 and bef2 != 1)
			ans[v] = 1;
		if (bef1 != 2 and bef2 != 2)
			ans[v] = 2;
		if (bef1 != 3 and bef2 != 3)
			ans[v] = 3;
		return;
	}
	if (adj[v][0] == p) swap (adj[v][0], adj[v][1]);
	if (bef1 != 1 and bef2 != 1 and solve (adj[v][0], bef2, 1, v) + mat[v][1] == ret) {
		ans[v] = 1;
		recu (adj[v][0], bef2, 1, v);
	}
	if (bef1 != 2 and bef2 != 2 and solve (adj[v][0], bef2, 2, v) + mat[v][2] == ret) {
		ans[v] = 2;
		recu (adj[v][0], bef2, 2, v);
	}
	if (bef1 != 3 and bef2 != 3 and solve (adj[v][0], bef2, 3, v) + mat[v][3] == ret) {
		ans[v] = 3;
		recu (adj[v][0], bef2, 3, v);
	}

	// printf (" v = %d, bef1 = %d, bef2 = %d\n", v, bef1, bef2);
}

int main () {
	for (int i = 0; i < N;i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				dp[i][j][k] = -1;
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &mat[i][1]);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &mat[i][2]);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &mat[i][3]);
	for (int i = 1; i<n; i++) {
		int u, v;
		scanf ("%d %d", &u, &v);
		adj[u].push_back (v);
		adj[v].push_back (u);
		if (len (adj[u]) == 3 or len (adj[v]) == 3) {
			printf ("-1\n");
			exit (0);
		}
	}
	int st = -1;
	for (int i = 1; i <= n; i++)
		if (len (adj[i]) == 1) {
			st = i;
			break;
		}
	// printf ("st = %d\n", st);

	printf ("%lld\n", solve (st, 0, 0, st));
	recu(st, 0, 0, st);
	for (int i = 1; i <= n; i++)
		printf ("%d ", ans[i]);
	putchar ('\n');

	return 0;
}
