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

template <class base_t>
struct fenwick
{
	vector<base_t> t;
	int n;

	fenwick(int _n = 1) : n(_n)
	{
		t.assign(n, 0);
	}

	void add(int p, base_t v)
	{
		for(int i = p; i < n; i += i & -i)
			t[i] += v;
	}

	base_t sum(int p)
	{
		base_t ans = 0;
		for(int i = p; i > 0; i -= i & -i)
			ans += t[i];
		return ans;
	}

	void add(int l, int r, base_t v)
	{
		add(l, v);
		add(r + 1, -v);
	}
};


int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n; cin >> n;
	set<pii> st;
	for(int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		st.insert({h, i});
	}

	set<int> ord_l, ord_r;

	auto mid_l = [&](int l, int r) {
		int m = (l + r) / 2;
		return m + 1;
	};

	auto mid_r = [&](int l, int r) {
		int m = (l + r + 1) / 2;
		return m - 1;
	};

	fenwick<int> bit(n + 10);

	while(!empty(st)) {
		auto [h, id] = *st.rbegin();
		st.erase({h, id});

		int l = ord_l.upper_bound(-id) == ord_l.end() ? 0 : mid_l(-*ord_l.upper_bound(-id), id);
		int r = ord_r.upper_bound(id) == ord_r.end() ? n - 1 : mid_r(id, *ord_r.upper_bound(id));

		// cout << id << "-> " << l << ", " << r << endl;

		bit.add(l + 1, r + 1, 1);

		ord_l.insert(-id);
		ord_r.insert(id);
	}

	for(int i = 0; i < n; i++)
		cout << bit.sum(i + 1) - 1 << " \n"[i == n - 1];

	return 0;
}
