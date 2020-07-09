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

int n, m;
int link[N], sz[N], jmp[N], merge[N];
vector<int> comps[N];

int find (int x) {
	if (x == link[x]) return x;
	return link[x] = find (link[x]);
}

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
	x = find (x), y = find (y);
	if (sz[x] > sz[y]) swap (x, y);
	link[x] = y;
	sz[y] += sz[x];
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) sz[i] = 1, link[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		if (!same (x, y)) unite (x, y);
	}

	for (int i = 1; i <= n; i++) comps[find (i)].push_back (i), jmp[i] = i+1;

	int ans = 0;
	for (int ii = 1; ii <= n; ii++) {
		int i = find (ii);
		int maxi = comps[i].back();
		for (int j = comps[i].front(); j <= maxi; j=jmp[j]) {
			if (!same (i, j)) {
				++ans;
				maxi = max (maxi, comps[find(j)].back());
				unite (j, i);
				i = find(i);
			}
			if (j > comps[i].front())
				jmp[j-1] = maxi;
		}
	}
	printf ("%d\n", ans);

	return 0;
}
