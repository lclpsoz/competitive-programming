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
		int sum = 0;
		vi vec(n);
		for (int &v : vec) {
			cin >> v;
			sum += v;
		}
		vi to_test;
		for (int i = 1; i*i <= sum; i++)
			if (sum%i == 0) {
				if (sum/i <= n)
					to_test.push_back(i);
				if (i <= n)
					to_test.push_back(sum/i);
			}
		int ans = n-1;
		for (int sub_sum : to_test) {
			vi now = vec;
			int cur_ans = 0;
			while (LEN(now)) {
				if (now.back() > sub_sum) {
					cur_ans = n+1;
					break;
				}
				else if (now.back() == sub_sum)
					now.pop_back();
				else if (now.back() < sub_sum) {
					int val = now.back();
					now.pop_back();
					now.back() += val;
					++cur_ans;
				}
			}

			ans = min(ans, cur_ans);
		}
		cout << ans << '\n';
	}

	return 0;
}
