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

const int N = 1e5 + 10;

string a, b;
int dp[2][N];



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> a >> b;
	int n = LEN(a);
	int miss = n/100;

	for(int i = 0; i <= n; i++) {
		int now = i%2;
		int bef = !now;
		for(int j = max(0, i-miss); j <= min(n, i+miss); j++) {
			// cout << "i = " << i << ", j = " << j << '\n';
			int &val = dp[now][j];
			val = 0;
			if(i and j and a[i-1] == b[j-1])
				val = dp[bef][j-1]+1;
			if(j)
				val = max(val, dp[now][j-1]);
			val = max(val, dp[bef][j]);
		}
		// cout << "  dp[" << i << "] = ";
		// for(int j = max(0, n-10); j <= n; j++)
		// 	cout << dp[now][j] << " \n"[j==n];
	}
	// for(int i = 0; i < 2; i++) {
	// 	cout << "  dp[" << i << "] = ";
	// 	for(int j = max(0, n-10); j <= n; j++)
	// 		cout << dp[i][j] << " \n"[j==n];
	// }
	// cout << dp[n%2][n] << '\n';
	if(n-dp[(n)%2][n] > miss)
		cout << "Not brothers :(\n";
	else
		cout << "Long lost brothers D:\n";

	return 0;
}
