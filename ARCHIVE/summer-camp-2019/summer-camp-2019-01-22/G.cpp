#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1010;

int n;
bool vis[N][N];
ll pd[N][N];
int mat[N][N];

ll solve (int lin, int col) {
    if (lin == 0 || col > lin || col == 0)
        return 0;
    ll &ret = pd[lin][col];
    if (vis[lin][col]) return ret;
    vis[lin][col] = true;
    
    ret = max (0ll, mat[lin][col] + solve (lin-1, col-1) + solve (lin+1, col));
    printf ("%d %d %lld\n", lin, col, ret);
    return ret;
}

int main()
{
    while (scanf ("%d", &n), n) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                scanf ("%d", &mat[i][j]);
        for (int i = 1; i <= n; i++)
            solve (
        memset (vis, 0, sizeof vis);
        memset (pd, 0, sizeof pd);
    }

    return 0;
}
