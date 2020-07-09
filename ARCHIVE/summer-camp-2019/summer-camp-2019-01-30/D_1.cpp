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

const int INF = 1e9+10, MSK = (1<<14) + 10;
const int N = 105;
int t;
int n, m, home, z, total;
int pd[15][MSK];
int dist[N][N], distPD[15][15];

void floyd () {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = dist[j][i] = 
                    min (dist[i][j], dist[i][k] + dist[k][j]);
}

void floydPD () {
    for (int k = 1; k <= total; k++)
        for (int i = 1; i <= total; i++)
            for (int j = 1; j <= total; j++)
                distPD[i][j] = distPD[j][i] = 
                    min (distPD[i][j], distPD[i][k] + distPD[k][j]);
}

int solve (int v, int msk) {
//     bitset<6> bb1(msk);
//     cout << "st: " << v << ' ' << bb1 << '\n';
    if ((msk+1) == (1<<(total+1)))
        return distPD[v][0];
    
    int &ret = pd[v][msk];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i <= total; i++)
        if (!((1<<i) & msk))
            ret = min (ret, solve (i, msk | (1<<i)) + distPD[v][i]);
//     bitset<6> bb(msk);
//     cout << v << ' ' << bb << ' ' << ret << '\n';
    return ret;
}


int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d %d", &n, &m, &home);
        
        total = 0;
        memset (pd, -1, sizeof pd);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = i == j ? 0 : INF;
        
        while (m--) {
            int x, y, d;
            scanf ("%d %d %d", &x, &y, &d);
            dist[x][y] = dist[y][d] = min (dist[x][y], d);
        }
        
        floyd();
        
        vector<pair<pii, int>> vec;
        vec.push_back ({{home, home}, 0});
        scanf ("%d", &z);
        for (int i = 1; i <= z; i++) {
            int x, y, b;
            scanf ("%d %d %d", &x, &y, &b);
            total += b;
            while (b--) {
                int pos = 0;
    //             printf ("%d -> %d %d\n", x, y, wNow);
                for (auto p : vec) {
                    int u, v, w;
                    u = p.x.x, v = p.x.y, w = p.y;
//                     printf ("pos=%d, (%d, %d) -> (%d, %d)\n", pos, x, y, u, v);
                    distPD[pos][len (vec)] = w + dist[v][x];
                    distPD[len (vec)][pos++] = dist[x][y] + dist[y][u];
                }
                vec.push_back ({{x, y}, dist[x][y]});
            }
        }
//         for (int i = 1; i <= n; i++)
//             for (int j = 1; j <= n; j++)
//                 printf ("%2d%c", dist[i][j], " \n"[j==n]);
//         for (int i = 0; i <= total; i++)
//             for (int j = 0; j <= total; j++)
//                 printf ("%2d%c", distPD[i][j], " \n"[j==total]);
//         printf ("total: %d\n", total);
        floydPD();
        int ans = INF;
        ans = min (ans, solve (0, 1));
        printf ("%d\n", ans);
        
//         for (int i = 1; i <= z; i++)
//             if (solve (0, 1) + distPD[0][i] == ans) {
//                 printf (" (%d) ", i);
//             }
    }
	return 0;
}
