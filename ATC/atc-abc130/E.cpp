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

const int MOD = 1e9+7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e3 + 10;

ll dp[N][N];
int a[N], b[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	// n = max(n, m);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
			if(a[i] == b[j])
				dp[i][j] = (dp[i][j]+dp[i-1][j-1]+1)%MOD;
			dp[i][j] = (dp[i][j]-dp[i-1][j-1]+MOD)%MOD;
			// cout << "i = " << i << ", j = " << j << ", dp = " << dp[i][j] << '\n';
		}


	cout << (dp[n][m]+1)%MOD << '\n';



	return 0;
}
