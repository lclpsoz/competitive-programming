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

const int block_size = 800;

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query {
	int l, r;
	int id;
	long long ord;
	inline void calcOrder() {
		ord = hilbertOrder(l, r, 21, 0);
	}
};

inline bool operator<(const query &a, const query &b) {
	return a.ord < b.ord;
}

const int N = 5e5 + 10;
int cnt[N], v[N], n, q, ans, mp[N], anss[N];

inline void add(int p)
{
	if(++cnt[v[p]] > 1)
		ans ^= mp[v[p]];
}
inline void del(int p)
{
	if(--cnt[v[p]] > 0)
		ans ^= mp[v[p]];
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	while(cin >> n >> q)
	{
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[i] = v[i];
		}

		sort(mp, mp + n);
		int sz = unique(mp, mp + n) - mp;

		for (int i = 0; i < n; i++)
			v[i] = lower_bound(mp, mp + sz, v[i]) - mp;

		vector<query> queries(q);
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			queries[i] = {l, r, i};
			queries[i].calcOrder();
		}
		sort(queries.begin(), queries.end());
		for (int i = 0; i < queries.size(); i++) {
			cout << queries[i].l << " " << queries[i].r << endl;
		}

		int cur_l = 0;
		int cur_r = -1;
		for (int i = 0; i < q; i++) {
			int l = queries[i].l;
			int r = queries[i].r;
			int id = queries[i].id;
			l--, r--;
			while (cur_l > l) {
				cur_l--;
				add(cur_l);
			}
			while (cur_r < r) {
				cur_r++;
				add(cur_r);
			}
			while (cur_l < l) {
				del(cur_l);
				cur_l++;
			}
			while (cur_r > r) {
				del(cur_r);
				cur_r--;
			}
			anss[id] = ans;
		}

		while(cur_l <= cur_r) del(cur_l++);

		for (int i = 0; i < q; i++)
			;//cout << anss[i] << '\n';
	}


	return 0;
}
