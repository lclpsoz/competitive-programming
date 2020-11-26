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

const int N = 2e5 + 10;

int n, m;
set<int> ax[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.precision(10);
	cin >> n >> m;
	vector<vector<int>> a(n+2, vector<int>(m+2));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			// a[i][j]--;
		}

	int ans = 0;
	for(int col = 1; col <= m; col++) {
		// int maxi = 0;
		for(int lin = 1; lin <= n; lin++) {
			// cout << col << ' ' << lin << ' ' << a[lin][col] << '\n';
			int x = a[lin][col]-col;
			if(x%m == 0) {
				x/=m;
				if(x < n) {
					int pp = x - (lin-1);
					if(pp < 0) pp+=n;

					pp = (n - pp)%n;
					ax[pp].insert(x);
				}
				// maxi = max(maxi, LEN(ax[pp]));
				// cout << col << ' ' << LEN(ax[pp]) << '\n';
				// cout << "pp = " << pp << '\n';
			}
		}
		int mini = n;
		for(int i = 0; i <= n; i++) {
			// cout << "i = " << i << ' ' << LEN(ax[i]) << '\n';
			mini = min(i + (n-LEN(ax[i])), mini);
			ax[i].clear();
		}
		ans += mini;
	}
	cout << ans << '\n';

	return 0;
}
