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
const int MOD = 1e9 + 7;

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
			t[i] = mod(t[i]+v);
	}

	base_t sum(int p)
	{
		base_t ans = 0;
		for(int i = p; i > 0; i -= i & -i)
			ans = (ans+t[i])%MOD;
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

	int k, delay;
	cin >> k >> delay;

	vector<vi> mat(k+1, vi(k+1));
	for (int i = 0; i <= k; i++)
		mat[i][0] = -2.1e9;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			cin >> mat[i][j];

	fenwick<int> bef(k+1);
	for (int i = 1; i <= k; i++)
		bef.add(i, i, 1);
	
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		fenwick<int> now(k+1);
		int p;
		cin >> p;
		int st = -1, en = -1;
		for (int j = 1; j <= k; j++) {
			auto it_l = lower_bound(mat[j].begin(), mat[j].end(), p-delay);
			auto it_r = upper_bound(mat[j].begin(), mat[j].end(), p+delay);
			int l = it_l-mat[j].begin();
			int r = it_r-mat[j].begin();
			// cerr << "  j = " << j << ' ';
			// cerr << "    l = " << l << " r = " << r << '\n';
			if (l < r) {
				now.add(l, r-1, bef.sum(j));
			}
		}
		// cerr << "i = " << i << '\n';
		// for (int j = 1; j <= k; j++)
		// 	cerr << now.sum(j) << ' ';
		// cerr << '\n';
		bef = now;
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)
		ans = (ans + bef.sum(i))%MOD;
	cout << ans << '\n';



	return 0;
}
