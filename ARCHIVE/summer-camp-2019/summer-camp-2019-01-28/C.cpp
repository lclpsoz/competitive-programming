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

const int N = 2e4 + 10, M = 1e5+10;

int n, m, k;
vector<pair<int, pii>> cobble, concrete;
int link[N], size[N];
set<int> ans;
pair<int, pii> edge[M];

int find (int a) { return link[a] == a ? a : link[a] = find (link[a]); }

bool same (int a, int b) { return find (a) == find (b); }

void unite (int a, int b) {
	if (same (a, b)) return;
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	link[a] = b;
}

void no () {
	printf ("no solution\n");
	exit (0);
}

void yes () {
	for (int e : ans)
		printf ("%d %d %d\n", edge[e].y.x, edge[e].y.y, edge[e].x);
}

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		size[i] = 1, link[i] = i;
	
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		scanf ("%d %d %d", &u, &v, &c);
		edge[i] = {c, {u, v}};
		if (c == 1) {
			if (!same (u, v))
				unite (u, v);
			concrete.push_back ({i, {u, v}});
		} else
			cobble.push_back ({i, {u, v}});
	}
	
	for (auto p : cobble) {
		if (k == 0) break;
		int id = p.x;
		int u = p.y.x;
		int v = p.y.y;
		if (!same (u, v)) {
			unite (u, v);
			ans.insert (id);
			--k;
		}
	}
	
	for (int i = 1; i <= n; i++)
		size[i] = 1, link[i] = i;
	
	for (int e : ans) {
		int u = edge[e].y.x;
		int v = edge[e].y.y;
		unite (u, v);
	}
	
	for (auto p : cobble) {
		if (k == 0) break;
		int id = p.x;
		int u = p.y.x;
		int v = p.y.y;
		if (!same (u, v)) {
			unite (u, v);
			ans.insert (id);
			--k;
		}
	}
	
	if (k > 0)
		no();
	
	for (auto p : concrete) {
		int id = p.x;
		int u = p.y.x;
		int v = p.y.y;
		if (!same (u, v)) {
			unite (u, v);
			ans.insert (id);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		find (i);
// 			printf ("%d: %d\n", i, link[i]);
		if (link[i] != link[1]) {
			no();
		}
	}
	yes();

	return 0;
}
