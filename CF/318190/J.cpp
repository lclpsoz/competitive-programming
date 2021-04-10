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
	vi a(n);
	for (int &x : a)
		cin >> x;

	int m;
	cin >> m;
	vector<vi> adj(n+1);
	while (m--) {
		for (int i = 1; i <= n; i++) {
			int nxt;
			cin >> nxt;
			adj[i].push_back(nxt);
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(ALL(adj[i]));
		adj[i].resize(unique(ALL(adj[i])) - adj[i].begin());
	}

	int x;
	cin >> x;
	bitset<200010> msk;
	vi new_vals;
	for (int i = 1; i <= n; i++)
		if (a[i-1] == x) {
			msk[i] = 1;
			new_vals.push_back(i);
			break;
		}
	for (int i = 0; i < n; i++) {
		vi nxt_new_vals;
		for (int v : new_vals)
			for (int u : adj[v]) {
				if (!msk[u])
					nxt_new_vals.push_back(u);
				msk[u] = 1;
			}
		new_vals = nxt_new_vals;
	}
	cout << (msk[1] ? "YES" : "NO") << '\n';

	return 0;
}
