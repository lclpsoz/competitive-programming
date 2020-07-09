#include <bits/stdc++.h>
using namespace std;

// ------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

// ------------

const int N = 1e5+100;
const int INF = 1e9;

int n, m;
vector<pii> adj[N];
int dist[N];
int ans[5];
bool vis[N][5];

void dijkstra () {
	ans[0] = ans[1] = ans[2] = INF;
	
	set<pair<int, pii>> st;
	st.insert ({0, {1, 0}});
	while (!st.empty()) {
		int w = st.begin()->x, v = st.begin()->y.x, q = st.begin()->y.y;
		st.erase (st.begin());
		if (vis[v][q]) continue;
		vis[v][q] = true;
		if (v == n) {
			ans[q] = w;
			continue;
		}
		for (pii p : adj[v])
			st.insert ({w+p.y, {p.x, (q+1)%3}});
	}
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		scanf ("%d %d %d", &x, &y, &w);
		adj[x].push_back ({y, w});
		adj[y].push_back ({x, w});
	}
	
	dijkstra();
	vector<pair<int, string>> vec;
	vec.push_back ({ans[0], "me"});
	vec.push_back ({ans[1], "Gon"});
	vec.push_back ({ans[2], "Killua"});
	sort (vec.begin(), vec.end());
	
	for (auto p : vec)
		cout << p.y << '\n';
	
	return 0;
}