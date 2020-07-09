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

const int N = 1e5+10;

int n, s;
vector<int> adj[N];

int main () {
	scanf ("%d %d", &n, &s);
	for (int i = 0; i < n-1; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}
	int qnt = 0;
	for (int i = 1; i <= n; i++)
		qnt += len (adj[i]) == 1;
	
	printf ("%.15Lf\n", 2*((ld)s/qnt));
	
	return 0;
}
