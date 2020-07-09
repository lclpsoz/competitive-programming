#include "stdio.h"
#include "assert.h"
#include "string.h"
using namespace std;

const int N = 110;

int t, n;
int bit[N], arr[N];

bitset<N> dp[N];

int sum (int p) {
    int r = 0;
    for (;p >= 1; p-= p&-p)
        r += bit[p];
    
    return r;
}

void add (int p, int v) {
    for (; p < N; p+=p&-p)
        bit[p] += v;
}

long double max (long double x, long double y) {
    if (x > y) return x;
    return y;
}

int main () {
    scanf ("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf ("%d", &arr[i]);
        
//         int test = 0;
//         for (int i = n; i >= 1; i--) {
//             test += sum (arr[i]);
//             add (arr[i], 1);
//             printf ("%d: %d\n", i, test);
//         }
        
        long double ans = 0;
        for (int i = n; i >= 1; i--) {
            memset (bit, 0, sizeof bit);
            int acu = 0;
            for (int k = i; k >= 1; k--) {
                acu += sum (arr[k]);
                add (arr[k], 1);
                printf ("(%d, %d): %d\n", k, i, acu);
                ans = max (ans, (long double)acu / (i-k+1));
            }
        }
        printf ("Case #%d: %.12Lf\n", caso, ans);
    }

	return 0;
}
