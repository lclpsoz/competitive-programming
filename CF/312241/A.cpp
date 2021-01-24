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
	int ret = x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 105, M = 11;
int dp[N][N][N];
int e[M], d[N], s[N];
int t, p;
int solve(int l, int r, int k)
{
	if(l > r) return 0;

	int& ans = dp[l][r][k];

	if(ans == -1)
	{
		ans = solve(l + 1, r, k);
		if(d[l] <= k)
			ans = max(ans, s[l] + solve(l + 1, r, k - d[l]));
	}

	return ans;
}

int dp2[1 << M][N];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> t >> p;
	for(int i = 0; i < t; i++) cin >> e[i];
	for(int i = 0; i < p; i++) cin >> d[i];
	for(int i = 0; i < p; i++) cin >> s[i];

	int ans = 0;
	memset(dp, -1, sizeof dp);
	for(int msk = 1; msk < (1 << t); msk++)
	{
		for(int r = 0; r < p; r++)
		{
			for(int i = 0; i < t; i++)
			{
				if(msk & (1 << i))
				{
					int nmsk = msk ^ (1 << i);
					for(int l = 0; l <= r; l++)
						dp2[msk][r] = max(dp2[msk][r], (!l ? 0 : dp2[nmsk][l - 1]) + solve(l, r, e[i]));
					ans = max(ans, dp2[msk][r]);
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
