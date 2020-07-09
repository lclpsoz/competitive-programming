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

const int INF = 1e9 + 100;
const int N = 2e4 + 10;

int n, m;
int js, jg, rs, rg;
vector<pii> adjDir[N], adjInv[N];
set<pii> st;
int distJ[2][N], distR[2][N];
bool ok[N];

int dij (int *dist, int start, int goal, vector<pii> *adj) {
	for (int i = 1; i <= n; i++) dist[i] = INF, ok[i] = false;
	st.insert ({0, start});
	while (!st.empty()) {
		int v = st.begin()->y, d = st.begin()->x;
		// printf ("v = %d\n", v);
		st.erase (st.begin());
		if (ok[v]) continue;
		ok[v] = true;
		dist[v] = d;
		for (auto pp : adj[v]) {
			int u = pp.x, w = pp.y;
			// printf ("u = %d, w = %d\n", u, w);
			if (dist[u] > dist[v] + w) {
				dist[u] = dist[v] + w;
				st.insert ({dist[u], u});
			}
		}
	}

	// for (int i = 1; i <= n; i++)
	// 	printf ("from %d to %d: %d\n", start, i, dist[i]);
	// printf ("OUT!\n");
	return dist[goal];
}

int main () {
	memset (distJ, -1, sizeof distJ);
	memset (distR, -1, sizeof distR);
	scanf ("%d %d", &n, &m);
	scanf ("%d %d %d %d", &js, &jg, &rs, &rg);
	while (m--) {
		int u, v, d;
		scanf ("%d %d %d", &u, &v, &d);
		// printf ("(%d, %d) w = %d\n", u, v, d);
		adjDir[u].push_back ({v, d});
		adjInv[v].push_back ({u, d});
	}

	int mnJ = dij (distJ[0], js, jg, adjDir);
	dij (distJ[1], jg, js, adjInv);
	int mnR = dij (distR[0], rs, rg, adjDir);
	dij (distR[1], rg, rs, adjInv);
	int mn = INF;
	
	for (int i = 1; i <= n; i++)
		if (distJ[0][i] == distR[0][i] and
		distJ[0][i]+distJ[1][i] == mnJ and
		distR[0][i]+distR[1][i] == mnR)
			mn = min (mn, distJ[0][i]);

	if (mn == INF)
		printf ("-1\n");
	else
		printf ("%d\n", mn);

	return 0;
}
