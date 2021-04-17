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

	int n, m;
	cin >> n >> m;
	vector<pair<int, set<int>>> people(m+1, {1, {}}); //{upper_bound, id_event}
	vi cnt_event(n+1);
	for (int i = 1; i <= n; i++) {
		int q, maxi;
		cin >> q >> maxi;
		while (q--) {
			int p_pos;
			cin >> p_pos;
			auto &[p_up, p_ids] = people[p_pos];
			if (LEN(p_ids) == 0 or p_up == maxi) {
				p_up = maxi;
				p_ids.insert(i);
				cnt_event[i]++;
			}
			else if (p_up > maxi) {
				p_up = maxi;
				for (int x : p_ids)
					cnt_event[x]--;
				p_ids.clear();
				p_ids.insert(i);
				cnt_event[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!cnt_event[i]) {
			cout << "Poor memory\n";
			exit(0);
		}
	cout << "Good memory\n";
	for (int i = 1; i <= m; i++)
		cout << people[i].x << " \n"[i==m];

	return 0;
}
