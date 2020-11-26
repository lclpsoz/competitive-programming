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

	int n;
	cin >> n;
	vi vec;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	
	vector<pair<int, pii>> all_pairs;
	for(int i = 0; i < n; i++) {
		set<int> vals;
		int s = 0;
		for(int j = i; j < n; j++) {
			s += vec[j];
			if(vals.count(s) == 0) {
				vals.insert(s);
				all_pairs.push_back({s, {j, i}});
			}
		}
	}
	int ans = 0;
	vpii ans_vec;
	sort(ALL(all_pairs));
	int cur_val = -1e9;
	int l_used = -1;
	int now = 0;
	vpii vec_now;
	for(auto [val, pp] : all_pairs) {
		if(val != cur_val) {
			if(now > ans) {
				ans = now;
				ans_vec.swap(vec_now);
			}
			cur_val = val;
			l_used = -1;
			now = 0;
			vec_now.clear();
		}
		if(l_used < pp.y) {
			l_used = pp.x;
			++now;
			vec_now.push_back({pp.y, pp.x});
		}
	}
	if(now > ans) {
		ans = now;
		ans_vec.swap(vec_now);
	}
	cout << ans << '\n';
	for(auto [x, y] : ans_vec)
		cout << x+1 << ' ' << y+1 << '\n';

	return 0;
}
