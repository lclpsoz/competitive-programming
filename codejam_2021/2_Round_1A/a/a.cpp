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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	for (int t_now = 1; t_now <= t; t_now++) {
		int n;
		cin >> n;
		vector<string> vec(n);
		for (string &x : vec)
			cin >> x;
		int ans = 0;
		for (int i = 1; i < n; i++) {
			string &bef = vec[i-1];
			string &now = vec[i];
			if (LEN(now) <= LEN(bef)) {
				bool lex_smaller = false;
				bool lex_larger = false;
				for (int j = 0; !lex_smaller and !lex_larger and j < LEN(now); j++)
					if (now[j] < bef[j])
						lex_smaller = true;
					else if (now[j] > bef[j])
						lex_larger = true;
				if (lex_smaller)
					while (LEN(now) <= LEN(bef)) {
						now += '0';
						++ans;
					}
				else if (lex_larger) {
					while (LEN(now) < LEN(bef)) {
						now += '0';
						++ans;
					}
				}
				else {
					bool just_add = false;
					for (int j = LEN(now); !just_add and j < LEN(bef); j++)
						if (bef[j] != '9')
							just_add = true;
					if (just_add) {
						ans += LEN(bef) - LEN(now);
						bef.back()++;
						int pos = LEN(bef)-1;
						while (bef[pos] > '9') {
							bef[pos] = '0';
							--pos;
							bef[pos]++;
						}
						now = bef;
					}
					else {
						while (LEN(now) <= LEN(bef)) {
							now += '0';
							++ans;
						}
					}
				}
			}
		}
		cout << "Case #" << t_now << ": " << ans << '\n';
		// for (string s : vec)
		// 	cerr << s << '\n';
	}

	return 0;
}
