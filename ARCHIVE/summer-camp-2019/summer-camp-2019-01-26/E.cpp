#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 3;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m) % m);
}



// ------------------------------------------------------------

const int N = 5e4+10;

int t, n, k;
int link[N], size[N], edge[N];

pii find (int x) {
	if (link[x] != x) {
		pii p = find (link[x]);
		link[x] = p.x;
		edge[x] = mod (edge[x] + p.y);
	}
	
	return {link[x], edge[x]};
}

void unite (int x, int y, int w) {
	--w;
	pii p1 = find (x);
	pii p2 = find (y);
	w -= edge[x];
	w += edge[y];
	x = p1.x;
	y = p2.x;
	w = mod (w);
	if (size[x] > size[y]) {
		w = mod(-w);
		swap (x, y);
	}
	size[y] += size[x];
	size[x] = 0;
	link[x] = y;
	edge[x] = w; // ?
}

bool upd (int x, int y, int opt) {
	find (x);
	find (y);
	if (link[x] != link[y]) {
		unite (x, y, opt);
		return true;
	}
	int v = mod (edge[x] - edge[y]);
	if ((v == 2) or
		(v == 0 and opt == 2) or
		(v == 1 and opt == 1))
		return false;
	return true;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		int ans = 0;
		scanf ("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
			link[i] = i, size[i] = 1, edge[i] = 0;
		while (k--) {
			int opt;
			ll x, y;
			scanf ("%d %lld %lld", &opt, &x, &y);
// 			printf ("k: %d |", k);
// 			for (int i = 1; i<=5; i++)
// 				printf ("(%d,%d)%c", edge[i], link[i], ",\n"[i==5]);
 			assert (x >= 1 and y >= 1);
			if (x > n or y > n or (opt == 2 and x == y) or !upd (x, y, opt)) {
// 	 				printf ("%d %d %d\n", opt, x, y);
				++ans;
			}
		}
		printf ("%d\n", ans);
	}
    
    return 0;
}
