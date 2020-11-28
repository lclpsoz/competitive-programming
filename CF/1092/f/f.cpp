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

int n;
vi adj[N];
ll a[N], dp[N], sub_a[N], ans[N];

void solve_tree(int v, int p) {
	for(int u : adj[v])
		if(u != p) {
			solve_tree(u, v);
			dp[v] += dp[u];
			sub_a[v] += sub_a[u];
		}
	dp[v] += sub_a[v];
	sub_a[v] += a[v];
}

void solve(int v, int p, ll acu_dp, ll acu_a) {
	ans[v] = dp[v] + acu_dp + acu_a;
	acu_a += sub_a[v];
	for(int u : adj[v])
		if(u != p)
			solve(u, v, ans[v] - dp[u] - sub_a[u], acu_a - sub_a[u]);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve_tree(1, 1);
	solve(1, 1, 0, 0);

	ll max_ans = 0;
	for(int i = 1; i <= n; i++) max_ans = max(ans[i], max_ans);
	cout << max_ans << '\n';

	return 0;
}
