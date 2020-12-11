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

const int DBG = 0;

int n;
vi vec;
map<int, int> dp[2010][2010];

int solve(int pos, int x, int y) {
	if(pos == n) return 0;
	// cout << "pos = " << pos << ", x = " << x << ", y = " << y << '\n';
	int p_now = 3*pos;
	if(dp[pos][x].count(y)) return dp[pos][x][y];
	int &ret = dp[pos][x][y];
	if(pos < n-1) {
		vi now = {x, y, vec[p_now+2], vec[p_now+3], vec[p_now+4]};
		ret = solve(pos+1, x, y) + (now[2] == now[3] and now[3] == now[4]);
		for(int i = 0; i < 5; i++)
			for(int j = i+1; j < 5; j++)
				ret = max(ret, solve(pos+1, now[i], now[j]));
	}
	else
		ret = x == y and y == vec[p_now+2];
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;
	for(int i = 0; i < 3*n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	cout << solve(0, vec[0], vec[1]) << '\n';

	return 0;
}
