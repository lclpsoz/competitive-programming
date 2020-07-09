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

using pp = unordered_map<int, pair<int, int>>;

const int N = 1e5+10;

int n, k;
vector<int> children[N];
pii edge[N];
int ans[N];

int find (int a, pp &mp) {
    if (mp.count (a) == 0)
        return a;
    return a == mp[a].x ? a : mp[a].x = find (mp[a].x, mp);
}

bool unite (int a, int b, pp &mp) {
//     printf ("UNITE %d %d\n", a, b);
    a = find (a, mp);
    b = find (b, mp);
    if (a == b) return false;
//     printf ("UNITE %d %d\n", a, b);
    
    pii &p1 = mp[a];
    pii &p2 = mp[b];
    p1.x = a;
    p2.x = b;
    if (p1.y > p2.y)
        swap (p1, p2);
    if (p1.y == 0) p1.y = 1;
    if (p2.y == 0) p2.y = 1;
    p2.y += p1.y;
    p1.x = p2.x;
    
    return true;
}

// Reference, worst case 1e5 maps because 1e5 leafs.
int dfs (int v, pp &now) {
//     printf ("__ %d __\n", v);
//     printf ("%d: %d %d %d\n", v, n, len (now), len (st));
    int &ret = ans[v];
    ret = k;
    if (edge[v].x) {
        unite (edge[v].x, edge[v].y, now);
        --ret;
    }
    for (int u : children[v]) {
        pp mp;
        int val = dfs (u, mp);
        if (len (mp) > len (now)) {
            swap (val, ret);
            swap (mp, now);
        }
        for (auto p : mp)
            if (unite (p.x, p.y.x, now))
                --ret;
    } 
//     printf ("%d: %d %d %d\n", v, k, len (now), len (st));
    ans[v] = ret;
    return ret;
}


int main () {
    scanf ("%d %d", &n, &k);
    for (int i = 2; i <= n; i++) {
        int p;
        scanf ("%d", &p);
        children[p].push_back (i);
    }
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf ("%d %d", &x, &y);
        edge[i] = {x, y};
    }
    pp now;
    dfs (1, now);

    for (int i = 1; i <= n; i++)
        printf ("%d\n", ans[i]);
    
	return 0;
}
