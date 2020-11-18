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

int dp[40][75];
int dp_ans[2][75];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, k;
	cin >> n >> m >> k;
	memset(dp_ans, -1, sizeof dp_ans);
	dp_ans[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;
		for(int j = 1; j <= m; j++) {
			// cout << i << ' ' << j << '\n';
			// cout.flush();
			int val;
			cin >> val;
			for(int l = m/2; l > 0; l--) {
				for(int v = 0; v < k; v++)
					if(dp[l-1][mod(v, k)] != -1)
						dp[l][mod(v+val, k)] = max(dp[l][mod(v+val, k)], dp[l-1][mod(v, k)]+val);
			}
		}

		for(int l = m/2-1; l > 0; l--)
			for(int v = 0; v < k; v++)
				dp[m/2][v] = max(dp[m/2][v], dp[l][v]);
		// cout << "dp = ";
		// for(int v = 0; v < k; v++)
		// 	cout << dp[m/2][v] << ' ';
		// cout << '\n';

		// cout << "here!\n";
		// cout.flush();
		int now = i&1;
		// cout << "dp_ans = ";
		for(int v = 0; v < k; v++) {
			dp_ans[now][v] = dp_ans[!now][v];
			// cout << dp_ans[now][v] << ' ';
		}
		// cout << "\n\n";
		for(int v = 0; v < k; v++)
			if(dp[m/2][v] != -1)
				for(int v_ans = 0; v_ans < k; v_ans++)
					if(dp_ans[!now][mod(v_ans-v, k)] != -1) {
						// cout << v << ' ' << v_ans << '\n';
						dp_ans[now][v_ans] = max(dp_ans[now][v_ans], dp_ans[!now][mod(v_ans-v, k)]+dp[m/2][v]);
					}
	}
	cout << dp_ans[n&1][0] << '\n';

	return 0;
}
