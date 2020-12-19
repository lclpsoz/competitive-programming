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
string div (llu a, llu b, int n) {
	string s = "";
	// while (a < b) a*=10;
	while (a and LEN(s) < n) {
		if (a < b) {
			a*=10;
			while (a < b and LEN(s) < n) {
				a*=10;
				s.push_back('0');
			}
		}
		if (LEN(s) < n)
			s.push_back((char)(a/b+'0'));
		a %= b;
	}
	while (LEN(s) < n)
		s.push_back('0');
	
	return s;
}

int brute (string s, int p) {
	int ret = 0;
	assert(LEN(s) <= 19);
	for (int i = 0; i < LEN(s); i++)
		for (int j = 1; j <= LEN(s)-i; j++) {
			ret += (stoull(s.substr(i, j))%p == 0);
		}
	return ret;
}

// void brute_div () {
// 	for (int i = 1; i <= 1000; i++)
// 		for (int j = 1; j <= 1000; j++) {
// 			if (i < j) {
// 				// cerr << setprecision(20) << fixed << (ld)i/j << '\n';
// 				ld ax = (ld)i/j;
// 				int cnt = 0;
// 				while (ax < 1) {
// 					ax *= 10;
// 					++cnt;
// 				}
// 				if (cnt > 1) continue;
// 				string val = to_string((ll)((ll)floor(((ld)i/j)*1e11))/100);
// 				// cerr << "val = " << val << '\n';
// 				if (val != div(i, j, 9)) {
// 					cerr << i << "/" << j << '\n';
// 					cerr << (ld)i/j*1e10 << '\n';
// 					cerr << "  " << val << '\n';
// 					cerr << "  " << div(i, j, 9) << '\n';
// 				}
// 			}
// 		}
// 	exit(0);
// }

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// brute_div();

	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		int n, p;
		cin >> a >> b >> n >> p;
		string s = div (a, b, n);
		vi dp(n);
		int base = 1;
		// cerr << "s = " << s << '\n';
		// cerr << "brute = " << brute(s, p) << '\n';
		vi vec(p), bef(p);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int now = s[i]-'0';
			for (int j = 0; j < p; j++)
				vec[j] = 0;
			for (int j = 0; j < p; j++)
				vec[(j*10 + now)%p] += bef[j];
			vec[now%p]++;
			ans += vec[0];
			// cerr << "vec = " << vec[0] << '\n';
			for (int j = 0; j < p; j++)
				bef[j] = vec[j];
		}
		cout << ans << '\n';
	}

	return 0;
}
