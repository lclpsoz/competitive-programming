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
const int N = 1e5+10;

int n, m;
vector<pp> adj[N];
int edge[N], verts[N];
char vis[N];
vector<int> ans, topo;

bool eval (int now, int v) {
	if (vis[v] == 'G') return false;
	if (vis[v] == 'B') return true;
	vis[v] = 'G';
	for (auto &p : adj[v]) {
		int u = p.x, w = edge[p.y.x];
		bool inverted = p.y.y;
		if (w > now and !inverted)
			if (!eval (now, u))
				return false;
	}
	vis[v] = 'B';
	
	return true;
}

bool eval (int now) {
	for (int i = 1; i <= n; i++)
		vis[i] = 'W';
// 	printf ("____ %d _____\n", now);
	for (int i = 1; i <= n; i++) {
// 		if (!vis[i]) printf ("now: %d | i: %d\n", now, i);
		if (vis[i] == 'W' and !eval (now, i))
			return false;
	}
	return true;
}

void dag (int v, int now) {
	if (vis[v] == 'B') return;
	vis[v] = 'B';
	for (auto &p : adj[v]) {
		int u = p.x, w = edge[p.y.x];
		bool inverted = p.y.y;
		if (inverted and w > now)
			dag (u, now);
	}
	
	topo.push_back (v);
}

int main () {
	scanf ("%d %d", &n, &m);
	int edgeId = 1;
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		edge[edgeId] = w;
		adj[u].push_back ({v, {edgeId, false}});
		adj[v].push_back ({u, {edgeId++, true}}); // Inverted
	}
	
	int l = 0, r = 1e9;
	while (l < r) {
		int md = (l+r)/2;
		if (eval (md))
			r = md;
		else
			l = md+1;
	}
	
	for (int i = 1; i <= n; i++)
		vis[i] = 'W';
	for (int v = 1; v <= n; v++)
		if (vis[v] == 'W') dag (v, l);
	for (int i = 0; i < len (topo); i++)
		verts[topo[i]] = i+1;
	
	
	
	vector<int> ans;
	for (int v = 1; v <= n; v++)
		for (auto p : adj[v]) {
			int u = p.x, w = edge[p.y.x];
			bool inverted = p.y.y;
			if (w <= l and !inverted and verts[v] > verts[u])
				ans.push_back (p.y.x);
		}
			
	printf ("%d %d\n", l, len (ans));
	for (int i = 0; i < len (ans); i++)
		printf ("%d%c", ans[i], " \n"[i == len(ans)-1]);

	return 0;
}
