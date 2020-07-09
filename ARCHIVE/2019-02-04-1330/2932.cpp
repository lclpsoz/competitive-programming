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

using pp = pair<pii, int>;
const int N = 2e5+10;

int n, m;
bool marked[N], edge[N];
vector<pp> adj[N];
ll ans;

pair<int, int> dfs (int v, int parent, int wei, int edgId) {
	if (v != parent and marked[v])
		return {wei, edgId};
	for (pp p : adj[v]) {
		int id = p.y;
		int u = p.x.x;
		int w = p.x.y;
		if (u != parent and !edge[id]) {
			pii now = dfs (u, v, w, id);
			if (now.x) {
				if (v == parent) {
					edge[now.y] = true;
					ans += now.x;
				} else {
					if (wei < now.x) {
						now.x = wei;
						now.y = edgId;
					}
					return now;
				}
			}
		}
	}
	
	return {0, 0};
}

int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int v;
		scanf ("%d", &v);
		marked[v] = true;
	}
	int id = 0;
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({{v, w}, id});
		adj[v].push_back ({{u, w}, id++});
		assert (w > 0);
	}
	for (int i = 0; i < n; i++)
		if (marked[i])
			dfs (i, i, 0, 0);
	printf ("%lld\n", ans);

	return 0;
}
