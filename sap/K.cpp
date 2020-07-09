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

const int N = 1010, FLAG = 1002;

int n;
vector<pair<int, pii>> fj;
vector<pair<ld, pii>> edges;
int sz[N], link[N];
bool vis[N][N];
ld dist[N];
pair<int, ld> adj[N][N];

int find (int a) {
	if (link[a] == a) return a;
	return link[a] = find (link[a]);
}

bool same (int a,  int b) { return find (a) == find (b); }

void unite (int a, int b) {
	a = find (a), b = find (b);
	if (sz[a] > sz[b]) swap (a, b);
	sz[b] += sz[a];
	link[a] = b;
}

ld di (pii x, pii y) {
	ld a = x.x-y.x;
	ld b = x.y-y.y;
	return sqrt (a*a + b*b);
}

int main () {
	scanf ("%d", &n);
	if (n == 0) {
		printf ("0.0\n");
		exit (0);
	}
	for (int i = 0; i < n; i++) {
		dist[i] = 1e18;
		sz[i] = 1;
		link[i] = i;
		int x, y, t;
		scanf ("%d %d %d", &x, &y, &t);
		fj.push_back ({t, {x, y}});
	}
	sort (fj.begin(), fj.end());
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			pii x = fj[i].y, y = fj[j].y;
			int t = abs (fj[i].x - fj[j].x);
			// edges.push_back ({di (x, y)/t, {i, j}});
			adj[i][j] = {i, di(x, y)/t};
		}
	}
	set<pair<ld, pair<int, int>>> st;
	st.insert ({0, {0, FLAG}});
	while (!st.empty()) {
		int v1 = st.begin()->y.x, v2 = st.begin()->y.y;
		if (v1 == n-1 or v2 == n-1) break;
		ld d = st.begin()->x;
		st.erase (st.begin());
		if (vis[v1][v2]) continue;
		vis[v1][v2] = true;

		int u = max (v1, v2)+1; // next
		if (u > FLAG) u = v1+1;
		st.insert ({max (d, adj[v1][u].y), {u, v2}});
		if (v2 == FLAG)
			st.insert ({d, {v1, u}});
		else
			st.insert ({max (d, adj[v2][u].y), {v1, u}});
	}
	printf ("%Lf\n", st.begin()->x);



	// sort (edges.begin(), edges.end());
	// ld lst = 0;
	// ld ans = 0;
	// for (auto e : edges) {
	// 	int u = e.y.x, v = e.y.y;
	// 	ld d = e.x;
	// 	printf ("(%d, %d) %Lf\n", u, v, d);
	// 	if (!same (u, v)) {
	// 		printf ("%Lf\n", ans);
	// 		lst = ans;
	// 		ans = max (ans, d);
	// 		unite (u, v);
	// 	}
	// }
	// printf ("%Lf\n", lst);

	return 0;
}
