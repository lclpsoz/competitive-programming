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

const int N = 2e5 + 10;

int t;
int n, m;
int color[N];
vector<int> now;
vector<int> adj[N];

void dfs (int v, int c) {
	if (color[v] != -1) return;
	color[v] = c;
	now.push_back (v);
	for (int u : adj[v])
		dfs (u, !c);
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			adj[i].clear(), color[i] = -1;
		while (m--) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].push_back (v);
			adj[v].push_back (u);
		}
		for (int i = 1; i <= n; i++)
			if (color[i] == -1) {
				now.clear();
				int qnt = 0;
				dfs (i, 1);
				for (int v : now) {
					qnt += color[v];
					// printf ("%d: %d\n", i, v);
				}
				// printf ("%d %d\n", len(now), qnt);
				if (len(now) > 1 and qnt > len (now)/2)
					for (int &v : now)
						color[v] = !color[v];
			}
		now.clear();
		for (int i = 1; i <= n; i++)
			if (color[i]) now.push_back (i);
		assert (len (now) <= n/2);
		printf ("%d\n", len (now));
		for (int i = 0; i < len (now); i++)
			printf ("%d%c", now[i], " \n"[i==len(now)-1]);
	}

	return 0;
}
