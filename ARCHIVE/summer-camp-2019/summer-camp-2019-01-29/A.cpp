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

const int N = 110;

int n, m;
int size[N], link[N];
set<int> comp[N];
int mat[N][N];
vector<int> lang[N];
vector<int> vert[N];
int ans;

int find (int a) {
    return link[a] == a ? a : link[a] = find (link[a]);
}

bool same (int a, int b) { return find (a) == find (b); }

void unite (int a, int b) {
    a = find (a);
    b = find (b);
    if (size[a] > size[b]) swap (a, b);
    size[b] += size[a];
    link[a] = b;
    for (int x : comp[a])
        comp[b].insert (x);
    comp[a].clear();
}

void func (int a, int b, bool novo) {
    if (!same (a, b)) {
        a = find (a), b = find (b);
        for (int v : comp[a])
            if (comp[b].count (v)) {
                unite (a, b);
                return;
            }
        if (novo) {
            if (comp[a].size() == 0 and comp[b].size() == 0) {
                ans += 2;
                unite (a, b);
                a = find (a);
                comp[a].insert (1);
            } else {
                ++ans;
                unite (a, b);
            }
        }
    }
}

int main () {
    scanf ("%d %d", &n, &m);
    int st = 1;
    for (int i = 1; i <= n; i++)
        size[i] = 1, link[i] = i;
    for (int i = 1; i <= n; i++) {
        int k;
        scanf ("%d", &k);
        if (k)
            st = i;
        for (int j = 1; j <= k; j++) {
            int l;
            scanf ("%d", &l);
            comp[i].insert (l);
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!same (i, j))
                func (i, j, false);
            
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!same (i, j))
                func (i, j, true);
    
    
    printf ("%d\n", ans);
    
    
	return 0;
}
