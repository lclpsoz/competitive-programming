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

const int N = 1010;

int m, n, g, k;
int pd[N], cost[N];
vector<int> adj[N], monsters[N];
bool vis[N];

int dijkstra () {
	set<pii> st;
	memset (vis, false, sizeof vis);
	
	st.insert ({cost[1], 1});
	while (!st.empty() and st.begin()->y != n) {
		int u = st.begin()->y, w = st.begin()->x;
		st.erase (st.begin());
		if (vis[u]) continue;
		vis[u] = true;
		
		for (int v : adj[u])
			st.insert ({w + cost[v], v});
	}
	
	return st.empty() ? -1 : st.begin()->x;
}

int main () {
	while (scanf ("%d %d %d %d", &m, &n, &g, &k), m) {
		for (int i = 0; i < N; i++) {
			pd[i] = 1e9;
			adj[i].clear();
			monsters[i].clear();
		}
		pd[0] = 0;
		
		for (int j = 0; j < m; j++) {
			int mana, dam;
			scanf ("%d %d", &mana, &dam);
			for (int i = dam; i <= 1000; i++)
				pd[i] = min (pd[i], pd[i-dam]+mana);
		}
		for (int i = 1000; i >= 1; i--) {
			pd[i] = min (pd[i], pd[i+1]);
		}
		
		for (int i = 0; i < g; i++) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].push_back (v);
			adj[v].push_back (u);
		}
		
		for (int i = 0; i < k; i++) {
			int v, life;
			scanf ("%d %d", &v, &life);
			monsters[v].push_back (life);
		}
		
		for (int i = 1; i <= n; i++) {
			int &mana = cost[i];
			mana = 0;
			for (int life : monsters[i])
				mana += pd[life];
		}
		
		printf ("%d\n", dijkstra());
	}

	return 0;
}
