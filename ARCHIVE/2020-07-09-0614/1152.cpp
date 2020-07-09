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

const int N = 2e5 + 10;

int n, m;
set<pii> st;
vector<pii> adj[N];
bitset<N> vis;

int main () {
	while (scanf ("%d %d", &n, &m), n) {
		int ans = 0, total = 0;
		for (int i = 0; i <= n; i++) vis[i] = 0, adj[i].clear();
		while (m--) {
			int x, y, z;
			scanf ("%d %d %d", &x, &y, &z);
			adj[x].push_back ({z, y});
			adj[y].push_back ({z, x});
			total += z;
		}
		vis[0] = 1;
		for (auto e : adj[0])
			st.insert (e);
		while (!st.empty()) {
			int w = st.begin()->x;
			int v = st.begin()->y;
			st.erase (st.begin());
			if (vis[v]) continue;
			vis[v] = 1;
			// printf ("%d %d\n", v, w);
			ans += w;
			// printf ("  %d, %d\n", total, ans);
			for (auto e : adj[v])
				st.insert (e);
		}
		printf ("%d\n", total - ans);
	}

	return 0;
}
