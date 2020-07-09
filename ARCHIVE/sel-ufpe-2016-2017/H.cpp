#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

// ----------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 420;
inline int mod (int x, int m = MOD) {
	return x%m;
}

// ----------------

const int INF = 1e9+10;
const int N = 1e5+10;

int n, m, k;
int valSem[10], s[N];
vector<pii> adj[N];
int dist[N];

int dijkstra (int a, int b) {
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	
	set<pii> st;
	st.insert ({0, a});
	dist[a] = 0;
	while (!st.empty()) {
		int d = st.begin()->x, v = st.begin()->y;
		st.erase (st.begin());
		if (d > dist[v]) continue;
//  		printf ("%d %d %d\n", d, t, v);
		if (v == b) break;
// 		if (t%s[v]) {
// 			int ax = s[v] - t%s[v];
// 			t = mod (t + ax);
// 			d += ax;
// 		}
// 		printf ("t: %d, d: %d\n", t, d);
		for (pii p : adj[v]) {
			int u = p.x, w = p.y;
			int ax = d+w;
			if (u != b and (ax)%s[u])
				ax += (s[u] - (ax)%s[u]);
			if (dist[u] > ax) {
				dist[u] = ax;
				st.insert ({ax, u});
			}
		}
	}
	
	return dist[b];
}

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i= 1; i <= k; i++)
		scanf ("%d", &valSem[i]);
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({v, w});
		adj[v].push_back ({u, w});
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &s[i]);
		s[i] = valSem[s[i]];
	}
	int a, b;
	scanf ("%d %d", &a, &b);
	printf ("%d\n", dijkstra (a, b));
	
	return 0;
}
