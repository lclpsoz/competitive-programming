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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

set<pii> st;
int a[N];

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		auto it = st.lower_bound({a[i]-1, -1});
		// if(it != st.end())
		// 	it--;
		// if(it != st.end()) {
		// 	cout << i << '\n';
		// 	cout << it->x << ' ' << it->y << '\n';
		// }
		if(it == st.end() or it->x > a[i]-1) {
			st.insert({a[i], 1});

		} else {
			auto it2 = st.lower_bound({a[i], -1});
			if(it2 == st.end() or it2->x > a[i] or it2->y < it->y+1) {
				pii val = *it;
				st.erase(it);
				val.x++;
				val.y++;
				st.insert(val);
			}
		}
	}

	int val = -1, mx = -1;
	for(auto p : st) {
		if(p.y > mx) {
			// cout << "mx = " << mx << '\n';
			mx = p.y;
			// cout << "mx = " << mx << '\n';
			val = p.x;
		}
	}
	val -= mx-1;
	vector<int> ans;
	for(int i = 1; i <= n; i++) {
		if(a[i] == val) {
			ans.push_back(i);
			val++;
		}
	}
	cout << LEN(ans) << '\n';
	for(int i = 0; i < LEN(ans); i++)
		cout << ans[i] << ' ';

	return 0;
}
