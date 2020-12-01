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

	int t, n;
	cin >> t;
	// map<int, int> dist;
	// int to_calc = 1e6;

	// set<int> vals;
	// vals.insert(0);
	// for(int i = 1; i<=300; i++) {
	// 	cerr << i << ' ' << LEN(vals) << '\n';
	// 	vi nxt;
	// 	for(int v:vals) {
	// 		nxt.push_back(v-1);
	// 		nxt.push_back(v+i);
	// 	}
	// 	vals.clear();
	// 	for(int v : nxt) {
	// 		if(v <= 1001000) {
	// 			if(dist.count(v) == 0) dist[v] = i;
	// 			vals.insert(v);
	// 		}
	// 	}
	// }
	// for(int i = 1; i <= 100; i++)
	// 	cerr << i << ' ' << dist[i] << '\n';
	vi ans(2000100);
	ans[0] = 0;
	int now = 0;
	for(int i = 1; now+i < LEN(ans) ;i++) {
		now += i;
		for(int j = now-2; j>0 and ans[j] == 0; j--) ans[j] = i;
		ans[now] = i;
		ans[now-1] = i+1;
	}
	// for(int i = 1000000-100; i <= 1000000; i++) {
	// 	// cerr << i << ' ' << ans[i] << ' ' << dist[i] << '\n';
	// 	// assert(ans[i] == dist[i]);
	// 	cerr << i << ' ' << ans[i] << '\n';
	// }

	while(t--) {
		cin >> n;
		// int x = 0;
		// int ans = 0;
		cout << ans[n] << '\n';
	}

	return 0;
}
