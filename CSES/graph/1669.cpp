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

const int N = 1e5 + 10;

vi adj[N];
vi cur;
int color[N];

int dfs (int v, int p) {
	if (color[v] == 1) {
		vi ans;
		ans.push_back(v);
		while (cur.back() != v) {
			ans.push_back(cur.back());
			cur.pop_back();
		}
		ans.push_back(cur.back());
		reverse(ALL(ans));
		cout << LEN(ans) << '\n';
		for (int i = 0; i < LEN(ans); i++)
			cout << ans[i] << " \n"[i==LEN(ans)-1];
		exit(0);
	}
	cur.push_back(v);
	color[v] = 1;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	cur.pop_back();
	color[v] = 2;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!color[i])
			dfs(i, i);
	cout << "IMPOSSIBLE\n";

	return 0;
}
