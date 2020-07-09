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

const int N = 1e5+10;

int n, m;
vector<int> adj[N];
int dp[N];

int solve (int v) {
	int &r = dp[v];
	if (r != -1) return r;
	r = 0;
	for (int u : adj[v])
		r = max (r, solve (u) + 1);
	
	return r;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		adj[x].push_back (y);
	}
	
	int ans = -1;
	for (int i = 1; i <= n; i++)
		ans = max (ans, solve (i));
	printf ("%d\n", ans);

	return 0;
}
