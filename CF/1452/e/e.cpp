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

ll mat[2020][2020];

void add_mat(int x1, int y1, int x2, int y2, ll v)
{
	mat[x2][y2] += v;
	mat[x1-1][y1-1] += v;
	mat[x1-1][y2] += -v;
	mat[x2][y1-1] += -v;
}

void add(int x1, int x2, int n, int v) {
	x1 = max(1, x1);
	x2 = min(x2, n);
	add_mat(1, x1, n, x2, v);
	add_mat(x1, 1, x2, n, v);
	add_mat(x1, x1, x2, x2, -v);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, k;
	cin >> n >> m >> k;

	while(m--) {
		int x, y;
		cin >> x >> y;
		int sz = y-x+1;
		for(int ln = 1; ln <= min(sz, k); ln++)
			add(x-k+ln, y-ln+1, n, 1);
	}

	for(int i = 2010; i >= 0; i--)
		for(int j = 2010; j >= 0; j--)
			mat[i][j] = mat[i][j] + mat[i+1][j] + mat[i][j+1] - mat[i+1][j+1];

	ll ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans = max(ans,mat[i][j]);
	cout << ans << '\n';

	return 0;
}
