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

const int N = 1e5 + 100;

int n;
vector<pair<int, int>> adj[N];
int ans = - 2e9;

void dfs (int v, int p, int k, int acu) {
	// printf ("v = %d, p = %d, k = %d acu = %lld\n", v, p, k, acu);
	for (auto pp : adj[v])
		if (pp.x != p) {
			// printf ("  %d %d w = %lld\n", v, pp.x, pp.y);
			ans = max (ans, k*pp.y + acu);
			dfs (pp.x, v, k-1, acu + pp.y);
		}
}

int main () {
	int k, x;
	scanf ("%d", &n);
	--n;
	while (n--) {
		int u, v;
		int w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({v, w});
		adj[v].push_back ({u, w});
	}

	scanf ("%d %d", &k, &x);dfs (x, x, k, 0);
	printf ("%d", ans);

	return 0;
}
