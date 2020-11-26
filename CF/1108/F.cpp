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

using pp = pair<int, pii>;

const int N = 2e5+10;

int n, m;
set<pp> st;
int ans;
int link[N], size[N], his[N];
int tempo;

int find (int x, int t) {
	if (link[x] == x) return x;
	if (his[x] > t) return x;
	return find (link[x], t);
}

bool same (int x, int y, int t) {
	return find (x, t) == find (y, t);
}

void unite (int x, int y) {
	tempo++;
	x = find (x, tempo);
	y = find (y, tempo);
	if (size[x] > size[y]) swap (x, y);
	link[x] = y;
	size[y] += size[x];
	his[x] = tempo;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		link[i] = i, size[i] = 1, his[i] = 0;
	while (m--) {
		int x, y, w;
		scanf ("%d %d %d", &x, &y, &w);
		st.insert ({w, {x, y}});
	}
	
	int wNow = -1000;
	int tNow = 0;
	while (!st.empty()) {
		int w = st.begin()->x;
		int u = st.begin()->y.x;
		int v = st.begin()->y.y;
		st.erase (st.begin());
		if (w != wNow) {
			wNow = w;
			tNow = tempo;
		}
		if (!same (u, v, tempo))
			unite (u, v);
		else if (!same (u, v, tNow))
			++ans;
	}
	
	printf ("%d\n", ans);

	return 0;
}
