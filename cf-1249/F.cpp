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

int solve(int v, int p, int dist) {
	// printf("%d %d\n", v, dep);
	int &ret = dp[v][dist];
	if(ret != -1) return ret;
	int sum = 0;
	if(dist > k) {
		sum = w[v];
		for(int u : adj[v])
			if(u != p)
				sum += solve(u, v, 1);
	}
	int sum2 = 0;
	for(int u : adj[v]) {
		if(u != p)
			sum2 += solve(u, v, dep+1);
	}
	// printf("  v = %d, %d %d\n", v, sum, sum2);
	ret = max(sum, sum2);
	return ret;
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);

	for(int i = 0; i < n-1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int ans = 0;
	for(int root = 1; root <= n; root++) {
		memset(dp, -1, sizeof dp);
		int now = solve(root, -1, k+1);
		printf("root = %d, val = %d\n", root, now);
		ans = max(ans, now);
	}
	printf("%d\n", ans);

	return 0;
}
