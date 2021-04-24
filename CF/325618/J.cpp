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

vector<vector<pair<int, pair<int, int>>>> adj(1001, vector<pair<int, pair<int, int>>>());
int n, T;

bool is_valid(int cut, int &time) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, 1});
	vector<int> dist(n + 1, 1e9 + 1);
	dist[1] = 0;
	while (!q.empty()) {
		auto [t, v] = q.top();
		q.pop();
		for (auto info : adj[v]) {
			int u = info.first;
			int d = info.second.first;
			int s = info.second.second;
			if (s <= cut && dist[v] + d < dist[u]) {
				dist[u] = dist[v] + d;
				q.push({dist[u], u});
			}
		}
	}
	time = dist[n];
	return dist[n] <= T;
}

int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d, s;
		cin >> a >> b >> d >> s;
		adj[a].push_back({b, {d, s}});
		adj[b].push_back({a, {d, s}});
	}
	cin >> T;
	int l = 0, r = 1e9;
	int time;
	while (l < r) {
		int m = (l + r) / 2;
		if (is_valid(m, time)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	if (l >= 1e9)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		is_valid(l, time);
		cout << l << " " << time << endl;
	}
	return 0;
}
