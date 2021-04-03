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

vector<vector<int>> adj;
vector<long long> chain, indiv, sub;

void dfs(int v) {
	for (int u : adj[v]) {
		dfs(u);
		indiv[v] += chain[u];
		chain[v] += chain[u];
	}
}

void dfs2(int v) {
	sub[v] = indiv[v];
	for (int u : adj[v]) {
		dfs2(u);
		sub[v] += sub[u];
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m, q;
	cin >> n >> m >> q;
	adj = vector<vector<int>>(n + 1, vector<int>());

	int jaime = 0;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		if(!p) jaime = i;
		else adj[p].push_back(i);
	}

	indiv = vector<long long>(n + 1, 0);
	chain = vector<long long>(n + 1, 0);
	sub = vector<long long>(n + 1, 0);

	while (m--) {
		int t, e, v;
		cin >> t >> e >> v;
		if (t == 1) {
			indiv[e] += v;
		} else {
			indiv[e] += v;
			chain[e] += v;
		}
	}
	dfs(jaime);
	// for(int i = 1; i <= n; i++)
	// 	cout << indiv[i] << " \n"[i == n];
	dfs2(jaime);
	// for(int i = 1; i <= n; i++)
	// 	cout << sub[i] << " \n"[i == n];
	while (q--) {
		int t, e;
		cin >> t >> e;
		if (t == 1) {
			cout << indiv[e] << '\n';
		} else {
			cout << sub[e] << '\n';
		}
	}

	return 0;
}
