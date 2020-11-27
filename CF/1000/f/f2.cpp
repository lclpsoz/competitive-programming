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

const int N = 5e5 + 10;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vi vec(n), lft(n);
	for(int &v : vec) cin >> v;
	vi idx(N, -1);
	for(int i = 0; i < LEN(vec); i++) {
		lft[i] = idx[vec[i]];
		idx[vec[i]] = i;
	}
	for(int &v : idx) v = n;

	vector<pair<pii, int>> intervals;
	for(int i = LEN(vec)-1; i >= 0; i--) {
		intervals.push_back({{lft[i]+2, idx[vec[i]]}, vec[i]});
		idx[vec[i]] = i;
	}

	int m;
	cin >> m;
	vector<pair<pii, int>> queries;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back({{l, r}, i});
	}

	// for(auto &[a, b] : intervals)
	// 	cerr << a.x << ' ' << a.y << ' ' << b << '\n';

	sort(ALL(queries));
	sort(ALL(intervals));

	vi ans(m);
	int pos = 0;
	int mx = -1;
	int mx_val = -1;
	for(auto &[pp, p_ans] : queries) {
		auto &[l, r] = pp;
		while(pos < LEN(intervals) and intervals[pos].x.x <= l) {
			if(intervals[pos].x.y > mx) {
				cerr << "inter = " << intervals[pos].x.x << ' ' << intervals[pos].x.y << '\n';
				mx = intervals[pos].x.y;
				mx_val = intervals[pos].y;
				cerr << "  mx_val = " << mx_val << '\n';
			}
			++pos;
		}
		if(r <= mx)
			ans[p_ans] = mx_val;
	}

	for(int v : ans)
		cout << v << '\n';

	return 0;
}
