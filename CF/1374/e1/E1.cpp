#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	
	int n, k;
	cin >> n >> k;
	int lf, rf;
	lf = rf = 0;
	vi vals;
	vi lft, rig;
	while(n--) {
		int v;
		int x, y;
		cin >> v >> x >> y;
		lf += x, rf += y;
		if(x and y)
			vals.push_back(v);
		else if(x)
			rig.push_back(v);
		else if(y)
			lft.push_back(v);
	}
	if(lf < k or rf < k) {
		cout << "-1\n";
		exit(0);
	}
	sort(ALL(lft));
	sort(ALL(rig));
	reverse(ALL(lft));
	reverse(ALL(rig));
	while(LEN(lft) and LEN(rig)) {
		vals.push_back(lft.back() + rig.back());
		lft.pop_back();
		rig.pop_back();
	}
	sort(ALL(vals));
	ll ans = 0;
	for(int i = 0; i < k; i++) ans += vals[i];
	cout << ans << '\n';

	return 0;
}
