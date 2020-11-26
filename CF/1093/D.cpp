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

const int N = 3e5+10;

int t, n, m;
int vert[N];
vector<int> adj[N];
pii now;

bool dfs (int v, int p, int color) {
	if (vert[v] != -1) {
		if (vert[v] != color)
			return true;
		return false;
	}
	if (color)
		now.x++;
	else
		now.y++;
	vert[v] = color;
	for (int u : adj[v])
		if (u != p)
			if (dfs (u, v, !color))
				return true;
	return false;
}

int powMod (int b, int p) {
	int ret = 1;
	while (p) {
		if (p&1)
			ret = mod (ret * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}
	
	return ret;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			vert[i] = -1;
			adj[i].clear();
		}
		while (m--) {
			int x, y;
			scanf ("%d %d", &x, &y);
			adj[x].push_back (y);
			adj[y].push_back (x);
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (vert[i] != -1)
				continue;
			now = {0, 0};
			if (dfs (i, i, 0)) {
				ans = 0;
				break;
			}
			ans = mod (ans * 1LL * mod (powMod (2, now.x) + powMod (2, now.y)));
		}
		printf ("%d\n", ans);
	}

	return 0;
}
