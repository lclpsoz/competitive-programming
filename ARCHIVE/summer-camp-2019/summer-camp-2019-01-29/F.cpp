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

const int MOD = 3;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 5e4+10;

int t, n, k;
int size[N], link[N], edge[N];

pii find (int x) {
    if (x != link[x]) {
        pii p = find (link[x]);
        edge[x] = mod (edge[x] + p.y);
        link[x] = p.x;
    }
    
    return {link[x], edge[x]};
}

bool same (int a, int b) {
    return find (a) == find (b);
}

void unite (int a, int b, int d) {
    find (a);
    find (b);
    if (a != link[a]) {
        d -= edge[a];
        a = link[a];
    }
    if (b != link[b]) {
        d += edge[b];
        b = link[b];
    }
    if (size[a] > size[b]) {
        swap (a, b);
        d = -d;
    }
    size[b] += size[a];
    link[a] = b;
    edge[a] = mod (edge[a] + d);
}

bool update (int a, int b, int d) {
    find (a); find (b);
    d--;
    if (link[a] == link[b]) {
        if (mod (edge[a] - edge[b]) == d)
            return true;
        else
            return false;
    }
    unite (a, b, d);
    return true;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        int ans = 0;
        scanf ("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            edge[i] = 0, size[i] = 1, link[i] = i;
        while (k--) {
            int d, x, y;
            scanf ("%d %d %d", &d, &x, &y);
            if (x > n or y > n or (d == 2 and x == y) or !update (x, y, d))
                ++ans;
//             for (int i = 1; i <= 5; i++)
//                 printf ("%d: %d %d %d\n", i, link[i], size[i], edge[i]);
//             printf ("__________\n");
            
        }
        printf ("%d\n", ans);
    }

	return 0;
}
