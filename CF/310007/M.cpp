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
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vi> mat(n);
		for (vi &vec : mat) {
			int m;
			cin >> m;
			vec = vi(m);
			// cerr << "vec: ";
			for (int &v : vec) {
				cin >> v;
				// cerr << v << ' ';
			}
			// cerr << '\n';
			sort(ALL(vec));
		}
		map<pii, int> mp;
		auto add_pair = [&] (pii _p) {
			if (_p.x > _p.y)
				swap(_p.x, _p.y);
			mp[_p]++;
			return mp[_p] >= 2;
		};
		set<pair<int, pii>> st;
		for (int i = 0; i < n; i++) {
			// auto it = st.lower_bound({mat[i][0], {-1, -1}});
			// while (it != st.end() and it->x == mat[i][0]) {
			// 	add_pair({it->y.x, i});
			// 	++it;
			// }
			st.insert({mat[i][0], {i, 1}});
		}
		while (LEN(st)) {
			auto [val, _idx_nxt] = *st.begin();
			auto [idx, nxt_pos] = _idx_nxt;
			// cerr << "  idx = " << idx << '\n';
			st.erase(st.begin());
			auto it = st.lower_bound({val, {-1, -1}});
			bool ok = false;
			while (!ok and it != st.end() and it->x == val) {
				ok = add_pair({it->y.x, idx});
				++it;
			}
			if (ok) break;
			if (nxt_pos == LEN(mat[idx]))
				continue;
			st.insert({mat[idx][nxt_pos], {idx, nxt_pos+1}});
		}
		pii ans = {-1, -1};
		for (auto [p_idxs, cnt] : mp) {
			auto [x, y] = p_idxs;
			// cerr << " idxs = " << x << ", " << y << " -> " << cnt << '\n';
			if (cnt >= 2)
				ans = {x, y};
		}
		if (ans.x == -1)
			cout << "-1\n";
		else
			cout << ans.x+1 << ' ' << ans.y+1 << '\n';
		st.clear();
		mp.clear();
	}

	return 0;
}
