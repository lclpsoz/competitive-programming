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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m) % m);
}



// ------------------------------------------------------------

const int N = 1010;

int n, m;
vector<pair<int, pii>> adj[N];
set<pair<ld, int>> st;
ld dist[N];

ld dijkstra (ld t) {
//     printf ("t:: %Lf\n", t);
    for (int i = 1; i <= n; i++)
        dist[i] = 1e18;
    st.insert ({0, 1});
    dist[1] = 0;
    while (!st.empty() and st.begin()->y != n) {
        int v = st.begin()->y;
        ld tNow = st.begin()->x;
//         printf ("%d: %Lf\n", v,     tNow);
        st.erase (st.begin());
        if (cmp (tNow, dist[v]) == 1) continue;
        for (auto p : adj[v]) {
            int u = p.x;
            int a, b;
            a = p.y.x;
            b = p.y.y;
            ld now = tNow + a*t + b;
//              printf ("Vertice %d\n", u);
//              printf ("tNow = %Lf, a = %d, b = %d, calc = %Lf\n", tNow, a, b, tNow + a*t + b);
            if (now < dist[u]) {
                dist[u] = now;
                st.insert ({tNow + a*t + b, u});
            }
        }
    }
    ld ret = st.begin()->x;
    st.clear();
    
    return ret;
}

int main () {
    while (scanf ("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        while (m--) {
            int x, y, a, b;
            scanf ("%d %d %d %d", &x, &y, &a, &b);
            adj[x].push_back ({y, {a, b}});
            adj[y].push_back ({x, {a, b}});
        }
        
//         for (ld t = 0; t <= 1440; t+=10)
//             printf ("%Lf: %Lf\n", t, dijkstra (t));
        ld l, r;
        l = 0, r = 1440;
        int cnt = 0;
        while (cnt++ < 250) {
            ld a = (2*l + r)/3;
            ld b = (l + 2*r)/3;
            ld vA = dijkstra (a);
            ld vB = dijkstra (b);
            if (cmp (vA, vB) == -1)
                l = a;
            else
                r = b;
        }
        
        printf ("%0.5Lf\n", dijkstra (l));
    }
    return 0;
}
