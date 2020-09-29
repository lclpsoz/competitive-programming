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

int n;
vector<int> a(3), b(3), x(3), y(3);

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	cin >> n;
	for(int i = 0; i < 3; i++) cin >> a[i];
	for(int i = 0; i < 3; i++) cin >> b[i];

	vector<pii> vec;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			vec.push_back({i, j});
	int ans_mn = 2e9, ans_mx = -2e9;
	do {
		x = a;
		y = b;
		int wins = 0;
		for(pii p : vec) {
			int mn = min(x[p.x], y[p.y]);
			x[p.x] -= mn, y[p.y] -= mn;
			if((p.y-p.x+3)%3 == 1)
				wins += mn;
		}
		ans_mn = min(ans_mn, wins);
		ans_mx = max(ans_mx, wins);
	} while(next_permutation(ALL(vec)));
	// cout << q << '\n';
	cout << ans_mn << ' ' << ans_mx << '\n';

	return 0;
}
