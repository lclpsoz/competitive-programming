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
		int n;
		cin >> n;
		vi ans(n+2);
		set<pair<int, pii>> st;
		st.insert({-n, {1, n}});
		int id = 1;
		while(!st.empty()) {
			int l = st.begin()->y.x;
			int r = st.begin()->y.y;
			// cout << l << ' ' << r << '\n';
			int md = (l+r)/2;
			ans[md] = id++;
			st.erase(st.begin());
			if(l < md)
				st.insert({-((md-1)-l+1), {l, md-1}});
			if(md < r)
				st.insert({-((r-(md+1)+1)), {md+1, r}});
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " \n"[i==n];
	}

	return 0;
}
