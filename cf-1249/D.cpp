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

int n, k;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d %d", &n, &k);
	vector<pair<pii, pii>> vec;
	for(int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.push_back({{x, 0}, {-y, i}});
		vec.push_back({{y, 1}, {-y, i}});
	}
	sort(ALL(vec));
	set<pii> st;
	vector<int> ans;
	for(auto p : vec) {
		// printf("  x = %d, st = %d\n", p.x.x, p.x.y);
		if(p.x.y) st.erase(p.y);
		else {
			if(LEN(st) < k)
				st.insert(p.y);
			else {
				// printf("HERE!\n");
				auto pp = *st.begin();
				if(-pp.x > -p.y.x) {
					ans.push_back(pp.y);
					st.erase(pp);
					st.insert(p.y);
				} else
					ans.push_back(p.y.y);
			}
		}
		// printf("st = %d\n", LEN(st));
	}
	printf("%d\n", LEN(ans));
	for(int i = 0; i < LEN(ans); i++)
		printf("%d%c", ans[i], " \n"[i==LEN(ans)-1]);

	return 0;
}
