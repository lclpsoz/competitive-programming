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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vi pts(n);
		for(int &v : pts)
			cin >> v;
		int y;
		for(int v : pts)
			cin >> y;
		sort(ALL(pts));

		vi cnt(n);
		vi en_cnt(n);
		vi cnt_mx(n+1);
		int l = 0, r = 0;
		while(l < LEN(pts)) {
			while(r < LEN(pts)-1 and pts[r+1]-pts[l] <= k) ++r;
			cnt[l] = r-l+1;
			en_cnt[l] = r;
			++l;
		}
		for(int i = n-1; i >= 0; i--)
			cnt_mx[i] = max(cnt[i], cnt_mx[i+1]);
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, cnt[i] + cnt_mx[en_cnt[i]+1]);
		cout << ans << '\n';
	}

	return 0;
}
