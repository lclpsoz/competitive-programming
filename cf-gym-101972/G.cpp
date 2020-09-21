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

const int N = 510;
int mat[N][N];
int pre[5][N][N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t; cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;

		for(int k = 0; k < 4; k++)
			memset(pre[k], 0, sizeof pre[k]);

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> mat[i][j];

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				pre[0][i][j] = max({pre[0][i - 1][j], pre[0][i][j - 1], mat[i][j]});

		for(int i = 1; i <= n; i++)
			for(int j = m; j > 0; j--)
				pre[1][i][j] = max({pre[1][i - 1][j], pre[1][i][j + 1], mat[i][j]});
		
		for(int i = n; i > 0; i--)
			for(int j = m; j > 0; j--)
				pre[2][i][j] = max({pre[2][i + 1][j], pre[2][i][j + 1], mat[i][j]});
		
		for(int i = n; i > 0; i--)
			for(int j = 1; j <= m; j++)
				pre[3][i][j] = max({pre[3][i + 1][j], pre[3][i][j - 1], mat[i][j]});
		
		int ans = 1e9;
		for(int i = 2; i < n; i++)
			for(int j = 2; j < m; j++)
			{
				int mx = 0, mn = 1e9;
				mx = max(mx, pre[0][i - 1][j - 1]);
				mx = max(mx, pre[1][i - 1][j + 1]);
				mx = max(mx, pre[2][i + 1][j + 1]);
				mx = max(mx, pre[3][i + 1][j - 1]);

				mn = min(mn, pre[0][i - 1][j - 1]);
				mn = min(mn, pre[1][i - 1][j + 1]);
				mn = min(mn, pre[2][i + 1][j + 1]);
				mn = min(mn, pre[3][i + 1][j - 1]);
				ans = min(ans, mx - mn);
			}
		cout << ans << endl;
	}

	return 0;
}
