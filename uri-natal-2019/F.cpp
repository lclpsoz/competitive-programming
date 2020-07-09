#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e6 + 10;

int n;
map<string, ll> mp;
map<string, int> mpId;
string backId[N];
vector<pair<int, ll>> adj[N];
queue<int> q;
bitset<N> vis;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (auto p : adj[v]) {
		int u = p.x;
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n;
	ll c;
	int id = 0;
	while (n--) {
		string s;
		cin >> s >> c;
		mp[s] = c;
		q.push (id);
		backId[id] = s;
		mpId[s] = id++;
	}
	string p1, p2;
	int from = id;
	while (cin >> p1) {
		cin >> p2 >> c;
		if (mpId.count (p1) == 0) {
			backId[id] = p1;
			mpId[p1] = id++;
		}
		adj[mpId[p2]].push_back ({mpId[p1], c});
	}
	n = id;

	// while (!q.empty()) {
	// 	int now = q.front();
	// 	q.pop();
	// 	if (vis[now]) continue;
	// 	vis[now] = true;
	// 	cout << now << ' ' << backId[now] << '\n';
	// 	int costNow = mp[backId[now]];
	// 	for (auto p : adj[now]) {
	// 		int nxt = p.x;
	// 		c = p.y;
	// 		mp[backId[nxt]] += costNow*c;
	// 		q.push (nxt);
	// 	}
	// }

	topological_sort();
	for (int i = 0; i < n; i++) {
		// cout << i << ' ' << backId[i] << '\n';
		for (auto p : adj[i])
			mp[backId[p.x]] += p.y * mp[backId[i]];
	}

	for (auto p : mp)
		if (mpId[p.x] >= from)
			cout << p.x << ' ' << p.y << '\n';

	return 0;
}
