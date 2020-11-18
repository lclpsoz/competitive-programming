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

ll dp[105][105];

ll solve(vector<vector<ll>> &mat, int n, int m) {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dp[i][j] = INF<ll>;
	dp[1][1] = 0;
	ll st_val = mat[1][1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			ll expected = st_val+(i+j-2);
			if(i > 1 and mat[i][j] >= expected)
				dp[i][j] = min(dp[i][j], dp[i-1][j] + mat[i][j]-expected);
			if(j > 1 and mat[i][j] >= expected)
				dp[i][j] = min(dp[i][j], dp[i][j-1] + mat[i][j]-expected);
			// cout << dp[i][j] << " [" << mat[i][j] << "] ";
			// if(j==m) cout << '\n';
		}

	return dp[n][m];
}
int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		// cout << "t = " << t << '\n';
		int n, m;
		cin >> n >> m;
		vector<vi> adj(n*m+10);
		vector<vector<ll>> mat(n+1, vector<ll>(m+10));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> mat[i][j];

		ll st_val = mat[1][1];
		ll en_val = mat[n][m];
		int op = n-1 + m-1;
		ll base = 0;
		if(st_val+op > en_val) {
			base = (st_val+op)-en_val;
			st_val -= base;
			mat[1][1] = st_val;
		}
		else if(st_val+op < en_val) {
			base += en_val-(st_val+op);
			en_val -= base;
			mat[n][m] = en_val;
		}
		// cout << "base = " << base << '\n';
		ll ans = INF<ll>;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				int op_now = i + j - 2;
				ll st_now = mat[i][j]-op_now;
				// cout << st_now << " vs " << st_val << '\n';
				if(st_now <= st_val) {
					ll delta = st_val-st_now;
					mat[1][1] = st_val-delta;
					mat[n][m] = en_val-delta;

					ll now = base + 2*delta + solve(mat, n, m);
					ans = min(ans, now);
					// cout << "  st_now = " << st_now << ", delta = " << delta << ", now = " << now << '\n';
				}
			}

		cout << ans << '\n';
	}

	return 0;
}
