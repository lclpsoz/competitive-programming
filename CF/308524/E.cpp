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

const int N = 110;
int dp[N][N][2][2010];
int n, m;
pii a[N][N];

int solve(int i, int j, bool k, int c)
{
	if(i == n || j == m) return 0;

	int& ans = dp[i][j][k][c];
	if(ans == -1)
	{
		auto [x, y] = a[i][j];
		ans = min(x, y);
		
		if(x > y) x -= y, y = 0;
		else y -= x, x = 0;

		bool nk = k;
		int nc = c;

		if(x)
		{
			if(!k) nc += x;
			else
			{
				int d = min(x, c);
				nc -= d, x -= d, ans += d;
				if(x) nk = !nk, nc = x;
			}
		}
		else if(y)
		{
			if(k) nc += y;
			else
			{
				int d = min(y, c);
				nc -= d, y -= d, ans += d;
				if(y) nk = !nk, nc = y;
			}
		}
		ans += max(solve(i + 1, j, nk, nc), solve(i, j + 1, nk, nc));
	}
	return ans;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t; cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				for(int k = 0; k < 2; k++)
					for(int c = 0; c < 2010; c++)
						dp[i][j][k][c] = -1;
				
				a[i][j] = {0, 0};
				int x; cin >> x;
				while((x % 2) == 0) a[i][j].first++, x /= 2;
				while((x % 3) == 0) a[i][j].second++, x /= 3;
			}
		
		cout << solve(0, 0, 0, 0) << endl;
	}

	return 0;
}
