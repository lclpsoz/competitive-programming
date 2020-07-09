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

const int FLAG = - 1e9;
const int N = 1e5 + 10;

int n, l, h;
int dp[N][22];
pair<int, bool> a[N];


int main () {
    scanf ("%d %d %d", &n, &l, &h);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &a[i].x);
    for (int i = 1; i <= n; i++) {
        int st;
        scanf ("%d", &st);
        a[i].y = st;
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 22; j++)
            dp[i][j] = FLAG;
    int ans = FLAG;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].y)
            dp[i][0] = 0;
        else
            dp[i][0] = max (0, dp[i-1][0] + a[i].x);
        
        if (a[i].y)
            dp[i][1] = max (a[i].x, dp[i-1][0] + a[i].x);
        else if (dp[i-1][1] != FLAG)
            dp[i][1] = dp[i-1][1] + a[i].x;
        
        for (int j = 2; j < 21; j++) {
            if (a[i].y and dp[i-1][j-1] != FLAG)
                dp[i][j] = dp[i-1][j-1] + a[i].x;
            else if (!a[i].y and dp[i-1][j] != FLAG)
                dp[i][j] = dp[i-1][j] + a[i].x;
        }
    }
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= 8; j++)
//             printf ("dp[%d][%d] = %d\n", i, j, dp[i][j]);
//         putchar ('\n');
//     }
    
    for (int i = 0; i < N; i++)
        for (int j = l; j <= h; j++)
            ans = max (ans, dp[i][j]);
    
    printf ("%d\n", ans);
    

	return 0;
}
