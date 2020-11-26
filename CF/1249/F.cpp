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

const int N = 210;

int n, k;
int w[N];
vector<int> adj[N];
int dp[N][N];

void solve(int v, int p) {
	for(int u : adj[v])
		if(u != p)
			solve(u, v);

	// General
	for(int i = k-1; i >= 1; i--) {
		int &now = dp[v][i];
		int total = 0;
		for(int u : adj[v])
			if(u != p)
				total += dp[u][max(i-1, k-i-1)];
		for(int u : adj[v])
			if(u != p)
				now = max(now, total - dp[u][max(i-1, k-i-1)] + dp[u][i-1]);

		now = max(now, dp[v][i+1]);
	}

	// Using v
	int &ax = dp[v][0];
	ax = w[v];
	for(int u : adj[v])
		if(u != p)
			ax += dp[u][k-1];
	ax = max(ax, dp[v][1]);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> k;
	++k;
	for(int i = 1; i <= n; i++) cin >> w[i];

	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	solve(1, 1);
	cout << dp[1][0] << '\n';


	return 0;
}
