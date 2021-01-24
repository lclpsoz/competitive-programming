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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

vi adj[1010];
int dist[1010][1010];

void f_bfs (int st) {
	vpii bfs;
	bfs.push_back({st, 0});
	for (int i = 0; i < LEN(bfs); i++) {
		auto [v, d] = bfs[i];
		if (dist[st][v] != INF<int>) continue;
		dist[st][v] = d;
		for (int u : adj[v])
			if (dist[st][u] == INF<int>)
				bfs.push_back({u, d+1});
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	ll k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF<int>;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		// dist[u][v] = dist[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
		f_bfs(i);

	ll len_order, t;
	cin >> len_order >> t;
	k = t/k;

	vi order;
	while (len_order--) {
		int v;
		cin >> v;
		order.push_back(v);
	}

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= n; j++)
	// 		cerr << dist[i][j] << " \n"[j==n];

	vi spe_city(LEN(order)), spe_val(LEN(order));
	for (int i = 0; i < LEN(order); i++)
		cin >> spe_city[i] >> spe_val[i];

	int bef = 1;
	ll dist_base = 0;
	for (int x : order) {
		dist_base += dist[bef][x];
		bef = x;
	}
	dist_base += dist[bef][1];
	k -= dist_base;
	if (k < 0)
		cout << "Impossible\n";
	else {
		vector<ll> w(LEN(order));
		for (int i = 0; i < LEN(order); i++) {
			w[i] = dist[order[i]][spe_city[i]];
			if (i < LEN(order)-1) {
				w[i] += dist[spe_city[i]][order[i+1]];
				w[i] -= dist[order[i]][order[i+1]];
			}
			else {
				w[i] += dist[spe_city[i]][1];
				w[i] -= dist[order[i]][1];
			}
		}
		int ax = 102*LEN(order);
		vector<ll> dp(ax, INF<int>);
		dp[0] = 0;
		for (int ii = 0; ii < LEN(order); ii++) {
			int val = spe_val[ii];
			int wei = w[ii];
			for (int j = 100*ii; j >= 0; j--)
				if (dp[j] < INF<int>)
					dp[j+val] = min(dp[j+val], dp[j]+wei);
		}
		int ans = 0;
		for (int i = 0; i <= 100*LEN(order); i++)
			if (dp[i] <= k)
				ans = max(ans, i);
		cout << ans << '\n';
	}

	return 0;
}
