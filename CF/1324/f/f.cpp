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

int sub[N], dp[N], val[N];
vi adj[N];

void fill_sub (int v, int p) {
	sub[v] = val[v];
	for (int u : adj[v]) 
		if (u != p) {
			fill_sub(u, v);
			sub[v] += max(0, sub[u]);
		}
}

void solve (int v, int p) {
	dp[v] = sub[v];
	if (v != 1)
		dp[v] += max(0, sub[p]);
	int ori_sub = dp[v];
	sub[v] = ori_sub;
	for (int u : adj[v])
		if (u != p) {
			sub[v] -= max(0, sub[u]);
			solve(u, v);
			sub[v] = ori_sub;
		}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	for (int i = 1 ; i <= n; i++) {
		cin >> val[i];
		if (!val[i])
			val[i] = -1;
	}
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fill_sub(1, 1);
	// for (int i = 1; i <= n; i++)
	// 	cerr << "sub[" << i << "] = " << sub[i] << '\n';
	solve(1, 1);

	for (int i = 1; i <= n; i++)
		cout << dp[i] << " \n"[i==n];
	

	return 0;
}
