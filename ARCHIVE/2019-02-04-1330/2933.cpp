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
const int N = 1e5+10, LOGN = 20;

int n, m;
vector<pii> adj[N];

// ======================== MST ======================== //
int size[N], link[N];
set<pp> st;

int find (int a) {
	if (link[a] == a) return a;
	return link[a] = find (link[a]);
}

bool same (int a, int b) { return find (a) == find (b); }

void unite (int a, int b) {
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	link[a] = b;
}

void kruskal () {
	for (int i = 0; i < n; i++) {
		size[i] = 1;
		link[i] = i;
	}
	while (!st.empty()) {
		int u = st.begin()->y.x, v = st.begin()->y.y, w = st.begin()->x;
		st.erase (st.begin());
		if (!same (u, v)) {
			unite (u, v);
// 			printf ("|%d %d %d\n", u, v, w);
			adj[u].push_back ({v, w});
			adj[v].push_back ({u, w});
		}
	}
}

// ===================================================== //

// ======================== LCA ======================== //

int depth[N];
int sparse[N][LOGN], anc[N][LOGN];

void dfs (int v = 0, int parent = 0, int w = 0, int d = 0) {
	depth[v] = d;
	sparse[v][0] = w;
	anc[v][0] = parent;
	for (auto p : adj[v])
		if (p.x != parent)
			dfs (p.x, v, p.y, d+1);
}

void buildSparse () {
	for (int i = 1; i < LOGN; i++)
		for (int j = 0; j < n; j++) {
			anc[j][i] = anc[anc[j][i-1]][i-1];
			sparse[j][i] = max (sparse[j][i-1], sparse[anc[j][i-1]][i-1]);
		}
}

int lca (int u, int v) {
	if (depth[u] > depth[v]) swap (u, v);
	int d = depth[v]-depth[u];
	int b = 0;
	int ret = 0;
	while (d) {
		if (d&1) {
			ret = max (ret, sparse[v][b]);
			v = anc[v][b];
		}
		++b;
		d>>=1;
	}
	b = LOGN-1;
	while (b >= 0 and u != v) {
		if (anc[u][b] == anc[v][b])
			--b;
		else {
			ret = max (ret, sparse[u][b]);
			ret = max (ret, sparse[v][b]);
			u = anc[u][b];
			v = anc[v][b];
		}
	}
	if (u != v) {
		ret = max (ret, sparse[u][0]);
		ret = max (ret, sparse[v][0]);
		u = anc[u][0];
		v = anc[v][0];
		assert (u == v);
	}
	
	return ret;
}

// ===================================================== //

int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		st.insert ({w, {u, v}});
	}
	
	kruskal ();
	dfs ();
	buildSparse ();
	
	int q;
	scanf ("%d", &q);
	while (q--) {
		int u, v;
		scanf ("%d %d", &u, &v);
		int ans;
		if (u == v) ans = 0;
		else ans = lca (u, v);
		printf ("%d\n", ans);
	}

	return 0;
}
