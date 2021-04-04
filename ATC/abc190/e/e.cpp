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
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10, MSK = (1<<18) + 15;

int n, m, k;
vi adj[N];
vi choosen;
int dp[18][MSK];

vi get_dij (int st) {
	set<pii> dij;
	vi dist(n+1, INF<int>);
	dist[st] = 0;
	dij.insert({0, st});
	while (LEN(dij)) {
		auto [d, v] = *dij.begin();
		dij.erase(dij.begin());
		if (dist[v] != d)
			continue;
		for (int u : adj[v])
			if (dist[u] > dist[v]+1) {
				dist[u] = dist[v]+1;
				dij.insert({dist[u], u});
			}
	}
	return dist;
}

int tsp (int v, int msk, vector<vpii> &adj_tsp) {
	if (msk == ((1<<k)-1))
		return 0;
	// cerr << "v = " << v << ", msk = " << bitset<4>(msk) << '\n';
	int &ret = dp[v][msk];
	if (ret != -1) return ret;
	ret = INF<int>;
	for (auto [u, d] : adj_tsp[v])
		if (!(msk & (1<<u)))
			ret = min(ret, tsp (u, msk | (1<<u), adj_tsp) + d);
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		choosen.push_back(x);
	}
	sort(ALL(choosen));

	vector<vpii> adj_tsp(k+1);
	for (int v = 0; v < k; v++) {
		int ori_v = choosen[v];
		vi dists = get_dij(ori_v);
		// cerr << "ori_v = " << ori_v << ", dists = ";
		// for (int d : dists)
		// 	cerr << d << ' ';
		// cerr << '\n';
		for (int u = 0; u < k; u++) {
			if (u != v) {
				int ori_u = choosen[u];
				if (dists[ori_u] < INF<int>) {
					adj_tsp[v].push_back({u, dists[ori_u]});
					// cerr << "(" << v << ", " << u << ") -> " << dists[ori_u] << '\n';
				}
			}
		}
	}
	int ans = INF<int>;
	memset(dp, -1, sizeof dp);
	for (int v = 0; v < k; v++)
		ans = min(ans, tsp(v, 1<<v, adj_tsp));
	if (ans >= INF<int>)
		cout << "-1\n";
	else
		cout << ans+1 << '\n';


	return 0;
}
