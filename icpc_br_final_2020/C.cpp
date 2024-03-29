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
	cin >> n;
	vi vec_base(n);
	ll total = 0;
	for (int &x : vec_base) {
		cin >> x;
		total += x;
	}
	ll parc = total/n;
	vi vec = vec_base;
	ll ans = 0;
	ll now = 0;
	ll mov = 0;
	for (int i = 0; i < 2*n; i++) {
		int j = i%n;
		if (vec[j] > parc) {
			mov += vec[j] - parc;
			vec[j] = parc;
		}
		else if (vec[j] < parc) {
			int df = min(parc-vec[j], mov);
			vec[j] += df;
			mov -= df;
		}
		// cerr << i << ' ' << mov << '\n';

		now += mov;
	}
	ans = now;
	// for (int i = 0; i < n; i++)
	// 	cerr << vec[i] << '\n';

	now = 0;
	mov = 0;
	vec = vec_base;
	reverse(ALL(vec));
	// for (int i = 0; i < n; i++)
	// 	cerr << vec[i] << ' ';
	// cerr << '\n';
	for (int i = 0; i < 2*n; i++) {
		int j = i%n;
		if (vec[j] > parc) {
			mov += vec[j] - parc;
			vec[j] = parc;
		}
		else if (vec[j] < parc) {
			int df = min(parc-vec[j], mov);
			vec[j] += df;
			mov -= df;
		}

		now += mov;
	}
	// for (int i = 0; i < n; i++)
	// 	cerr << vec[i] << '\n';
	cout << min(ans, now) << '\n';

	return 0;
}
