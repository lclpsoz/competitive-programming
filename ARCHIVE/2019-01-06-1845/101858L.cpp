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

const int INF = 1e9;
const int N = 1e5+100;

int n, l;
vector<pii> points[N];
vector<int> adj[N];
int dist[N];

void makeGraph () {
	for (int i = 0; i < l; i++)
		for (pii p : points[i]) {
			for (int j = 1; j < 6; j++) {
				auto lb = lower_bound (points[i+j].begin(), points[i+j].end(), make_pair (p.x-(5-j), 0));
				auto ub = upper_bound (points[i+j].begin(), points[i+j].end(), make_pair (p.x+(5-j), INF));
				for (; lb != ub; lb++)
					adj[p.y].push_back (lb->y);
			}
		}
}

int solve () {
	for (int i = 0; i <= n+1; i++)
		dist[i] = -INF;
	
	dist[n+1] = 0;
	for (int i = l-1; i >= 0; i--) {
		for (pii p : points[i]) {
			int u = p.y;
			int mx = -INF;
			for (int v : adj[u])
				mx = max (mx, dist[v]);
			dist[u] = mx+1;
		}
	}
	
	return dist[0]-1;
}

int main () {
	scanf ("%d %d", &n, &l);
	points[0].push_back ({0, 0}); 		// Start
	points[l].push_back ({0, n+1});		// End
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		points[x].push_back ({y, i});
	}
	
	for (int i = 1; i < l; i++)
		sort (points[i].begin(), points[i].end());
	
	makeGraph();
	printf ("%d\n", solve ());

	return 0;
}
