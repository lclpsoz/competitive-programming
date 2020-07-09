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

int n, m;
vector<pii> adj[105];
bool verif[105];

int main () {
	while (scanf ("%d %d", &n, &m), n || m) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			verif[i] = false;
		}
		while (m--) {
			int u, v, t;
			scanf ("%d %d %d", &u, &v, &t);
			adj[u].push_back ({v, t});
		}
		int s, d;
		scanf ("%d %d", &s, &d);
		set<pii> st;
		st.insert ({0, s});
		while (!st.empty() and st.begin()->y != d) {
			int v = st.begin()->y, w = st.begin()->x;
			st.erase (st.begin());
			if (verif[v]) continue;
			verif[v] = true;
			for (pii p : adj[v]) {
				int u = p.x, wei = p.y;
				st.insert ({wei+w, u});
			}
		}
		
		if (!st.empty())
			printf ("%d\n", st.begin()->x);
		else
			printf ("-1\n");
	}

	return 0;
}
