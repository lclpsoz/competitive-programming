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

	int n;
	string s;
	cin >> n >> s;
	vi vec;
	char bef = s[0];

	vec.push_back(0);
	for (char c : s) {
		if (c == bef) {
			vec.back()++;
		}
		else {
			vec.push_back(1);
			bef = c;
		}
	}

	reverse(ALL(vec));
	int ans = 0;
	int p = LEN(vec)-1;
	while (LEN(vec)) {
		p = min(p, LEN(vec)-1);
		while (p and vec[p] == 1)
			--p;
		if (p == 0 and vec[p] == 1)
			vec.pop_back();
		else
			vec[p]--;
		++ans;
		if (LEN(vec))
			vec.pop_back();
		// cerr << "p = " << p << ' ' << "LEN(vec) = " << LEN(vec) << '\n';
	}
	cout << ans << '\n';

	return 0;
}
