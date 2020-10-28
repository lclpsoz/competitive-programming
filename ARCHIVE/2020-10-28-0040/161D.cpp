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

const int N = 5e4 + 10;

int n, k;
ll ans = 0;
int dp[N][505];
vector<int> adj[N];

void solve(int v, int p, int dep) {
	vector<int> now(505, 0);
	vector<int> tmp(505, 0);
	for(int u : adj[v])
		if(u != p) {
			solve(u, v, dep+1);
			ans += dp[u][k-1];
			for(int i = k-1; i >= 0; i--) {
				dp[v][i+1] += dp[u][i];
				if(i and i <= (k/2)) {
					// printf("v = %d, u = %d, i = %d -> %lld, %lld\n", v, u, i, dp[u][k-i-1]*1LL*now[i], dp[u][i-1]*1LL*now[k-i]);
					ans += dp[u][k-i-1]*1LL*now[i];
					if(i != k-i)
						ans += dp[u][i-1]*1LL*now[k-i];
				}
				tmp[i+1] = dp[u][i];
			}
			for(int i = 0; i < k; i++) now[i] += tmp[i];
		}
	dp[v][0] = 1;
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n-1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	solve(1, -1, 0);
	// for(int i = 1; i <= n; i++) {
	// 	printf("%d: ", i);
	// 	for(int j = 0; j <= k; j++)
	// 		printf("%d%c", dp[i][j], " \n"[j==k]);
	// }
	printf("%lld\n", ans);

	return 0;
}
