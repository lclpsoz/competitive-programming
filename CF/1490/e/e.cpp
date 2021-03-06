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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi vec(n);
		map<int, int> mp;
		for (int &x : vec) {
			cin >> x;
			mp[x]++;
		}
		vpii vals;
		ll acu = 0;
		for (auto [v, q] : mp)
			vals.push_back({v, q});
		set<int> ans;
		for (int i = 0; i < LEN(vals)-1; i++) {
			ll now = vals[i].x*1LL*vals[i].y + acu;
			// cerr << "i = " << i << ", now = " << now << '\n';
			if (now >= vals[i+1].x)
				ans.insert(vals[i].x);
			else {
				ans.clear();
			}
			acu = now;
		}
		ans.insert(vals.back().x);
		vi vec_ans;
		for (int i = 1; i <= n; i++)
			if (ans.count(vec[i-1]))
				vec_ans.push_back(i);
		cout << LEN(vec_ans) << '\n';
		for (int i = 0; i < LEN(vec_ans); i++)
			cout << vec_ans[i] << " \n"[i==LEN(vec_ans)-1];
	}

	return 0;
}
