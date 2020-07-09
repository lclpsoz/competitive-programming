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
const ll INF = 1e18;
const int N = 1e4+10;

int n, m;
vector<pair<int, pii>> adj[N];
set<pp> st;
ll dist[N], costSingle[N];

ll dijkstra () {
	for (int i = 1; i <= n; i++)
		dist[i] = costSingle[i] = INF;
	st.insert ({0, 1});
	dist[1] = costSingle[1] = 0;

	while (!st.empty()) {
		int v = st.begin()->y;
		ll dPath = st.begin()->x;
// 		printf ("%d %lld %lld\n", v, dPath, cPath);
		st.erase (st.begin());
		if (dPath > dist[v]) continue;
		for (auto p : adj[v]) {
			int u = p.x;
			int d = p.y.x;
			int c = p.y.y;
			if (dist[u] > dist[v] + d or (dist[u] == dist[v] + d and
										costSingle[u] > c)) {
				dist[u] = dist[v] + d;
				costSingle[u] = c;
				st.insert ({dist[u], u});
			}
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += costSingle[i];
	return ans;
}


int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int a, b, l, c;
		scanf ("%d %d %d %d", &a, &b, &l, &c);
		adj[a].push_back ({b, {l, c}});
		adj[b].push_back ({a, {l, c}});
	}
	
	printf ("%lld\n", dijkstra());	
	
	return 0;
}
