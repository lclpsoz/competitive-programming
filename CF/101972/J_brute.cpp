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

int dp[1010][1010];
int calc(int i, int j)
{
	if(!i && !j) return 1;
	if(j < 0 || j > i) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	// cout << i << ' ' << j << '\n';
	return dp[i][j] = calc(i - 1, j - 1) + calc(i - 1, j);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	memset(dp, -1, sizeof dp);
	for(int n = 33; n <= 62; n++)
	{
		// cout << "n = " << n << '\n';
		int ans = 0;
		for(int i = 0; i <= n; i++)
		{
			// cout << "\tm = " << i << '\t' << calc(n, i) << '\t' << bitset<16>(calc(n, i)) <<'\n';
			// cout << i << ": " << calc(n, i) % 2 << endl;
			ans += ((calc(n, i) % 2) == 0);
		}
		// if(ans != 5) continue;
		// for(int i = 0; i <= n; i++)
			// cout << i << ": " << calc(n, i) % 2 << endl;
		cout << "ans(" << n << " | " << bitset<10>(n) << "): " << ans;
		for(int i = 0; i < ans; i++)
			cout << '.';
		cout << '\n';
	}
	return 0;
}