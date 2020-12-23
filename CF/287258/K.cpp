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
int dfs1 (int v, int p, vector<vi> &adj, vi &far) {
	far[v] = 1;
	for (int u : adj[v]) {
		if (u != p) {
			far[v] = max(far[v], dfs1(u, v, adj, far) + 1);
		}
	}

	return far[v];
}

void dfs2 (int v, int p, vector<vi> &adj, vi &far1, vi &far2) {
	for (int u : adj[v]) {
		// cerr << "u(" << u << ") = " << far1[u] << '\n';
		far2[v] = max(far2[v], far1[u]+1);
	}

	int mx1, mx2;
	mx1 = 0, mx2 = 0;
	for (int u : adj[v])
		if (mx1 < far1[u]) {
			mx2 = mx1;
			mx1 = far1[u];
		}
		else
			mx2 = max(mx2, far1[u]);
	for (int u : adj[v]) {
		if (u != p) {
			int mx = mx1;
			if (mx1 == far1[u])
				mx = mx2;
			far1[v] = mx + 1;
			dfs2(u, v, adj, far1, far2);
		}
	}
}

ld prob_finish (vector<vi> &adj, int k) {
	int n = LEN(adj)-1;
	vi far1(n+1), far2(n+1);

	dfs1(1, 1, adj, far1);
	dfs2(1, 1, adj, far1, far2);

	// for (int i = 1; i <= n; i++)
	// 	cerr << i << ": " << far2[i] << '\n';

	int ok = 0;
	for (int i = 1; i <= n; i++)
		ok += far2[i]-1 <= k;
	return (ld)ok/n;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(4);

	int t;
	cin >> t;
	while (t--) {
		int c, k;
		cin >> c >> k;
		vector<ld> probs;
		for (int _i = 0; _i < c; _i++) {
			int n;
			cin >> n;
			vector<vi> adj(n+1);
			for (int i = 2; i <= n; i++) {
				int u;
				cin >> u;
				adj[i].push_back(u);
				adj[u].push_back(i);
			}

			probs.push_back(prob_finish(adj, k));
			// cerr << "| " << _i << ": " << probs.back() << '\n';
		}
		
		vector<ld> dp(c + 1, 0);
		for(int i = 1; i <= c; i++)
		{
			ld z = 1 / probs[i - 1];
			dp[i] = (1 + dp[i - 1]) * z + 3 * (z - 1);
		}

		cout << fixed << dp[c] << '\n';
	}

	return 0;
}
