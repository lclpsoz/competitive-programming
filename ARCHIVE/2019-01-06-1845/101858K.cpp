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

const int INF = 1e9+100;
const int N = 1e5+100;

int n, m;
int dist[N][3];
vector<pair<int, string>> vec;
vector<pii> adj[N];

void dijkstra () {
	for (int i = 1; i <= n; i++)
		dist[i][0] = dist[i][1] = dist[i][2] = INF;
	
	dist[1][0] = 0;
	set<pair<int, pair<int, int>>> st;
	st.insert ({0, {1, 0}});
	while (!st.empty()) {
		int w = st.begin()->x, u = st.begin()->y.x, q = st.begin()->y.y; 
		st.erase (st.begin());
		if (dist[u][q] < w) continue;
		if (u == n) continue;
		int nq = (q+1)%3;
		for (auto p : adj[u]) {
			int v = p.x;
			if (dist[u][q]+p.y < dist[v][nq]) {
				dist[v][nq] = dist[u][q]+p.y;
				st.insert ({dist[v][nq], {v, nq}});
			}
		}
	}
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0 ; i < m; i++) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({v, w});
		adj[v].push_back ({u, w});
	}
	
	dijkstra ();
	vec.push_back ({dist[n][0], "me"});
	vec.push_back ({dist[n][1], "Gon"});
	vec.push_back ({dist[n][2], "Killua"});
	sort (vec.begin(), vec.end());
	for (auto p : vec)
		cout << p.y << '\n';
	
	return 0;
}
