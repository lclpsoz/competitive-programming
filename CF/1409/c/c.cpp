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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n, x, y;
		cin >> n >> x >> y;
		int mx_step = 1;
		int ans_mx = 1e9;
		vi ans = {};
		for(int i = 1; i < n; i++)
			if((y-x)%i == 0) {
				int step = (y-x)/i;
				for(int st = 1; st <= 50; st++) {
					bool ok_x = false, ok_y = false;
					vi now;
					int cur_val = st;
					for(int j = 1; j <= n; j++) {
						now.push_back(cur_val);
						if(cur_val == x) ok_x = 1;
						else if(cur_val == y) ok_y = 1;
						cur_val += step;
					}
					if(ok_x and ok_y) {
						cur_val -= step;
						if(cur_val < ans_mx) {
							ans_mx = cur_val;
							ans = now;
						}
					}
				}
			}
		for(int i = 0; i < n; i++)
			cout << ans[i] << " \n"[i==n-1];
	}

	return 0;
}