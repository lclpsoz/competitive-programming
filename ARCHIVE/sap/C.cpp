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

const ll INF = 1e19;
const int N = 1e4 + 10;

int f, c, t;
ll dist[N];
bool vis[N];
vector<pii> adj[N];

int main () {
	scanf ("%d", &f);
	ll ans = 0;
	while (f--) {
		scanf ("%d %d", &c, &t);
		for (int i = 1; i <= c; i++) adj[i].clear(), dist[i] = INF, vis[i] = false;
		while (t--) {
			int a, b, d;
			scanf ("%d %d %d", &a, &b, &d);
			adj[a].push_back ({b, d});
		}
		set<pair<ll, int>> st;
		st.insert ({0, 1});
		dist[1] = 0;
		while (!st.empty()) {
			int v = st.begin()->y;
			ll d = st.begin()->x;
			st.erase (st.begin());
			if (vis[v]) continue;
			vis[v] = true;
			for (auto pp : adj[v]) {
				int u = pp.x;
				if (dist[v] + pp.y < dist[u]) {
					dist[u] = dist[v] + pp.y;
					st.insert ({dist[u], u});
				}
			}
		}
		ans += dist[c];
	}
	printf ("%lld\n", ans);

	return 0;
}
