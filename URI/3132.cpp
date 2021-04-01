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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	string a, b;
	cin >> a >> b;
	string s1 = "", s2 = "";
	for (char x : a)
		if (x >= 'a' and x <= 'z') {
			s1 += x-'a'+'A';
			s1 += x-'a'+'A';
		}
		else
			s1 += x;
	for (char x : b)
		if (x >= 'a' and x <= 'z') {
			s2 += x-'a'+'A';
			s2 += x-'a'+'A';
		}
		else
			s2 += x;
	vector<vi> dp(205, vi(205));
	for (int i = 1; i <= LEN(s1); i++)
		for (int j = 1; j <= LEN(s2); j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (s1[i-1] == s2[j-1])
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
		}
	cout << dp[LEN(s1)][LEN(s2)] << '\n';

	return 0;
}
