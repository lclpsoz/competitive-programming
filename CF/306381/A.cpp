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

const int N = 800;
int n, dp[N][N];
string s;

int solve(int i, int j)
{
	if(j == 26) return 0;
	if(i == n) return INF<int>;

	int& ans = dp[i][j];
	if(ans == -1)
	{
		ans = INF<int>;
		if(!j) ans = solve(i + 1, j);
		ans = min(ans, 1 + solve(i + 1, j));
		if(s[i] == char('A' + j))
			ans = min(ans, 1 + solve(i + 1, j + 1));
	}
	return ans;
}

int main () {
	// freopen("collectingofficer.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t; cin >> t;
	while(t--)
	{
		cin >> n >> s;
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << endl;
	}

	return 0;
}
