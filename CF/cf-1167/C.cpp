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

const int N = 5e5 + 10;

int n, m;
int link[N], sz[N];

int find (int x) {
	if (link[x] == x) return x;
	return link[x] = find (link[x]);
}

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
	x = find (x);
	y = find (y);
	if (sz[x] > sz[y]) swap (x, y);
	sz[y] += sz[x];
	link[x] = y;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) sz[i] = 1, link[i] = i;
	while (m--) {
		int k;
		scanf ("%d", &k);
		int st;
		if (k)
		scanf ("%d", &st);
		--k;
		while (k-- > 0) {
			int x;
			scanf ("%d", &x);
			if (!same (x, st)) unite (x, st);
		}
	}
	for (int i = 1; i <= n; i++)
		printf ("%d ", sz[find(i)]);
	putchar ('\n');

	return 0;
}
