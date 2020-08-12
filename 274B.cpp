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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const ll INF = 1e18;
const int N = 1e5 + 10;

int n;
vector<int> adj[N];
ll w[N], ans, dp[N][2];

void solve(int v, int p) {
	ll delta = 0;
	// ll mini = 1e18;
	// ll maxi = -mini;
	dp[v][0] = INF;
	dp[v][1] = -dp[v][0];
	for(int u : adj[v])
		if(u != p) {
			solve(u, v);
			dp[v][0] = min(dp[v][0], dp[u][0]);
			dp[v][1] = max(dp[v][1], dp[u][1]);
		}
	if(dp[v][0] > 0) dp[v][0] = 0;
	if(dp[v][1] < 0) dp[v][1] = 0;
	w[v] += -dp[v][0] + -dp[v][1];
	if(w[v] > 0) dp[v][1] += w[v];
	else dp[v][0] += w[v];
	// printf("v = %d, dp = %lld, mn, mx = %lld, %lld\n", v, dp[v], mini, maxi);
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d", &n);
	for(int i = 1; i <= n-1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
		scanf("%lld", &w[i]);
	solve(1, 1);
	// for(int i = 1; i <= n; i++)
	// 	printf("%d: %d %d\n", i, dp[i][0], dp[i][1]);
	printf("%lld\n", abs(dp[1][1]) + abs(dp[1][0]));

	return 0;
}
