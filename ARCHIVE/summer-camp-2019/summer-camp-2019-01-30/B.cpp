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

int n, m;
int a[110], b[110], d[110];
vector<int> adj[110];
int ans[110][110];

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &b[i]);
        d[i] = a[i] - b[i];
    }
    while (m--) {
        int x, y;
        scanf ("%d %d", &x, &y);
        printf ("%d %d\n", x, y);
        --x; --y;
        adj[x].push_back (y);
        adj[y].push_back (x);
    }
    
    for (int i = 0; i < 1e4+10; i++) {
        int v, mini, ch;
        mini = 1000000;
        for (int j = 0; j < n; j++)
            if (d[j] < 0) {
                printf ("j: %d\n", j);
                int acu = 0, here = -1;
                for (int u : adj[j]) {
                    printf ("%d: %d\n", j, u);
                    if (a[u] > 0) {
                        printf ("HERE\n");
                        acu += d[u];
                        here = u;
                    }
                }
                if (acu < mini) {
                    mini = acu;
                    v = j;
                    ch = here;
                }
            }
        for (int i = 0; i < n; i++)
            printf ("%d ", d[i]);
        putchar ('\n');
        if (mini == 0 or mini == -1) {
            printf ("NO\n");
            exit (0);
        }
        d[v]++;
        d[ch]--;
        a[ch]--;
        ans[ch][v]++;
    }
    
    printf ("YES\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf ("%d%c", ans[i][j], " \n"[j==n-1]);

	return 0;
}
