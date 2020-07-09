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

using piii = pair<int, pii>;
const int N = 500;


int n;
int mat[N][N];
int link[N], sz[N];
set<piii> st, aft;

int find (int a) {
    return a == link[a] ? a : link[a] = find (link[a]);
}

bool same (int a, int b) {
    return find (a) == find (b);
}

void unite (int a, int b) {
    a = find (a), b = find (b);
    if (sz[a] > sz[b]) swap (a, b);
    sz[b] += sz[a];
    link[a] = b;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        sz[i] = 1, link[i] = i;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &mat[i][j]);
    
    int ans = 0, sumMaxST = 0, sumAll = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
            if (mat[i][j]) {
                if (!same (i, j))
                    unite (i, j);
                aft.insert ({-mat[j][i], {i, j}});
                sumAll += mat[j][i];
            }
            else
                st.insert ({mat[j][i], {i, j}});
        }
    
    while (!st.empty()) {
        int w = st.begin()->x;
        int u = st.begin()->y.x, v = st.begin()->y.y;
        st.erase (st.begin());
        if (!same (u, v)) {
            unite (u, v);
            ans += w;
            sumAll += w;
            aft.insert ({-w, {u, v}});
        }
    }
    
    for (int i = 0; i < n; i++)
        sz[i] = 1, link[i] = i;
    while (!aft.empty()) {
        int w = -aft.begin()->x;
        int u = aft.begin()->y.x, v = aft.begin()->y.y;
        aft.erase (aft.begin());
        if (!same (u, v)) {
            unite (u, v);
            sumMaxST += w;
        }
    }
    
    ans += sumAll - sumMaxST;
    printf ("%d\n", ans);

	return 0;
}
