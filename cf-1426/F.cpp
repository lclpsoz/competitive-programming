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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

int n;
string s;
int dp[3][4];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> s;
	reverse(ALL(s));
	int amnt = 0;
	for(char c : s) {
		if(c == 'a') {
			for(int i = 0; i <= 2; i++)
				dp[0][i] = (dp[1][i]+dp[0][i])%MOD;
		} else if (c == 'b') {
			for(int i = 0; i <= 1; i++)
				dp[1][i] = (dp[2][i]+dp[1][i])%MOD;
		} else if (c == 'c') {
			dp[2][0]++;
		} else {
			amnt++;
			for(int i = 0; i <= 2; i++)
				dp[0][i+1] = (dp[1][i]+dp[0][i+1])%MOD;
			for(int i = 0; i <= 1; i++)
				dp[1][i+1] = (dp[2][i]+dp[1][i+1])%MOD;
			dp[2][1]++;
		}
	}

	int ans = 0;
	for(int i = 0; i <= min(amnt, 3); i++) {
		int po = 1;
		for(int j = 0; j < amnt-i; j++)
			po = (po*1LL*3)%MOD;
		// cout << "qnt = " << i << '\n';
		// for(int j = 0; j < 3; j++)
		// 	cout << "  " << (char)('a'+j) << ": " << dp[j][i] << '\n';
		ans = (ans+dp[0][i]*1LL*po)%MOD;
	}
	cout << ans << '\n';

	return 0;
}
