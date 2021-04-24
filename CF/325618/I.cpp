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

int n;
vector<vector<int>> adj(101, vector<int>());
bitset<105> vis;

bool done () {
	for (int i = 1; i <= n; i++)
		if (!vis[i]) return false;
	return true;
}

int main () {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> ans_color(n+1);

	while (!done()) {
		set<int> to_apply;

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				int cnt = 1;
				for (int v : adj[i])
					cnt += !vis[v];
				if (cnt == 2) {
					for (int v : adj[i])
						if (!vis[v]) {
							to_apply.insert(v);
							break;
						}
				}
			}
		}

		if (LEN(to_apply) == 0)
			for (int i = 1; i <= n; i++) {
				if (vis[i] != 2) {
					to_apply.insert(i);
				}
			}
		while (LEN(to_apply)) {
			int now = -1, val = 0;
			for (int v : to_apply) {
				if (vis[v] == 2) {
					to_apply.erase(v);
					now = -1;
					break;
				}
				else {
					int cnt = !vis[v];
					for (int u : adj[v])
						cnt += !vis[u];
					if (cnt > val) {
						val = cnt;
						now = v;
					}
				}
			}
			if (now != -1) {
				vis[now] = 2;
				for (int v : adj[now])
					vis[v] = 1;
				// cerr << "now = " << now << '\n';
				ans_color[now] = 1;
				to_apply.erase(now);
			}
			else if (val == 0)
				break;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans_color[i] << " \n"[i==n];

	return 0;
}
