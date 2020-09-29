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

string prt(int ax, int k, int amnt9=0, int seq9=111) {
	if(ax < 9-(k-amnt9)) {
		return to_string(ax);
	} else {
		vector<char> vec;
		vec.push_back(9-(k-amnt9)+'0');
		ax -= 9-(k-amnt9);
		seq9--;
		while(ax >= 9 and seq9--) {
			vec.push_back('9');
			ax-=9;
		}
		if(ax >= 8) {
			vec.push_back('8');
			ax-=8;
		}
		while(ax >= 9) {
			vec.push_back('9');
			ax-=9;
		}
		if(ax)
			vec.push_back(ax+'0');
		reverse(ALL(vec));
		return string(ALL(vec));
	}
}

string solve(int n, int k) {
	if(k == 0)
		return prt(n, 0);
	else {
		int pa = (k*(k+1))/2;
		if(pa > n) {
			return "-1";
		} else if((n-pa)%(k+1) == 0) {
			int ax = (n-pa)/(k+1);
			return prt(ax, k);
		} else {
			for(int val9 = 9; val9 <= n; val9+=9)
				for(int amnt9 = 1; amnt9 <= k; amnt9++) {
					int aux = n - pa + val9*amnt9;
					if(aux > 0 and aux%(k+1) == 0 and (aux/(k+1)) >= val9-(k-amnt9))
						return prt(aux/(k+1), k, amnt9, val9/9);
				}
		}
	}
	return "-1";
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << solve(n, k) << '\n';
	}

	return 0;
}
