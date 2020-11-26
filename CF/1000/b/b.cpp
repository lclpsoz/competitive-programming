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

	int n, m;
	cin >> n >> m;
	vi vec;
	vec.push_back(0);
	while(n--) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	vec.push_back(m);
	vi pref(LEN(vec)+5);
	vi suf(LEN(vec)+5);
	for(int i = 1; i < LEN(vec); i++) {
		pref[i] += vec[i]-vec[i-1];
		if(i>1)
			pref[i] += pref[i-2];
		// cout << "pref[" << i << "] = " << pref[i] << '\n';
	}
	for(int i = LEN(vec)-1; i; i--) {
		suf[i] += suf[i+2]+vec[i]-vec[i-1];
		// cout << "suf[" << i << "] = " << suf[i] << '\n';
	}
	int ans = suf[1];
	bool active = true;
	for(int i = 1; i < LEN(vec); i++) {
		int cur = 0;
		if(vec[i]-vec[i-1] > 1) {
			if(active)
				cur = (i-2 >= 0 ? pref[i-2] : 0)
								+ vec[i]-vec[i-1]-1 + suf[i+1];
			else
				cur = pref[i-1] + vec[i]-vec[i-1]-1 + suf[i+2];
		}
		// cerr << "cur[" << i << "] = " << cur << '\n';
		ans = max(cur, ans);
	
		active = !active;
	}
	cout << ans << '\n';


	return 0;
}
