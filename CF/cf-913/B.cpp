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

int n;
vector<int> adj[N];
bool ans = true;

bool solve (int v) {
	if (len (adj[v]) == 0)
		return true;
	
	int r = 0;
	for (int u : adj[v])
		r += solve (u);
	if (r < 3)	ans = false;
// 	printf ("%d %d\n", v, r);
	return false;
}

int main () {
	scanf ("%d", &n);
	for (int i = 2; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		adj[x].push_back (i);
	}
	
	solve (1);
	printf ("%s\n", ans ? "Yes" : "No");
	
	return 0;
}
