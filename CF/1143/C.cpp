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

const int N = 1e5 + 10;

int n;
int c[N], p[N];
vector<int> adj[N];
vector<int> ans;

bool dfs (int v) {
	bool respect = c[v];
	for (int u : adj[v])
		respect = dfs (u) or respect;

	// printf ("%d %d\n", v, respect);
	if (!respect) ans.push_back (v);

	return c[v];
}

int main () {
	scanf ("%d", &n);
	int root = -1;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d %d", &x, &c[i]);
		c[i] = !c[i];
		p[i] = x;
		if (x == -1)
			root = i;
		else
			adj[x].push_back (i);
	}

	dfs (root);
	if (len (ans) == 0) {
		printf ("-1\n");
		exit (0);
	}
	sort (ans.begin(), ans.end());
	for (int x : ans)
		printf ("%d ", x);
	putchar ('\n');

	return 0;
}
