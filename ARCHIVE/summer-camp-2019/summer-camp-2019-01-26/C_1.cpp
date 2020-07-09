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

const int N = 1e5+10;

int n, m;
vector<pii> adj[N]; // {VERT, WEIGHT}
queue<pii> q;
bool vis[N];

void qry (int a, int b) {
    memset (vis, 0, sizeof (bool) * (n+2));
    int ret = 1000000000;
    q.push ({a, 0});
    while (!q.empty()) {
        int v = q.front().x;
        int w = q.front().y;
        q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        if (v == b)  {
            ret = w;
            break;
        }
        for (pii p : adj[v])
            q.push ({p.x, p.y + w});
    }
    while (!q.empty())
        q.pop();
    
    if (ret == 1000000000)
        printf ("UNKNOWN\n");
    else
        printf ("%d\n", ret);
}

int main () {
    while (scanf ("%d %d", &n, &m), n) {
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        while (m--) {
            char c;
            int a, b, w;
            scanf (" %c %d %d", &c, &a, &b);
            if (c == '!') {
                scanf ("%d", &w);
                adj[a].push_back ({b, w});
                adj[b].push_back ({a, -w});
            } else
                qry (a, b);
        }
    }
    
    return 0;
}
