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

const int N = 1e6+10;

int k, l, m;
char dp[N];

char check (int i) {
    if (dp[i-1] == 'B' or (i-k >= 1 and dp[i-k] == 'B') or (i-l >= 1 and dp[i-l] == 'B'))
        return 'A';
    return 'B';
}

int main () {
    scanf ("%d %d %d", &k, &l, &m);
    dp[1] = dp[k] = dp[l] = 'A';
    for (int i = 2; i < N; i++)
        if (dp[i] == '\0')
            dp[i] = check (i);
//     for (int i = 1; i<= 12; i++)
//         printf ("%d: %c\n", i, dp[i]);
    while (m--) {
        int x;
        scanf ("%d", &x);
        printf ("%c", dp[x]);
    }
    putchar ('\n');
    

	return 0;
}
