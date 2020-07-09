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

using pp = pair<int, pii>;
const int N = 110;

int n, e, t, m;
set<pp> st;
bool mices[N];
vector<pii> adj[N];
bool vis[N][N];

int main () {
	scanf ("%d %d %d %d", &n, &e, &t, &m);
	while (m--) {
		int a, b, w;
		scanf ("%d %d %d", &a, &b, &w);
		adj[a].push_back ({b, w});
	}
	
	for (int i = 1; i <= n; i++)
		st.insert ({0, {i, i}});
	
	int ans = 0;
	while (!st.empty()) {
		int d = st.begin()->x, id = st.begin()->y.x, v = st.begin()->y.y;
		st.erase (st.begin());
		if (d > t) continue;
		if (mices[id] or vis[id][v]) continue;
		if (v == e) {
			++ans;
			mices[id] = true;
			continue;
		}
		vis[id][v] = true;
		for (auto p : adj[v])
			st.insert ({d+p.y, {id, p.x}});
	}
	printf ("%d\n", ans);

	return 0;
}
