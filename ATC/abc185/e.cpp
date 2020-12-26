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

int dp[1010][1010];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	for (int &v : a)
		cin >> v;
	for (int &v : b)
		cin >> v;
	
	for (int i = 1; i <= n+1; i++)
		for (int j = 1; j <= m+1; j++)
			dp[i][j] = INF<int>;
	for (int i = 0; i < 1010; i++)
		dp[0][i] = dp[i][0] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i-1] != b[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = dp[i-1][j-1];
			dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
			dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
		}
	cout << dp[n][m] << '\n';


	return 0;
}
