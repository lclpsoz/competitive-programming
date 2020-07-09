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

const int N = 2e5 + 100;

int n, m, color[N];
vector<pii> edges;
vector<int> adj[N];

bool dfs (int v, int c) {
    if (color[v] != -1) return color[v] == c;
    color[v] = c;
    for (int u : adj[v])
        if (!dfs (u, !c)) return false;
    return true;
}

int main () {
    scanf ("%d %d", &n, &m);
    while (m--) {
        int x, y;
        scanf ("%d %d", &x, &y);
        edges.push_back ({x, y});
        adj[x].push_back (y);
        adj[y].push_back (x);
    }
    
    memset (color, -1, sizeof color);
    if (!dfs (1, 0))
        printf ("NO\n");
    else {
        for (int i = 1; i <= n; i++)
            assert (color[i] != -1);
        printf ("YES\n");
        for (pii e : edges) {
            if (color[e.x]) putchar ('1');
            else putchar ('0');
        }
        putchar ('\n');
    }

	return 0;
}
