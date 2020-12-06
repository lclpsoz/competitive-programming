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

vi rotate (int n, int m, vi &ori) {
	if (LEN(ori) == n) {
		vi ret(m);
		sort(ALL(ori));
		int cur = 0;
		for (int i = m; i >= 1; i--) {
			while (LEN(ori) and ori.back() >= i) {
				cur++;
				ori.pop_back();
			}
			ret[i-1] = cur;
		}
		return ret;
	}
	else {
		vi ret(n);
		sort(ALL(ori));
		int cur = 0;
		for (int i = n; i >= 1; i--) {
			while (LEN(ori) and ori.back() >= i) {
				cur++;
				ori.pop_back();
			}
			ret[i-1] = cur;
		}
		return ret;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m, r;
	cin >> n >> m >> r;

	vi vec(n);
	for (int &v : vec) cin >> v;
	
	if (r > 8)
		r = 4 + r%4;

	for (int i = 0; i < r; i++) {
		vec = rotate(n, m, vec);
		// for(int v : vec)
		// 	cerr << v << ' ';
		// cerr << '\n';
	}
	for (int i = 0; i < LEN(vec); i++)
		cout << vec[i] << " \n"[i==LEN(vec)-1];


	return 0;
}
