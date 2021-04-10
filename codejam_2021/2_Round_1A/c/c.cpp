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

	int n_tests;
	cin >> n_tests;
	for (int t = 1; t <= n_tests; t++) {
		int n, q; 
		cin >> n >> q;
		vpii people;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			int msk = 0;
			for (int j = 0; j < q; j++)
				if (s[j] == 'T')
					msk |= (1 << j);
			int scr;
			cin >> scr;
			people.push_back({msk, scr});
		}
		vi answers;
		for (int i = 0; i < (1<<q); i++) {
			bool ok = true;
			for (auto [msk, scr] : people) {
				int correct = 0;
				for (int j = 0; j < q; j++)
					correct += ((msk&(1<<j)) == (i&(1<<j)));
				if (correct != scr) {
					ok = false;
					break;
				}
			}
			if (ok)
				answers.push_back(i);
		}
		
		int ans = 0;
		int scr = -1;
		for (int msk_now = 0; msk_now < (1<<q); msk_now++) {
			int acu_scr = 0;
			for (int msk_ans : answers)
				for (int i = 0; i < q; i++)
					acu_scr += ((msk_now&(1<<i)) == (msk_ans&(1<<i)));


			if (acu_scr > scr) {
				scr = acu_scr;
				ans = msk_now;
			}
		}

		cout << "Case #" << t << ": ";
		for (int i = 0; i < q; i++)
			cout << ((ans&(1<<i)) ? 'T' : 'F');
		cout << ' ';
		int a = scr;
		int b = LEN(answers);
		int md = __gcd(a, b);
		a /= md;
		b /= md;
		cout << a << "/" << b << '\n';
	}

	return 0;
}
