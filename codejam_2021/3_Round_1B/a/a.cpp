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

	const int DIV = 1e9;
	const int MAXV = 3600*12;

	vector<vi> all_times;
	vector<vi> all_angles;
	vi base = {0, 0, 0};
	vi angles = {0, 0, 0};
	for (int i = 0; i < MAXV; i++) {
		all_times.push_back(base);
		base[2]++;
		if (base[2] == 60)
			base[1]++, base[2] = 0;
		if (base[1] == 60)
			base[0]++, base[1] = 0;

		all_angles.push_back(angles);
		angles[2] = (angles[2] + 720)%MAXV;
		angles[1] = (angles[1] + 12)%MAXV;
		angles[0] = (angles[0] + 1)%MAXV;

		// if (angles[2] == 0) {
		// 	if (angles[1] == 0)
		// }

		// if (i > MAXV-100) {
		// 	cerr << "i(" << i << "): ";
		// 	for (int v : base)
		// 		cerr << v << ' ';
		// 	cerr << ": ";
		// 	for (int v : angles)
		// 		cerr << v << ' ';
		// 	cerr << '\n';
		// }

		// if (angles[0] == 0) {
		// 	for (int v : angles)
		// 		cerr << v << ' ';
		// 	cerr << '\n';
		// }
		// for (int i = 2; i <= 1; i--)
		// 	if (angles[i] == MAXV) {
		// 		angles[i] = 0;
		// 		angles[i-1]++;
		// 	}
	}
	// for (int v : all_angles.back())
	// 	cerr << v << ' ';
	// cerr << '\n';

	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a /= DIV;
		b /= DIV;
		c /= DIV;
		// cerr << "inp: " << a << ' ' << b << ' ' << c << '\n';
		// Now, 1 tick is 1 second
		// Range is [0, 12*3600]
		vi vec = {(int)a, (int)b, (int)c};
		sort(ALL(vec));
		int ans = -1;
		do {
			for (int shift = 0; ans == -1 and shift < MAXV; shift++) {
				// if (x == y and y == z and x == 0) cerr << "here!\n";
				vi to_search = {(int)(vec[0]+shift)%MAXV,
								(int)(vec[1]+shift)%MAXV,
								(int)(vec[2]+shift)%MAXV};
				auto it = lower_bound(ALL(all_angles), to_search);
				if (it != all_angles.end() and *it == to_search) {
					ans = it - all_angles.begin();
					// cerr << "pos = " << pos << '\n';
				}
			}
		} while(ans == -1 and next_permutation(ALL(vec)));
		cout << "Case #" << cs << ":";
		for (int v : all_times[ans])
			cout << ' ' << v;
		cout << " 0\n";
	}

	return 0;
}
