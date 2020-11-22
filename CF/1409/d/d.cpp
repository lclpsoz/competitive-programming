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

// llu base10[20];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// llu base = 10;
	// for(int i = 1; i < 20; i++) {
	// 	base10[i] = base;
	// 	base *= 10;
	// }

	int t;
	cin >> t;
	while(t--) {
		string s;
		int mx;
		cin >> s >> mx;
		llu ans = 0;
		llu base = 1;
		int sum = 0;
		reverse(ALL(s));
		s += "0";
		for(char &c : s) {
			c-='0';
			sum += c;
		}
		for(int i = 0; sum > mx and i < LEN(s)-1; i++) {
			// cout << sum << ' ' << base << '\n';
			if(s[i] == 10) {
				s[i] = 0;
				sum -= 9;
				s[i+1]++;
			}
			else if(s[i]) {
				sum -= s[i];
				ans += (10-s[i])*base;
				s[i] = 0;
				s[i+1]++;
				sum++;
			}
			base *= 10;
		}
		cout << ans << '\n';
	}

	return 0;
}
