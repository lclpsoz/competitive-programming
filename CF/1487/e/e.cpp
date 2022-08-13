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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
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

	vi n(4), m(4);
	vector<vi> costs(4, vi(150010));
	for (int &x : n) cin >> x;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n[i]; j++)
			cin >> costs[i][j];
	vector<vector<set<int>>> cant(3, vector<set<int>>(150010));
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		cant[i][y].insert(x);
	}

	bool ans = true;
	vpii cheap, nxt;
	for (int i = 0; i < 3; i++) {
		if (LEN(cheap) == 0)
			for (int j = 0; j < n[i]; j++)
				cheap.push_back({costs[i][j], j+1});
		sort(ALL(cheap));
		cerr << "i = " << i << '\n';
		cerr << "cheap:\n";
		for (auto [x, y] : cheap)
			cerr << "  " << x << ' ' << y << '\n';
		for (int j = 0; j < n[i+1]; j++) {
			int mini = INF<int>;
			for (auto [w, id] : cheap) {
				if (!cant[i][j].count(id))
					mini = min(mini, w);
			}
			cerr << "mini = " << mini << ", c = " << costs[i+1][j] << '\n';
			if (mini < INF<int>)
				nxt.push_back({mini+costs[i+1][j], j+1});
		}
		cerr << "here!!\n";

		if (LEN(nxt) == 0) {
			ans = false;
			break;
		}
		cheap = nxt;
		nxt.clear();
	}
	if (ans) {
		int val = INF<int>;
		for (auto [w, id] : cheap)
			val = min(val, w);
		cout << val << '\n';
	}
	else
		cout << "-1\n";

	return 0;
}
