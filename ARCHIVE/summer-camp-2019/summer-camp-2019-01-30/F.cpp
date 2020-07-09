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

using pp = pair<ll, int>;
const int N = 1005;

int n, m;
pair<ll, int> dp[N][N];
char name[15], os[15];
int vals[2][N];
int typ[2][N];
map<string, int> mp;
int id = 1;
int ans;

pp solve (int x, int y) {
    if (x == n or y == m)
        return {0, 0};
    
    pp &ret = dp[x][y];
    if (ret.x != -1) return ret;
    ret = {-1000000000, -10000000};
    if (typ[0][x] == typ[1][y]) {
//         printf ("here\n");
//         pp mx = max (solve (x, y+1), solve (x+1, y));
//         ret = {mx.x + vals[0][x] + vals[1][y], mx.y - 1};
        pp mx = solve (x+1, y+1);
        mx.x += vals[0][x] + vals[1][y];
        mx.y--;
        ret = mx;
    } else
        ret = solve (x+1, y+1);
    ret = max (ret, solve (x+1, y));
    ret = max (ret, solve (x, y+1));
//     printf ("%d (%d | %d) %d (%d | %d) %d\n", x, vals[0][x], typ[0][x], y, vals[1][y], typ[1][y], ret);
    return ret;
}

// void recu (int x, int y) {
// //     printf ("%d %d\n", x, y);
//     if (x == n or y == m)
//         return;
//     
//     ll &ret = dp[x][y];
// //     if (ret != -1) return ret;
// //     ret = -1000000000;
// //     printf ("%d %d\n", ret, (solve[x+1][y+1] + vals[0][x] + vals[1][y]));
//     if (typ[0][x] == typ[1][y] and ret == (max (solve (x, y+1), solve (x+1, y)) + vals[0][x] + vals[1][y])) {
//         ++ans;
//         if (solve (x, y+1) > solve (x+1, y))
//             recu (x, y+1);
//         else
//             recu (x+1, y);
//     }
//     else if (ret == solve (x+1, y+1))
//         recu (x+1, y+1);
//     else if (ret == solve (x+1, y))
//         recu (x+1, y);
//     else if (ret == solve (x, y+1))
//         recu (x, y+1);
// //     printf ("%d (%d | %d) %d (%d | %d) %d\n", x, vals[0][x], typ[0][x], y, vals[1][y], typ[1][y], ret);
// //     return ret;
// }

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        id = 1;
        mp.clear();
        ans = 0;
        memset (dp, -1, sizeof dp);
        
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            int val;
            scanf ("%s %s %d", name, os, &val);
            int &r = mp[os];
            if (!r) r = id++;
            typ[0][i] = r;
            vals[0][i] = val;
        }
        scanf ("%d", &m);
        for (int i = 0; i < m; i++) {
            int val;
            scanf ("%s %s %d", name, os, &val);
            int &r = mp[os];
            if (r == 0) r = id++;
            typ[1][i] = r;
            vals[1][i] = val;
        }
        
        printf ("%lld %d\n", solve (0, 0).x, -solve (0, 0).y);
//         recu(0, 0);
//         printf (" %d\n", ans);
    }

	return 0;
}
