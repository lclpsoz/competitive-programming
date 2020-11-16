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

	base_t sum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(5);

	int n, a, b;
	cin >> n >> a >> b;
	fenwick<double> bit(n + 10);
	double p = 1.0 / (b - a + 1);
	double pp = (b) / (b + 1.0);
	double p2 = 1.0 / (b - a);

	for(int i = 1; i <= n; i++)
	{
		int l = max(0, i - b);
		int r = max(0, i - a - !a);
		
		if(a) bit.add(i + 1, 1 + bit.sum(l + 1, r + 1) * p);
		else bit.add(i + 1, 1 / pp + bit.sum(l + 1, r + 1) * p2);
	}

	double ans = bit.sum(n + 1, n + 1);
	cout << fixed << ans << endl;

	return 0;
}
