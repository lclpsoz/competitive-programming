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

const int INF = 2e9+10;
const int K = 505, N = 1e5+10;

int n, m, c;
int vertType[N];
// vector<int> vertsPerType[K];
vector<pii> adj[N], adjDij[N];
set<pii> st;
int dist[N];
int ans[K][K];
int qntType[N], oneType[N];
bool vis[N];
int minDist[N];
int distAux[K][K];

int dfs (int v, int ty) {
    if (vis[v]) return 0;
    vis[v] = true;
    int ret = (vertType[v] == ty);
    for (pii p : adj[v])
        if (p.y == 0)
            ret += dfs (p.x, ty);
        
    return ret;
}

void dijkstra (int stType) {
	memset (vis, 0, sizeof vis);
	for (int i = 1; i <= c; i++) dist[i] = INF;
	st.insert ({0, stType});
	dist[stType] = 0;
    
    while (!st.empty()) {
        int v = st.begin()->y;
        int w = st.begin()->x;
        st.erase (st.begin());
// 		printf ("%d %d\n", v, w);
        if (w > dist[v]) continue;
        for (pii p : adjDij[v]) {
            int u = p.x;
            int wNow = p.y;
            if (dist[u] > wNow + dist[v]) {
                dist[u] = wNow + dist[v];
                st.insert ({dist[u], u});
            }
        }
    }
    
    
    for (int i = 1; i <= c; i++)
        ans[stType][i] = ans[i][stType] = min (ans[i][stType], dist[i]);
}

int main () {
    scanf ("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= c; j++)
            distAux[i][j] = ans[i][j] = INF;
    
    int pp = 1;
    for (int i = 1; i <= c; i++) {
        int now;
         scanf ("%d", &now);
//         printf ("    %d\n", now);
        for (int j = 0; j < now; pp++, j++) {
//              printf ("%d %d\n", i, pp);
            qntType[i]++;
            vertType[pp] = i;
            oneType[i] = pp;
//             vertsPerType[c].push_back (pp);
        }
    }
//     for (int i = 1; i <= n; i++)
//         printf ("%d: %d\n", i, vertType[i]);
    
    while (m--) {
        int u, v, w;
        scanf ("%d %d %d", &u, &v, &w);
        adj[u].push_back ({v, w});
        adj[v].push_back ({u, w});
    }
    
    for (int i = 1; i <= c; i++) {
        memset (vis, 0, sizeof vis);
        if (dfs (oneType[i], i) < qntType[i]) {
//             printf (":: %d %d\n", i, qntType[i]);
            printf ("No\n");
            return 0;
        }
    }
    
	for (int i = 1; i <= n; i++)
		for (pii p : adj[i]) {
			int u = vertType[i];
			int v = vertType[p.x];
			int w = p.y;
			distAux[u][v] = distAux[v][u] = min (distAux[u][v], w);
		}
	
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= c; j++) {
			if (distAux[i][j] < INF and i != j) {
				adjDij[i].push_back ({j, distAux[i][j]});
				adjDij[j].push_back ({i, distAux[i][j]});
			}
// 			printf ("|	%d %d %d\n", i, j, distAux[i][j]);
		}
			
    for (int i = 1; i <= c; i++)
        dijkstra (i);
    printf ("Yes\n");
    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= c; j++)
            printf ("%d%c", ans[i][j] == INF ? -1 : ans[i][j], " \n"[j==c]);

	return 0;
}
