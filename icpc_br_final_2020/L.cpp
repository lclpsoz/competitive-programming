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

const int MAXV = 2e5 + 100;
int vec[MAXV];
//  events[MAXV];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);


	int n, x;
	cin >> n >> x;
	vpii events;
	for (int i = 0; i < n; i++) {
		int s, d;
		cin >> s >> d;
		events.push_back({s, d});
		// events[s]++;
		// events[s+d+1]--;
	}	

	int now = 0;
	// for (int i = 1; i < MAXV; i++) {
	// 	now += events[i];
	// 	if (i < 550)
	// 		cerr << i << ' ' << now << '\n';
	// 	vec[i] = now;
	// }
	int ans_time = 0;
	int ans = 1e9;
	for (int i = 0; i <= 8*60; i++) {
		now = 0;
		// for (int j = i; j < MAXV; j+=x)
		// 	now += vec[j];
		for (auto [s, d] : events) {
			int st_ev = s;
			int en_ev = s+d;
			int cnt_now = 0;
			if (en_ev >= i) {
				int dif = en_ev - i;
				cnt_now += dif/x + 1;
			}
			if (s > i) {
				s--;
				int dif = s - i;
				cnt_now -= dif/x + 1;
			}
			now += cnt_now;
		}
		// if (i < 5)
		// 	cerr << i << ' ' << now << '\n';
		if (now < ans) {
			ans = now;
			ans_time = i;
		}
	}
	cout << ans_time << ' ' << ans << '\n';

	return 0;
}
