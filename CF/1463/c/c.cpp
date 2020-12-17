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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<ll, int>> commands(n);
		for (auto &[tm, x] : commands)
			cin >> tm >> x;
		commands.push_back({INF<ll>, INF<ll>});

		bool ready = true;
		int pos = 0;
		int target = INF<int> + 1;
		int ans = 0;
		for (int i = 0; i < LEN(commands)-1; i++) {
			// cerr << "i = " << i << '\n';
			// cerr << "  ready = " << ready << '\n';
			// cerr << "  pos = " << pos << '\n';
			// cerr << "  target = " << target << "\n\n";

			auto [tm_now, x_now] = commands[i];
			auto [tm_nxt, x_nxt] = commands[i+1];
			ll tm_delta = tm_nxt-tm_now;
			if (ready) {
				if (abs (pos-x_now) <= tm_delta) {
					++ans;
					ready = true;
					pos = x_now;
				}
				else {
					ready = false;
					target = x_now;
					if (x_now < pos)
						pos -= tm_delta;
					else
						pos += tm_delta;
				}
			}
			else {
				int pos_new = INF<int>+1;
				if (abs(target-pos) <= tm_delta) {
					ready = true;
					pos_new = target;
				}
				else if (target < pos)
					pos_new = pos-tm_delta;
				else
					pos_new = pos+tm_delta;

				if ((pos_new <= pos and pos_new <= x_now and x_now <= pos) or
					(pos_new >= pos and pos <= x_now and x_now <= pos_new))
					++ans;
				pos = pos_new;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
