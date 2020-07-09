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

int n, m;
bool vert[N], vis[N];
vector<int> adj[N];

pii dfs (int v) {
	if (vis[v]) return {0, 0};
	vis[v] = true;
	pii ret = {(vert[v] == 0), (vert[v] == 1)};
	for (int u : adj[v]) {
		pii now = dfs (u);
		ret.x += now.x;
		ret.y += now.y;
	}
	
	return ret;
}

int main () {
	while (scanf ("%d %d", &n, &m) != EOF) {
		
		for (int i = 1; i <= n; i++) {
			char c;
			scanf (" %c", &c);
			vert[i] = (c == 'B');
			vis[i] = false;
			adj[i].clear();
		}
		while (m--) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].push_back (v);
			adj[v].push_back (u);
		}
		
		pii ans = {1, 1};
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				pii now = dfs (i);
				if (now.x + now.y > 1) {
					if (now.x&1) ans.x = false;
					if (now.y&1) ans.y = false;
				} else if (now.y == 1)
					ans.y = false;
			}
		printf ("%c\n", (ans.y) ? 'Y' : 'N');
	}

	return 0;
}
