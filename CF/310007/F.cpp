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

using pll = pair<ll, ll>;

ll cross (pll a, pll b) { return a.x*b.y - a.y*b.x; }

ll dot (pll a, pll b) { return a.x*b.x + a.y*b.y; }

int quarter(pll a) {
	if(a.x >= 0 and a.y >= 0)
	    return 1;
	else if(a.x < 0 and a.y >= 0)
	    return 2;
	else if(a.x < 0 and a.y < 0)
	    return 3;
	return 4;
}
bool cmp_radial(const pll &lhs, const pll &rhs) {
	if(quarter(lhs) == quarter(rhs))
	    return cross(lhs, rhs) > 0;
	return quarter(lhs) < quarter(rhs);
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pll> vec;
		while (n--) {
			pll a, b;
			cin >> a.x >> a.y >> b.x >> b.y;
			b.x -= a.x;
			b.y -= a.y;
			vec.push_back(b);
		}
		sort(ALL(vec), cmp_radial);

		vector<pll> pts;
		vi cnt;
		for (int i = 0; i < LEN(vec); i++) {
			if (LEN(pts) == 0 or cross(pts.back(), vec[i]) or dot(pts.back(), vec[i]) < 0) {
				pts.push_back(vec[i]);
				cnt.push_back(1);
			}
			else
				cnt.back()++;
		}
		// cerr << "LEN(pts) = " << LEN(pts) << '\n';
		int l = 0, r = 1;
		ll ans = 0;
		while (l < LEN(pts) and r < LEN(pts)) {
			while (r < LEN(pts) and cross(pts[l], pts[r]) > 0)
				++r;
			if (r == LEN(pts)) break;
			if (dot(pts[l], pts[r]) < 0 and cross(pts[l], pts[r]) == 0)
				ans += cnt[l]*1LL*cnt[r];
			++l;
			if (l == r) ++r;
		}
		cout << ans << '\n';
	}

	return 0;
}
