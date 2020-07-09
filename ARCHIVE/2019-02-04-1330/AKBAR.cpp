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

using pp = pair<pii, pii>;
const int N = 1e6+10;

int t;
int n, r, m;
int vert[N];
vector<int> adj[N];
queue<pp> q;

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &n, &r, &m);
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
			vert[i] = 0;
		}
		while (r--) {
			int a, b;
			scanf ("%d %d", &a, &b);
			adj[a].push_back (b);
			adj[b].push_back (a);
		}
		for (int i = 1; i <= m; i++) {
			int k, s;
			scanf ("%d %d", &k, &s);
			q.push ({{k, i}, {0, s}});
		}
		bool ans = true;
		while (!q.empty()) {
			int v = q.front().x.x, id = q.front().x.y, d = q.front().y.x, s = q.front().y.y;
			q.pop();
			if (vert[v]) {
				if (vert[v] == id) continue;
				ans = false;
				break;
			}
			vert[v] = id;
			if (d < s)
				for (int u : adj[v])
					q.push ({{u, id},{d+1, s}});
		}
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++)
			if (!vert[i]) {
				ans = false;
				break;
			}
		printf ("%s\n", ans ? "Yes" : "No");
	}

	return 0;
}
