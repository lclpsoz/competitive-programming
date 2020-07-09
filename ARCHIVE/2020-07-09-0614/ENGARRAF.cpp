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

const int INF = 1e9 + 10, N = 105;

int n, m;
vector<pair<int, pii>> edges;
int dist[N];


int main () {
	while (scanf ("%d %d", &n, &m), n or m) {
		edges.clear();
		for (int i = 1; i <= n; i++) dist[i] = INF; 
		while (m--) {
			int u, v, w;
			scanf ("%d %d %d", &u, &v, &w);
			edges.push_back ({w, {u, v}});
			// edges.push_back ({w, {v, u}});
		}
	
		int s, d;
		scanf ("%d %d", &s, &d);
		dist[s] = 0;
		for (int i = 1; i < n; i++)
			for (auto e : edges)
				dist[e.y.y] = min (dist[e.y.y], dist[e.y.x] + e.x);
		printf ("%d\n", dist[d] == INF ? -1 : dist[d]);
	}

	return 0;
}
