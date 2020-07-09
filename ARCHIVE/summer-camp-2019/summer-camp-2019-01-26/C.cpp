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

// Maximum Depth of 1!!!

int n, m;
int size[N], link[N], info[N];
vector<int> comp[N];

pii find (int a) {
    if (link[a] != a) {
        pii p = find (link[a]);
        link[a] = p.x;
        info[a] += p.y;
    }
    return {link[a], info[a]};
}

void unite (int a, int b, int w) {
    pii pA = find (a);
    pii pB = find (b);
    a = pA.x;
    w -= pA.y;
    b = pB.x;
    w += pB.y;
    
//     if (a != link[a]) {
//         w -= info[a];
//         a = link[a];
//     }
//     if (b != link[b]) {
//         w += info[b];
//         b = link[b];
//     }
    if (size[a] > size[b]) {
        swap (a, b);
        w = -w;
    }
    size[b] += size[a];
    link[a] = b;
    info[a] += w;
}

void qry (int a, int b) {
    find (a);
    find (b);
    if (link[a] != link[b])
        printf ("UNKNOWN\n");
    else {
        if (b == link[b])
            printf ("%d\n", info[a]);
        else if (a == link[a])
            printf ("%d\n", -info[b]);
        else
            printf ("%d\n", info[a] - info[b]);
    }
}

int main () {
    while (scanf ("%d %d", &n, &m), n) {
        for (int i = 1; i <= n; i++) {
            size[i] = 1;
            link[i] = i;
            info[i] = 0;
        }
        
        while (m--) {
            char c;
            int a, b, w;
            scanf (" %c %d %d", &c, &a, &b);
            if (c == '!') {
                scanf ("%d", &w);
                unite (a, b, w);
            } else
                qry (a, b);
        }
    }
    
    return 0;
}
