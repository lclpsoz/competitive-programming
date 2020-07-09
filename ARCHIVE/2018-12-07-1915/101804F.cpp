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

const int N = 1e5+100;

int n, m;
int parent[N];
vector<int> adj[N];
int dp[N][2];

void fParent (int v, int p) {
    parent[v] = p;
    for (int u : adj[v])
        if (u != p)
            fParent (u, v);
}

int solve (int v, bool state) {
    if (len (adj[v]) == 1)
        return state;
    
    int &r = dp[v][state];
    if (r != -1)
        return r;
    r = 0;
    
    if (state) {
        r = 1;
        for (int u : adj[v])
            if (u != parent[v])
                r += solve (u, false);
    }
    int aux = 0;
    for (int u : adj[v])
        if (u != parent[v])
            aux += solve (u, true);
    
    r = max (r, aux);
    return r;
}

int main () {
    memset (dp, -1, sizeof dp);
    scanf ("%d %d", &n, &m);
    while (m--) {
        int v, u;
        scanf ("%d %d", &v, &u);
        adj[v].push_back (u);
        adj[u].push_back (v);
    }
    
    fParent (1, 1);
    printf ("%d\n", solve (1, true));
    
    return 0;
}
