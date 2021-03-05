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

const int DBG = 0;

int n;
vi dbg_ans;

set<int> ask (int l, int r) {
	set<int> ret;
	cout << "Q " << l << ' ' << r << endl;
	if (!DBG) {
		for (int i = l; i <= r; i++) {
			int x;
			cin >> x;
			ret.insert(x);
		}
	}
	else {
		for (int i = l; i <= r; i++) {
			ret.insert(dbg_ans[i-1]);
		}
	}
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	if (DBG) {
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			dbg_ans.push_back(x);
		}
	}
	if (n == 1) {
		set<int> rig = ask(1, 1);
		cout << "A " << *rig.begin() << endl;
	}
	else {
		int l = 1, r = n/2;
		set<int> lft = ask(l, r);
		set<int> rig;
		cerr << "LEN(lft) = " << LEN(lft) << '\n';
		for (int i = 1; i <= n; i++)
			if (!lft.count(i)) rig.insert(i);
		vi ans(n+1);
		l = 2, r = n-1;
		while (l <= r) {
			set<int> mid = ask(l, r);
			set<int> ax = lft;
			for (int x : mid) ax.erase(x);
			if (LEN(ax))
				ans[l-1] = *ax.begin();
			else
				ans[l-1] = *lft.begin();
			lft.erase(ans[l-1]);
			ax = rig;
			for (int x : mid) 
				cerr << "x = " << x << '\n';
			for (int x : mid) ax.erase(x);
			ans[r+1] = *ax.begin();
			rig.erase(*ax.begin());
			++l, --r;
		}
		cerr << "LEN = " << LEN(rig) << '\n';
		if (LEN(lft))
			ans[n/2] = *lft.begin();
		if (LEN(rig))
			ans[n/2+1] = *rig.begin();
		cout << "A";
		for (int i = 1; i <= n; i++)
			cout << ' ' << ans[i];
		cout << endl;
	}

	return 0;
}
