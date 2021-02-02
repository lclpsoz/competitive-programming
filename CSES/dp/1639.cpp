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

int n, m;
int dp[5005][5005];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	string s1, s2;
	cin >> s1 >> s2;
	n = LEN(s1), m = LEN(s2);
	for (int i = 1; i < 5005; i++)
		dp[i][0] = dp[0][i] = i;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			
			if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = dp[i-1][j-1]+1;
			dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1, dp[i][j-1]+1));
		}
	cout << dp[n][m] << '\n';

	return 0;
}
