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

template <class base_t>
struct fenwick
{
	vector<base_t> t;
	int n;

	fenwick(int _n = 0) : n(_n)
	{
		t.assign(n + 1, 0);
	}

	void add(int p, base_t v)
	{
		for(int i = p; i <= n; i += i & -i)
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
		add(l, v), add(r + 1, -v);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n; cin >> n;
	vi a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i++)
		cin >> a[i], mp[a[i]] = i + 1;

	fenwick<int> bit(n + 10);

	ll ans = 0;
	int l = 1, r = n;
	for(auto it = mp.rbegin(); it != mp.rend(); ++it)
	{
		int p = it->second;
		int pp = p + bit.sum(p);
		if(r - pp < pp - l)
		{
			// cout << it->first << ": " << p << " -> " << r << endl;
			ans += r - pp;
			bit.add(p, n, -1);
			--r;
		}
		else
		{
			// cout << it->first << ": " << p << " -> " << l << endl;
			ans += pp - l;
			bit.add(1, p, 1);
			++l;
		}
	}

	cout << ans << endl;

	return 0;
}
