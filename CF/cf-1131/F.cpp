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

const int N = 151000;

int n;
int link[N], sz[N];
int root = -1;
bool vis[N];
vector<int> adj[N];
vector<int> ans;

int find (int x) {
	if (x == link[x]) return x;
	return link[x] = find (link[x]);
}

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
	x = find (x);
	y = find (y);
	if (sz[x] > sz[y]) swap (x, y);
	sz[y] += sz[x];
	link[x] = y;
	adj[y].push_back (x);
}

void dfs (int v) {
	if (vis[v]) return;
	ans.push_back (v);
	vis[v] = true;
	for (int u : adj[v])
		dfs (u);
}
int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		sz[i] = 1, link[i] = i;
	--n;
	while (n--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		if (!same (x, y)) unite (x, y);
	}

	dfs (find (1));
	for (int v : ans)
		printf ("%d ", v);
	putchar ('\n');

	return 0;
}
