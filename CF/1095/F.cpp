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

using pp = pair<ll, int>;

const int N = 2e5+10;

int n, m;
int link[N], size[N], idxMn;
ll weight[N], ans, mn;
set<pp> st;
vector<pp> adj[N];
bool vis[N];

int main () {
	scanf ("%d %d", &n, &m);
	mn = 1e18;
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &weight[i]);
		if (weight[i] < mn) {
			idxMn = i;
			mn = weight[i];
		}
	}
	while (m--) {
		int x, y;
		ll w;
		scanf ("%d %d %lld", &x, &y, &w);
		adj[x].push_back ({w, y});
		adj[y].push_back ({w, x});
	}
	for (int i = 1; i <= n; i++)
		st.insert ({weight[i] + mn, i});
	
	st.insert ({0ll, idxMn});
	while (!st.empty()) {
		ll w = st.begin()->x;
		int u = st.begin()->y;
		st.erase (st.begin());
		if (vis[u]) continue;
		vis[u] = true;
		ans += w;
		for (pp p : adj[u])
			if (!vis[p.y])
				st.insert ({p.x, p.y});
	}
	
	printf ("%lld\n", ans);

	return 0;
}
