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
		string s;
		cin >> s;
		int amnt1 = 0;
		for(char c : s)
			amnt1 += c=='1';
		if(amnt1==0) {
			cout << 1 + (n-1)/(k+1) << '\n';
		} else {
			// Before 1
			int ans = 0;
			int st = 0;
			for(int i = 0; i < n; i++) {
				if(s[i] == '1') break;
				st++;
			}
			if(st-k > 0)
				ans += 1+(st-k)/(k+1);
			// After last 1
			reverse(ALL(s));
			int en = 0;
			for(int i = 0; i < n; i++) {
				if(s[i] == '1') break;
				en++;
			}
			if(en-k > 0)
				ans += (en-2)/(k+1);
			reverse(ALL(s));

			// Mid

			

		}
	}

	return 0;
}
