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

const int N = 1e4+10;

int n;
vector<int> adj[N];
bool vis[N];
int maxProf, farVert;

void far (int v, int prof) {
	vis[v] = true;
	if (prof > maxProf) {
		maxProf = prof;
		farVert = v;
	}
	for (int u : adj[v])
		if (!vis[u])
			far (u, prof+1);
}

int main () {
	while (scanf ("%d", &n), n != -1) {
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		for (int i = 2; i <= n; i++) {
			int v;
			scanf ("%d", &v);
			adj[i].push_back (v);
			adj[v].push_back (i);
		}
		memset (vis, false, sizeof vis);
		maxProf = 0, farVert = 1;
		far (1, 1);
		maxProf = 0;
		memset (vis, false, sizeof vis);
		far (farVert, 1);
		printf ("%d\n", maxProf/2);
	}

	return 0;
}
