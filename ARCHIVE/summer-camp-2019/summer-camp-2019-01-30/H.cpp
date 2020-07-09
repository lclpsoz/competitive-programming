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

using pp = pair<pii, int>;
const int N = 1010;

char mat[N][N];
bool vis[N][N];
int adj[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

pair<pii, int> far (int x, int y, bool aft) {
    if (mat[x][y] != '.')
        return {{x, y} , -1};
    if (vis[x][y])
        return {{x, y}, -1};
    int now = 0;
    pii pos = {x, y};
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        pp p = far (x + adj[i][0], y + adj[i][1], aft);
        p.y++;
        if (p.y > now) {
            now = p.y;
            pos = p.x;
        }
    }
    vis[x][y] = aft;
    
    return {pos, now};
}

int main () {
    int t;
    int n, m;
    scanf ("%d", &t);
    while (t--) {
        memset (mat, '\0', sizeof mat);
        scanf ("%d %d", &n, &m);
        swap (n, m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf (" %c", &mat[i][j]);
            
        memset (vis, 0, sizeof vis);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!vis[i][j] and mat[i][j] == '.') {
                    pp p = far (i, j, false);
                    p = far (p.x.x, p.x.y, true);
//                     printf ("%d %d %d\n", i, j, p.y);
                    ans = max (ans, p.y);
                }
        printf ("Maximum rope length is %d.\n", ans);
    }

	return 0;
}
