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

const int N = 3e5+100;

int n, m;
vector<int> adj[N];
vector<pii> vert[N];
ll ans[N];
ll bit[N];
int prof[N];

void add (int p, int v) {
	for (; p < N; p+=p&-p)
		bit[p] += v;
}

ll sum (int p) {
	ll r = 0;
	for (; p >= 1; p-=p&-p)
		r += bit[p];
	return r;
}

// Starts at 1.
void fProf (int v, int p, int pr) {
	prof[v] = pr;
	for (int u : adj[v])
		if (u != p)
			fProf (u, v, pr+1);
	
}

void solve (int v, int p) {
	for (auto pp : vert[v]) {
		add (prof[v], pp.y); // left
		add (prof[v]+pp.x+1, -pp.y); // right
	}
	ans[v] = sum (prof[v]);
	
	for (int u : adj[v])
		if (u != p)
			solve (u, v);

	for (auto pp : vert[v]) {
		add (prof[v], -pp.y); // left
		add (prof[v]+pp.x+1, pp.y); // right
	}
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}
	scanf ("%d", &m);
	while (m--) {
		int v, d, x;
		scanf ("%d %d %d", &v, &d, &x);
		vert[v].push_back ({d, x});
	}

	fProf (1, 1, 1);
	solve (1, 1);
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			putchar (' ');
		printf ("%lld", ans[i]);
	}
	putchar ('\n');
	
	return 0;
}
