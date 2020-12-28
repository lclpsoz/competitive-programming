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

string solve (int k, vi &positions, string &s) {
	int n = LEN(s);

	int cnt_digits = min(20, k);
	int msk = (1<<cnt_digits)-1;
	vi vec;
	for (int p : positions) {
		// cerr << "p = " << p << '\n';
		int num = 0;
		int pot = 0;
		for (int i = p+cnt_digits-1; i >= p; i--) {
			if (s[i] == '0')
				num |= (1<<pot);
			++pot;
		}
		vec.push_back(num);
	}
	sort(ALL(vec));
	// vec.resize(unique(ALL(vec))-vec.begin());

	// for (int i : vec)
	// 	cerr << i << ": " << bitset<20>(i) << '\n';
	for (int i = 0; i < LEN(vec); i++)
		if (vec[i] != i) {
			string ret = "";
			for (int j = 0; j < k-cnt_digits; j++)
				ret.push_back('0');
			for (int j = cnt_digits-1; j >= 0; j--) {
				if (i&(1<<j))
					ret.push_back('1');
				else
					ret.push_back('0');
			}
			return ret;
		}
	if (LEN(vec) and vec.back() == msk)
		return "";
	else {
		if (LEN(vec) == 0)
			vec.push_back(-1);
		int i = ++vec.back();
		string ret = "";
		for (int j = 0; j < k-cnt_digits; j++)
			ret.push_back('0');
		for (int j = cnt_digits-1; j >= 0; j--) {
			if (i&(1<<j))
				ret.push_back('1');
			else
				ret.push_back('0');
		}
		return ret;
	}

}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		// cerr << "\nt = " << t << '\n';

		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vi positions;
		int cnt0 = 0;
		if (k <= 20) {
			for (int i = 0; i <= n-k; i++)
				positions.push_back(i);
		}
		else {
			int cnt_digits = 20;
			for (int i = 0; i < k-cnt_digits-1; i++)
				cnt0 += s[i]=='0';
			for (int i = 0; i <= n-k; i++) {
				// cerr << "i = " << i << '\n';
				cnt0 += s[i + (k-cnt_digits-1)]=='0';
				if (!cnt0) {
					positions.push_back(i+(k-cnt_digits));
					// cerr << "  p = " << positions.back() << '\n';
				}
				cnt0 -= s[i]=='0';
			}
		}
		string ans = solve(k, positions, s);
		if (LEN(ans) == k)
			cout << "YES\n" << ans << '\n';
		else
			cout << "NO\n";
	}

	return 0;
}
