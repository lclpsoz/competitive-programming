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

const int N = 1e5 + 10, V = 110;

int n, q;
int link[N], sz[N], bit[V], scores[N], ans[N];
vector<pii> queries[N];
vector<int> verts[N];

int find (int x) { return link[x] == x ? x : link[x] = find (link[x]); }

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
    x = find (x);
    y = find (y);
    if (sz[x] > sz[y]) swap (x, y);
    sz[y] += sz[x];
    link[x] = y;
}

void add (int p, int v) {
    for (; p < V; p+=p&-p)
        bit[p] += v;
}

int sum (int p) {
    int ret = 0;
    for (; p >= 1; p-=p&-p)
        ret += bit[p];
    
    return ret;
}

int main () {
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        link[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; i++) scanf ("%d", &scores[i]);
    
    scanf ("%d", &q);
    while (q--) {
        int a, b;
        scanf ("%d %d", &a, &b);
        if (!same (a, b))
            unite (a, b);
    }
    for (int i = 1; i <= n; i++)
        verts[find(i)].push_back (i);
    
    scanf ("%d", &q);
    int prt = 0;
    while (q--) {
        int opt, w, k;
        scanf ("%d", &opt);
        if (opt == 1) {
            scanf ("%d", &w);
            queries[find(w)].push_back ({-w, prt++});
        } else {
            scanf ("%d %d", &w, &k);
            queries[find(w)].push_back ({w, k});
        }
    }
    
    for (int i = 1; i <= n; i++)
        if (len (queries[i])) {
            memset (bit, 0, sizeof bit);
            for (int v : verts[i]) {
                add (scores[v], 1);
//                 printf ("v(%d): scr = %d\n", v, scores[v]);
            }
//             for (int i = 1; i <= 100; i++)
//                 printf ("%d: %d\n", i, sum (i));
            for (auto p : queries[i])
                if (p.x < 0) {
                    ans[p.y] = sum (scores[-p.x] - 1);
                } else {
                    add (scores[p.x], -1);
                    scores[p.x] = p.y;
                    add (scores[p.x], 1);
                }
        }
        
    for (int i = 0; i < prt; i++)
        printf ("%d\n", ans[i]);

	return 0;
}
