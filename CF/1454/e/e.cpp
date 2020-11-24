#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

vi adj[N];
int vert[N], tin[N], tlo[N];
bitset<N> cycle_v;
vi cycle;
int t_i;

int dfs_cycle(int v, int p) {
	if(tin[v])
		return tin[v];
	tin[v] = ++t_i;
	tlo[v] = 1e9;
	for(int u : adj[v])
		if(u != p)
			tlo[v] = min(tlo[v], dfs_cycle(u, v));
	if(tlo[v] <= tin[v]) {
		cycle_v[v] = 1;
		cycle.push_back(v);
	}
	
	return tlo[v];
}

int dfs(int v, int p) {
	int ret = 1;
	for(int u : adj[v]) {
		if(!cycle_v[u] and u != p)
			ret += dfs(u, v);
	}
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			adj[i].clear();
			tlo[i] = 0;
			tin[i] = 0;
			cycle_v[i] = 0;
			t_i = 1;
		}
		cycle.clear();
		for(int i = 0; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs_cycle(1, 1);
		vi vals;
		for(int v : cycle)
			vals.push_back(dfs(v, v));

		ll ans = 0;
		for(int v : vals) {
			// cout << "v = " << v << '\n';
			n -= v;
			ans += (v*1LL*(v-1))/2 + 2*(v*1LL*(n));
		}
		cout << ans << '\n';
	}


	return 0;
}
