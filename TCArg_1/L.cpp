#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 310;

int dp[2][N][N][2];
int n, a[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	cin >> n;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];

	int l = 1;
	for(int j = 1; j <= n; j++)
		for(int k = 1; k <= n; k++)
			dp[0][j][k][1] = -INF<int>;
	dp[0][1][1][1] = 0;

	for(int i = 1; i <= n; i++, l ^= 1)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)	
			{
				{
					int& now = dp[l][j][k][0];
					now = dp[l ^ 1][j][k][1] + a[i][j];
					if(j - 1 >= 1)
						now = max(now, dp[l][j - 1][k][0] + a[i][j]);
					// cout << i << " " << j << " " << k << " 0: " << now << endl;
				}
				{
					int& now = dp[l][j][k][1];
					now = dp[l][j][k][0] + (k > j ? a[i][k] : 0);
					if(k - 1 >= 1)
						now = max(now, dp[l][j][k - 1][1] + (k > j ? a[i][k] : 0));
					// cout << i << " " << j << " " << k << " 1: " << now << endl;
				}
			}

	cout << dp[l ^ 1][n][n][1] << endl;
	
	return 0;
}