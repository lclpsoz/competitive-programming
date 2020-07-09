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

const int INF = 1E9 + 10;
const int N = 404, Q = 1e5 + 100;

int n, r, q;
int cold[N][N], hot[N][N];
vector<pii> allTemps;
int tempIdx[N], temp[N], ans[Q];

int main () {
	memset (ans, -1, sizeof ans);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
				cold[i][j] = hot[i][j] = INF;
	scanf ("%d %d ", &n, &r);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf (" %d", &x);
		temp[i] = x;
		allTemps.push_back ({x, i});
	}
	sort (allTemps.begin(), allTemps.end());
	vector<int> comp;
	for (pii p : allTemps)
		comp.push_back (p.x);
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

	while (r--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		cold[v][u] = w;
		cold[u][v] = w;
		hot[u][v] = w;
		hot[v][u] = w;
	}


	vector<pair<pii, pii>> qCold, qHot;
	scanf ("%d", &q);
	for (int i = 1; i <= q; i++) {
		int u, v, k, t;
		scanf ("%d %d %d %d", &u, &v, &k, &t);
		if (t==0) {
			--k;
			int tmp = comp[min (len (comp)-1, k)];
			int idx = (upper_bound (allTemps.begin(), allTemps.end(), make_pair (tmp, 1010)) - allTemps.begin());
			qCold.push_back ({{i,  idx}, {u, v}});
		} else {
			int tmp = comp[max (0, len(comp)-k)];
			int idx = (lower_bound (allTemps.begin(), allTemps.end(), make_pair (tmp, 0)) - allTemps.begin()) + 1;
			qHot.push_back ({{i,  idx}, {u, v}});
		}
	}
	sort (qCold.begin(), qCold.end(), [&](auto &a, auto &b) {
		return a.x.y > b.x.y;
	});
	sort (qHot.begin(), qHot.end(), [&](auto &a, auto &b) {
		return a.x.y < b.x.y;
	});

	for (int k = 1; k <= n; k++) {
		int v = allTemps[k-1].y;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cold[i][j] = min (cold[i][j], cold[i][v] + cold[v][j]);
		while (!qCold.empty() and qCold.back().x.y == k) {
			int x, y;
			x = qCold.back().y.x;
			y = qCold.back().y.y;
			ans[qCold.back().x.x] = cold[x][y] == INF ? -1 : cold[x][y];
			qCold.pop_back();
		}
	}

	for (int k = n; k >= 1; k--) {
		int v = allTemps[k-1].y;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				hot[i][j] = min (hot[i][j], hot[i][v] + hot[v][j]);
		while (!qHot.empty() and qHot.back().x.y == k) {
			int x, y;
			x = qHot.back().y.x;
			y = qHot.back().y.y;
			ans[qHot.back().x.x] = hot[x][y] == INF ? -1 : hot[x][y];
			qHot.pop_back();
		}
	}
	for (int i = 1; i <= q; i++)
		printf ("%d\n", ans[i]);

	return 0;
}
